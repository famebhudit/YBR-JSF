#include <Servo.h>
#include "Mapf.h"
#include <PID_v2.h>
Servo myservo;
Servo myservo2;

//Motor
const int E1Pin = 10;
const int M1Pin = 12;
typedef struct {
  byte enPin;
  byte directionPin;
} MotorContrl;
const int M1 = 0;
const int M2 = 1;
const int MotorNum = 1;

const MotorContrl MotorPin[] = { { E1Pin, M1Pin } };

const int Forward = LOW;
const int Backward = HIGH;

//Button
int BUTTON = A6;

//PID
PID_v2 compassPID(0.62, 0.0001, 0.05, PID::Direct);

//Ultra
int const ULTRA_PIN = A9;

//INEX Gyro
float pvYaw, pvRoll, pvPitch;
uint8_t rxCnt = 0, rxBuf[8];

//  Light Sensors
int const RED_SEN = A7;
int const BLUE_SEN = A8;

// Servo
int const STEER_SRV = 16;
int const ULTRA_SRV = 23;

//OpenMV
static String receivedString = "";  // Buffer to store incoming data
int tempXBlob = -1, tempYBlob = -1, tempWidthBlob = -1, tempHeightBlob = -1;
int tempXRedBlob = -1, tempYRedBlob = -1, tempWidthRedBlob = -1, tempHeightRedBlob = -1;

int largestBlobX = 0, largestBlobY = 0, largestBlobWidth = 0, largestBlobHeight = 0;
int largestBlobArea = 0;

bool found_block;
float avoidance_degree = 0;
int missedBlockCount = 0;
const int MAX_MISSED_BLOCKS = 3;
int falseDetectionCount = 0;
const int requiredFalseCount = 3;

//Others
char TURN = 'U';
char last_block = 'U';
char Blocks_TURN = 'U';
char before_last_block = 'U';
long halt_detect_line_timer;
int Line_Number = 0;
int plus_degree = 0;
long MV_timer;
int block_count = 0;
float blockCenterX;
long timer_block_decay;
float found_block_factor;
int signature;
int blockDetectionCounter = 0;
const int detectionThreshold = 3;  // Number of consecutive detections needed
float pidOutput;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  Serial3.begin(19200);

  compassPID.Start(0, 0, 0);
  compassPID.SetOutputLimits(-180, 180);
  compassPID.SetSampleTime(10);

  pinMode(STEER_SRV, OUTPUT);
  pinMode(ULTRA_SRV, OUTPUT);
  pinMode(ULTRA_PIN, INPUT);
  pinMode(RED_SEN, INPUT);
  pinMode(BLUE_SEN, INPUT);
  pinMode(BUTTON, INPUT);

  initMotor();
  while (!Serial)
    ;
  myservo.attach(ULTRA_SRV, 500, 2400);
  myservo2.attach(STEER_SRV, 500, 2500);
  steering_servo(0);
  ultra_servo(0, 'L');
  while (analogRead(BUTTON) > 500)
    ;
  zeroYaw();
}


void loop() {

  while (analogRead(BUTTON) > 500) {
    getIMU();  // Read data from OpenMV
    ultra_servo(pvYaw, Blocks_TURN);
    Color_detection();
    // Additional logic for distance tracking
    float desiredDistance = 32.5;
    if (TURN == 'L') {
      desiredDistance += 5;
    } else if (TURN == 'R') {
      desiredDistance -= 0;
    }
    float distanceError = getDistance() - (desiredDistance);
    float deadband = 2.0;
    if (abs(distanceError) < deadband) {
      distanceError = 0.0;
    }
    float directionFactor = (Blocks_TURN == 'L') ? -1.0 : 1.0;
    float adjustedYaw = pvYaw + (distanceError * directionFactor);
    pidOutput = compassPID.Run(adjustedYaw);
    if (millis() - MV_timer > 20) {
      handleIncomingData();
    }
    calculate_avoidance();
    if ((avoidance_degree > 0) && largestBlobY > 0) {
      int final_degree = mapf(min(max(getDistance(), 5), 28), 5, 28, pidOutput, 1.5 * avoidance_degree);
      motor_and_steer(final_degree);
      //Serial.println(final_degree);
    } else {
      motor_and_steer(pidOutput);
    }
  }
  // while (analogRead(BUTTON) <= 500) {
  //   motor(0);
  // }
  // while (analogRead(BUTTON) > 500)
  //   ;
  // while (analogRead(BUTTON) <= 500)
  //   ;
}
