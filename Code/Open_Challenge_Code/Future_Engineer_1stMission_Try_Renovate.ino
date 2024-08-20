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
PID_v2 compassPID(0.52, 0.0001, 0.047, PID::Direct);

//Ultra
int const ULTRA_PIN = A9;

//INEX Gyro
float pvYaw, pvRoll, pvPitch;
uint8_t rxCnt = 0, rxBuf[8];

//  Light Sensors
int const RED_SEN = A7;
int const BLUE_SEN = A8;

// Servo
int const STEER_SRV = 16;//16
int const ULTRA_SRV = 23;//23

//Others
char TURN = 'U';
long halt_detect_line_timer;
int Line_Number = 0;
int plus_degree = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

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
    //Serial.println(analogRead(RED_SEN));
    // getIMU();
    // Serial.print("steer:");
    // Serial.print(1 * compassPID.Run(pvYaw + ((getDistance() - 25.5) * -3) * ((float(TURN == 'R') - 0.5) * 2)));
    // Serial.print(" dis:");
    // Serial.println(getDistance());
    motor(60);
    getIMU();
    Color_detection();
    float desiredDistance = 28.5;
    float distanceError = getDistance() - desiredDistance;
    float deadband = 2.0;
    if (abs(distanceError) < deadband) {  
      distanceError = 0.0;
    }
    float directionFactor = (TURN == 'L') ? -1.0 : 1.0;
    float adjustedYaw = pvYaw + (distanceError * directionFactor);
    float pidOutput = compassPID.Run(adjustedYaw);
    steering_servo(pidOutput);
    ultra_servo(pvYaw, TURN);

    if (Line_Number >= 12) {
      long timer01 = millis();
      while (millis() - timer01 < 750) {
        motor(100);
        getIMU();
        Color_detection();
        float desiredDistance = 28.5;
        float distanceError = getDistance() - desiredDistance;
        float deadband = 2.0;
        if (abs(distanceError) < deadband) {
          distanceError = 0.0;
        }
        float directionFactor = (TURN == 'L') ? -1.0 : 1.0;
        float adjustedYaw = pvYaw + (distanceError * directionFactor);
        float pidOutput = compassPID.Run(adjustedYaw);
        steering_servo(pidOutput);
        ultra_servo(pvYaw, TURN);
      }
      motor(0);
      while (true) {
      }
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
