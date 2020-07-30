stepper motor is interfaced with Beaglebone black wireless using ULN2003 driver module. In order to control the motor,
IN1 to IN4 pins can be controlled by 4 gpio pins.
steps involved:
$git clone https://github.com/joyalraju/iobb.git
$cd iobb/ 
$make
$make install // adding library to the path
for compilation:
gcc -o motor motor.c -liobb
