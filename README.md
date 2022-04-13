# Camera_Slider
## A firmware to Drive a Cam slider
### Description
Code for motion and direction control of 2 stepper motors using a joystick.
For motor control, we use the [Adafruit-Motor-Shield-library](https://github.com/adafruit/Adafruit-Motor-Shield-library.git).
### Components
- Arduino Nano
- Joystick
- 2 Stepper Motors
- L293D Motor Shield

### Configuration
Depending on the motor, the number of steps per revolution must be set. For this project, motors with a step angle of 1.8° were used, for which the number of steps is 200. This section is configured in the following line of code.
```
AF_Stepper motor1(200, 1);
```
### Functioning
![Funcionamiento](https://github.com/ArtilRobotics/Camera_Slider/blob/main/images/Camera%20Slider.gif)
