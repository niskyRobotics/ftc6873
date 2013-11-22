#pragma config(Hubs,  S1, HTServo,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S2_C1_1,     driveFrLt,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     driveFrRt,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     driveBkRt,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     driveBkLt,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C3_1,     armL,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C3_2,     flagMtr,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "joystickDriver.c"
#include "autonomousMain.h"
#include "teleopMain.h"


task main(){
	while(true){
		//init servo positions
		getJoystickSettings(joystick);
		if (joystick.StopPgm){
			nxtDisplayTextLine(2, "Disabled!");
			motor[motorD]=0;
			motor[motorE]=0;
			motor[motorF]=0;
			motor[motorG]=0;
			continue;
		}
		if (!joystick.UserMode){
			nxtDisplayTextLine(2, "Autonomous");
			autonMain();
		}
		else{nxtDisplayTextLine(2, "Teleop");
			teleMain();
		}
	}
}
