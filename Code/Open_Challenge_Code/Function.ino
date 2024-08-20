
int wrapValue(int value, int minValue, int maxValue) {
  int range = maxValue - minValue + 1;
  if (value < minValue) {
    value += range * ((minValue - value) / range + 1);
  }
  return minValue + (value - minValue) % range;
}

void motor(int speed) {
  if (speed > 0) {
    setMotorDirection(M1, Forward);
    setMotorSpeed(M1, speed);
  } else {
    setMotorDirection(M1, Backward);
    setMotorSpeed(M1, speed);
  }
}

void initMotor() {
  int i;
  for (i = 0; i < MotorNum; i++) {
    digitalWrite(MotorPin[i].enPin, LOW);

    pinMode(MotorPin[i].enPin, OUTPUT);
    pinMode(MotorPin[i].directionPin, OUTPUT);
  }
}

/**  motorNumber: M1, M2
direction:          Forward, Backward **/
void setMotorDirection(int motorNumber, int direction) {
  digitalWrite(MotorPin[motorNumber].directionPin, direction);
}

/** speed:  0-100   * */
inline void setMotorSpeed(int motorNumber, int speed) {
  analogWrite(MotorPin[motorNumber].enPin, 255.0 * (speed / 100.0));  //PWM
}

void zeroYaw() {
  Serial1.begin(115200);
  delay(100);
  // Sets data rate to 115200 bps
  Serial1.write(0XA5);
  delay(10);
  Serial1.write(0X54);
  delay(100);
  // pitch correction roll angle
  Serial1.write(0XA5);
  delay(10);
  Serial1.write(0X55);
  delay(100);
  // zero degree heading
  Serial1.write(0XA5);
  delay(10);
  Serial1.write(0X52);
  delay(100);
  // automatic mode
}

bool getIMU() {
  while (Serial1.available()) {
    rxBuf[rxCnt] = Serial1.read();
    if (rxCnt == 0 && rxBuf[0] != 0xAA) return;
    rxCnt++;
    if (rxCnt == 8) {  // package is complete
      rxCnt = 0;
      if (rxBuf[0] == 0xAA && rxBuf[7] == 0x55) {  // data package is correct
        pvYaw = (int16_t)(rxBuf[1] << 8 | rxBuf[2]) / 100.f;
        pvPitch = (int16_t)(rxBuf[3] << 8 | rxBuf[4]) / 100.f;
        pvRoll = (int16_t)(rxBuf[5] << 8 | rxBuf[6]) / 100.f;
        pvYaw = wrapValue(pvYaw + plus_degree, -179, 180);
        return true;
      }
    }
  }
  return false;
}

void Color_detection() {
  int blue_value = analogRead(BLUE_SEN);
  if (TURN == 'U') {
    int red_value = analogRead(RED_SEN);
    if (blue_value < 605 || red_value < 480) {
      int lowest_red_sen = red_value;
      long timer_line = millis();
      while (millis() - timer_line < 100) {
        int red_value = analogRead(RED_SEN);
        if (red_value < lowest_red_sen) {
          lowest_red_sen = red_value;
        }
      }
      if (lowest_red_sen > 480) {
        // Red
        TURN = 'L';
        plus_degree += 90;
        // ultra_servo(0, 'L');
      } else {
        // Blue
        TURN = 'R';
        plus_degree -= 90;
        // ultra_servo(0, 'R');
      }
      halt_detect_line_timer = millis();
      Line_Number++;
    }
  } else {
    if (millis() - halt_detect_line_timer > 1300) {
      Serial.println(pvYaw);
      if (blue_value < 605) {
        if (TURN == 'R') {
          plus_degree -= 90;
        } else {
          plus_degree += 90;
        }
        halt_detect_line_timer = millis();
        Line_Number++;
      }
    }
  }
}

void steering_servo(int degree) {
  myservo2.write((90 + max(min(degree, 45), -45)) / 2);
}

void ultra_servo(int degree, char mode_steer) {
  int middle_degree = 0;
  if (mode_steer == 'F') {
    middle_degree = 135; 
  } else if (mode_steer == 'L') {
    middle_degree = 135 - 65;  
  } else if (mode_steer == 'R' || mode_steer == 'U') {
    middle_degree = 135 + 90; 
  } else {
  }
  myservo.write(mapf(max(min(middle_degree + degree, 225), 45), 0, 270, 0, 180));
}


float getDistance() {
    float raw_distance = mapf(analogRead(ULTRA_PIN), 0, 1023, 0, 500);
    if (TURN == 'L') {
        raw_distance += 3;  
    } else if (TURN == 'R') {
        raw_distance -= 0;   
    }
    return min(raw_distance, 50);
}
