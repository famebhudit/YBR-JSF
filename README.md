# <p align="center"><span style="font-size: 500px;">WRO 2024 Future Engineer</span></p>

<p align="center">
  <img src="https://ybrobot.club/image/YB%20Robot%20logo.png" alt="YB Robot Logo" width="300" height="250">
</p>

<br>
<br>

# Introduction
This document contains the engineering materials for the autonomous vehicle robot model created for the 2024 WRO Future Engineers competition. It includes documentation, design schematics, programming code, and other technical resources essential for understanding the robot's design and functionality.

# Content
`Portion 1: Insights into our team` This portion contains the key information about our team.

-Team Member

-Team Background Information

`Portion 2: Our Robot Hardware` This portion contains the key components opf our robot.

-Main controller

-Board Extension

-Driving Motor

-Servo

-Step-Down

-Compass

-Button

-Switch

-Camera

-Ultrasonic

-Sensor

`Portion 3: Obstacle management` This portion explains how the robot manages the obtacles.

-Challenges

-Code

# <span style="font-size: 300px;">Portion 1: Insights into our team</span>
## Team Member:

1.  Bhudit    Thanaphakgosol
2.  Saknun    Sattham
3.  Norapat   Nimitkiatklai

<br>

## Team Background Information:
We're Bhudit, Saknun, and Norapat, seniors at Yothinburana School. We've been a team since we first met in the YB Robot Club back in grade 7, and we've been working together ever since.
<br><br>
Saknun is our go-to engineer, with a talent for crafting intricate mechanical designs that are as reliable as they are innovative. Bhudit, our coding genius, brings our creations to life with precise and efficient programming. Norapat, our strategist, ensures that every robot we build is not just functional, but optimized to win. Together we are team YBR-JSF.
Over the years, we've spent countless afternoons and weekends in the school's robotics lab, fine-tuning our skills and pushing the boundaries of what's possible. We've competed in local robotics competitions, learning valuable lessons from each challenge we faced.
Our goal this year is clear: we want to qualify for the international competition in Turkey. Last year, we came close but missed out. This time, we're more determined than ever. We've spent our summer break improving our robots, learning new techniques, and strengthening our teamwork.
<br><br>
As we enter our final year at Yothinburana School, we're ready to show the world what Team YBR-JSF is made of. With the support of our classmates and mentors, we're confident that this year will be our year to shine in the world of robotics.
<br><br>

## Team Strategy:
Our strategy revolves around teamwork beyond individual roles, emphasizing collective problem-solving and continuous support. Facing challenges, we unite to brainstorm solutions, leveraging diverse perspectives to innovate in mechanical design, coding, and competition strategy.
<br><br>
Outside formal sessions, we maintain open communication, sharing resources and feedback to strengthen our bond and enhance our effectiveness as a team. Our goal is clear: qualifying for the international competition in Turkey after narrowly missing out last year.
<br><br>

# <span style="font-size: 300px;">Portion 2: Our Robot Hardware</span>
## 1. Main controller
### <ins>ARDUINO MEGA: Arduino Mega 2560</ins>
<br><br>
<p align="center">
  <img src="https://cdn-reichelt.de/bilder/web/xxl_ws/B300/ARDUINO_MEGA_A01.png" alt="Arduino Mega 2560" width="500" height="300">
</p>
<br><br>
The Arduino Mega 2560 is a robust microcontroller board based on the ATmega2560 chip, running at 16 MHz. It features 256 KB of Flash memory (with 8 KB used by the bootloader), 8 KB of SRAM, and 4 KB of EEPROM. With 54 digital I/O pins (including 15 PWM outputs) and 16 analog inputs, it supports a wide range of sensors and actuators. Communication interfaces include UART, SPI, and I2C, alongside USB for programming and serial communication. Operating at 5V, it's compatible with Arduino shields and widely used in robotics, automation, and complex sensor applications, supported by a vibrant Board Extension community.
<br><br>


## 2. Board Extension
### <ins>Gravity: IO Sensor Shield For Arduino Mega</ins>
<p align="center">
  <img src="https://www.botnroll.com/18911-medium_default/shield-de-expancao-de-entradas-e-saidas-para-arduino-mega.jpg" alt="IO Sensor Shield" width="450" height="400">
</p>
<br><br>
This shield includes 3 Xbee slots, 1 microSD slot, Arduino shield headers to plugin most Arduino Shields. It also includes a prototyping area and breakouts for Digital pins 14 to 53, Analog pins 6 to 15 and PWM pins 2 to 9.
<br><br>  

### <ins>Gravity: 2x2A Motor Shield for Arduino Twin</ins>
<p align="center">
  <img src="https://images.prom.ua/4596325232_w640_h640_gravity-2x2a.jpg" alt="2x2A Motor Shield" width="300" height="300">
</p>
Motor shield allows Arduino to drive two channel DC motors, which uses a L298N chip which deliveries output current up to 2A each channel. Motor Driven Voltage is 4.8V to 35V, which driven in Dual full-bridge driver. The control function can be separated into two types, namely En and Mn, which are provided in the tables below.
<br><br>

- Control Function Table:
<img src="https://github.com/famebhudit/Robot_Image/blob/main/Screenshot%202024-07-24%20184221.png?raw=true" alt="Function Table" width="400" height="200">
<br><br>

- Control Signal Truth Table:
<img src="https://github.com/famebhudit/Robot_Image/blob/main/Screenshot%202024-07-24%20184316.png?raw=true" alt="Signal Truth Table" width="400" height="200">
<br><br>


## 3. Driving Motor
### <ins>LEGO® Power Functions L-Motor</ins>
<br><br>
<p align="center">
<img src= "https://www.lego.com/cdn/cs/set/assets/blt3289051a0e80fa54/88003.jpg?format=webply&fit=bounds&quality=70&width=800&height=800&dpr=1.5" alt="Signal Truth Table" width="600" height="350">
</p>
The LEGO® Power Functions L-Motor is designed to motorize large LEGO builds. It has a speed of 380 rpm and have ability to spin wheels and turn gears, with more power and speed than the standard M-Motor.
<br></br>


## 4. Servo
### <ins>Geekservo 2kg 360 Degrees Rotation Servo</ins>
<p align="center">
<img src= "https://i.ebayimg.com/images/g/VtMAAOSwZ9VfPQUW/s-l500.jpg" alt="Signal Truth Table" width="500" height="450">
</p>

- Electric Specifications
<img src="https://github.com/famebhudit/Robot_Image/blob/main/Screenshot%202024-07-27%20101426.png?raw=true" alt="Electric Spec" width="650" height="300">
<br><br>

## 5.Step-Down
### <ins>Step Down Module 12 V to 5 V Size 5 A</ins>

<p align="center">
<img src= "https://gd.lnwfile.com/_/gd/_raw/kz/77/it.jpg" alt="Signal Truth Table" width="500" height="350">
</p>
A step-down converter is a DC-to-DC converter which decreases voltage, while increasing current, from its input (supply) to its output (load). The efficiency of step-down converters can be very high, often over 90%, making them useful for tasks such as converting a computer's main supply voltage, which is usually 12 V, down to lower voltages needed by USB, DRAM and the CPU, which are usually 5, 3.3 or 1.8 V.
<br></br>

## 6.Compass
### <ins>GY-25 Tilt sensor module</ins>

<p align="center">
<img src= "https://electropeak.com/pub/media/catalog/product/cache/95f75205f3b943f313b30831421df8c2/s/e/sen-02-007-1-mpu6050-gy-25-three.jpg" alt="Signal Truth Table" width="350" height="350">
</p>
The GY-25 MPU6050 3-Axis Gyroscope Sensor Module offers high-resolution tilt angle measurements using a 3V-5V MPU6050 chip. It integrates a gyroscope, accelerometer, and Digital Motion Processor™ for 9-axis data and supports additional sensors via I2C. Ideal for enhancing devices in health, fitness, and location-based applications.
<br></br>

## 7.Button
### <ins>ZX-Switch01</ins>
<br>
<p align="center">
<img src= "https://inex.co.th/home/wp-content/uploads/2020/07/zx-switch01.jpg" alt="Signal Truth Table" width="350" height="350">
</p>
When the ZX-Switch01 is pressed, the DATA pin has logic “1” from R2 connected to the pull-up. When the switch is pressed, the DATA pin becomes “0” because the switch is shorted to ground. The DATA pin can be used as an input.
<br></br>

## 8.Switch
### <ins>Everyday switch</ins>
<br>
<p align="center">
<img src= "https://www.codrey.com/wp-content/uploads/2019/10/Rocker-Switch.jpg" alt="Signal Truth Table" width="350" height="350">
</p>
A regular everyday switch. This is used for cutting power from the battery to the robot.
<br></br>

## 9.Camera
### <ins>OpenMV H7 camera</ins>
<br>
<p align="center">
<img src= "https://o.lnwfile.com/_/o/_raw/pm/nx/ez.jpg" alt="Signal Truth Table" width="350" height="350">
</p>
The OpenMV Cam is a small, low-power microcontroller board for machine vision. It uses Python scripts through MicroPython, making complex tasks easier to manage. You control the board and its I/O pins fully with Python. It supports image and video capture triggered by external events. You can also use machine vision algorithms to control I/O pins.
<br></br>

## 10.Ultrasonic
### <ins>URM09 Ultrasonic Distance Sensor</ins>
<br><br>
<p align="center">
<img src= "https://dfimg.dfrobot.com/store/data/SEN0307/SEN0307.jpg?imageView2/1/w/564/h/376" width="400" height="250">
</p>
The DFRobot URM09 is an ultrasonic sensor designed for quick ranging and obstacle avoidance. It measures distances up to 500 cm with a frequency of up to 30Hz and features built-in temperature compensation and analog output. Compatible with Arduino, Raspberry Pi, and other 3.3V or 5V logic boards, it offers accurate distance measurements.
<br></br>

## 11.Sensor
### <ins>ZX-03R</ins>
<br>
<p align="center">
<img src= "https://inex.co.th/home/wp-content/uploads/2020/07/zx_03r.jpg" width="250" height="250">
</p>
The sensor uses a high-brightness red LED and a SFH310 photo transistor to detect red light reflected from objects. The amount of detected light depends on the object's ability to reflect red light, which varies with surface texture and color. Smooth, white objects reflect more light, resulting in a higher output voltage.
<br></br>

### <ins>ZX-03B</ins>
<br>
<p align="center">
<img src= "https://inex.co.th/home/wp-content/uploads/2020/07/zx-03b.jpg" width="250" height="250">
</p>
The sensor detects light reflections to differentiate between light and dark surfaces. The ZX-03B with a blue LED is best for surfaces that absorb light or have blue hues, while other ZX-03 models distinguish between white and black. Readings vary based on surface texture, distance (typically 3-15 mm), and external light interference.
<br></br>

# <span style="font-size: 300px;">Portion 3: Obstacle management</span>
## Challenges 
We use OpenMV IDE and Arduino IDE. The programming is organized into two parts: Open Challenge & Obstacle Challenge.
### 1.Open Challenge
In open challenges, the bottom OpenMV H7 camera helps the robot determine its direction of movement: it will proceed clockwise if the camera detects an orange line and counterclockwise if it detects a blue line. 

Gyro sensors ensure that the robot maintains a straight path and makes precise turns. 

Additionally, the left and right ultrasonic sensors measure the distance between the robot and the walls, allowing the steering to make adjustments to prevent collisions as the robot approaches the wall.
### 2.Obstacle challenge
The primary sensor helping the robot in this challenge is the OpenMV H7 camera. The lower OpenMV H7 camera detects traffic signs; if it identifies a red sign, the robot will turn right, and if it detects a green sign, it will also turn accordingly.

Additionally, the bottom OpenMV H7 camera helps the robot follow the colored lines on the map. If the robot encounters an orange line, it will turn clockwise; if it encounters a blue line , it will turn counterclockwise.

The gyro sensors continue to ensure that the robot travels in a straight line and maintains precise control when turning.
## Code

This Section provides a basic explanation of the code that is used in the robot
<br></br>
(a) Open Challenge
<br></br>
1. Getting direction: The robot uses the gyro sensor to get the heading direction.
<p align="center">
<img src= "https://github.com/famebhudit/Robot_Image/blob/main/Screenshot%202024-08-21%20005314.png" width="250" height="280">
</p>
<p align="center">
<img src= "https://github.com/famebhudit/Robot_Image/blob/main/Screenshot%202024-08-21%20005338.png" width="450" height="280">
</p>

<br></br>

2. Avoid Walls: The robot uses ultrasonic to maintain the distance between the walls and the robots. When the robot gets closer to the wall, the steering will do a correction to avoid hitting the wall.
<p align="center">
<img src= "https://github.com/famebhudit/Robot_Image/blob/main/Screenshot%202024-08-21%20011047.png" width="450" height="280">
</p>

<br></br>

3. Turning: The robot uses the bottom sensor to check the color line on the map. The information is used to determine the heading of the robot. The robot will run clockwise if it detects the orange line first and vice versa for the blue line.
<p align="center">
<img src= "https://github.com/famebhudit/Robot_Image/blob/main/Screenshot%202024-08-21%20011846.png" width="400" height="550">
</p>

<br></br>

(b) Obstacle Challenge

<br></br>
1. Getting direction: The robot uses the gyro sensor to get the heading direction.
<p align="center">
<img src= "https://github.com/famebhudit/Robot_Image/blob/main/Screenshot%202024-08-21%20005314.png" width="250" height="280">
</p>
<p align="center">
<img src= "https://github.com/famebhudit/Robot_Image/blob/main/Screenshot%202024-08-21%20005338.png" width="450" height="280">
</p>

<br></br>

2. Avoid Walls: The robot uses ultrasonic to maintain the distance between the walls and the robots. When the robot gets closer to the wall, the steering will do a correction to avoid hitting the wall.
<p align="center">
<img src= "https://github.com/famebhudit/Robot_Image/blob/main/Screenshot%202024-08-21%20011047.png" width="450" height="280">
</p>

<br></br>

3. Turning: The robot uses the bottom sensor to check the color line on the map. The information is used to determine the heading of the robot. The robot will run clockwise if it detects the orange line first and vice versa for the blue line.
<p align="center">
<img src= "https://github.com/famebhudit/Robot_Image/blob/main/Screenshot%202024-08-21%20011846.png" width="400" height="550">
</p>

<br></br>

## Credits

We sincerely appreciate LEGO Education for their invaluable support and commitment to providing us with high-quality LEGO EV3 sets. Our gratitude also extends to the team sponsors: Premier of Sarawak; Ministry of Education Innovation and Talent Development Sarawak (MEITD); Yayasan Sarawak; Welfield Services SB; YB Mayor Adam Yii Siew Sang; and Alumni IPGKS-IPS-MPS.
