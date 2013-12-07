#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "joystickDriver.c"
task main()
{
	int sval = 128;
	int s2val = 128;
	while(true){
		getJoystickSettings(joystick);
	servoTarget[servo3] = s2val;
	nxtDisplayCenteredTextLine(3, "%d", s2val);
		servoTarget[servo1] = sval;
		nxtDisplayCenteredTextLine(2, "%d", sval);
		if(joy1Btn(1) == 1){
			sval = sval+5;
			while(joy1Btn(1) == 1){}
		}
		sval += (joystick.joy1_y1/50);
			s2val += (joystick.joy1_y2/50);
			wait1Msec(10);
		if(joy1Btn(3) == 1){
			sval= sval - 5;
			while(joy1Btn(3) == 1 ){}
		}
		if(joy1Btn(2) == 1){
			s2val = s2val+5;
			while(joy1Btn(2) == 1){}
		}
		if(joy1Btn(4) == 1){
			s2val= s2val - 5;
			while(joy1Btn(4) == 1 ){}
		}

	}


}
