# Clench-bot-2.0


# Code overview

This code is for a robot that is controlled by pulse width modulation (PWM) signals. The robot has two base tilts (left and right) and six input channels (two for each base tilt and two for the wheels). The code is written in C++ and was developed for use with an Arduino microcontroller.

## Hardware setup

The robot's base tilts and input channels are defined as instances of the `BTS` and `FS_I6` classes, respectively. The `BTS` class represents a base tilt and contains variables for the PWM pins, enable pins, and current speed. The `FS_I6` class represents the six input channels and contains variables for the channel pins and current values.



## Hardware used

1. Micro controller - Arduino Mega
2. Motor Driver - BTS 7960 
3. Controller - Fly sky i6
4. Motors - Center shaft motor (150 RPM)
5. Acrylic sheet of 2mm used via laser cutting for making structure/chasis of bot 
6. Wheels - 3.5cm Radius
7. Servo - a. 360 degree 9kg/cm 
                 b. 180 degree - 18kg/cm
8. Battery - Li-po 2200 Mah
9. Jumper wires


In the `setup()` function, the input channels are initialized and the serial communication is started.

## Motor control

In the `loop()` function, the input values from the six channels are read and the speeds of the two base tilts are set accordingly. The `rotate()` function of the `BTS` class is used to set the speed of the base tilt. The `rotate()` function maps the input value to a range of -255 to 255 and sets the PWM values of the left and right motors accordingly. If the input value is 0, the base tilt remains stationary. If the input value is greater than 0, the base tilt rotates in a positive direction. If the input value is less than 0, the base tilt rotates in a negative direction.

## Getting started

To use this code, you will need to connect the appropriate hardware to your Arduino microcontroller and upload the code using the Arduino Integrated Development Environment (IDE). You will also need to provide the necessary PWM signals to control the robot.

## Questions or feedback

If you have any questions or need further assistance, please don't hesitate to reach out. We are here to help!
