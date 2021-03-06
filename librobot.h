#pragma config(Hubs,  S1, HTServo,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S2_C1_1,     driveSW,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     driveSE,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     driveNE,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     driveNW,       tmotorTetrix, openLoop)
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
#include "librobot.h"

typedef struct{
	int motorNE;
	int motorNW;
	int motorSE;
	int motorSW;
} TOmniOutput;

/* Calculates the output of a given movement. ns is positive for north.
ew positive for east. rotation positive for clockwise.
*/
void calcoutput(int ns, int ew, int rotation, TOmniOutput &output){
	TOmniOutput tempNS;
	TOmniOutput tempEW;
	//NS calculation
	tempNS.motorNE=-ns;
	tempNS.motorNW=ns;
	tempNS.motorSE=-ns;
	tempNS.motorSW=ns;

	//EW calculation
	tempEW.motorNE=ew;
	tempEW.motorNW=ew;
	tempEW.motorSE=-ew;
	tempEW.motorSW=-ew;


	//averaging
	output.motorNE=(tempNS.motorNE+tempEW.motorNE+rotation)/3;
	output.motorSE=(tempNS.motorSE+tempEW.motorSE+rotation)/3;
	output.motorNW=(tempNS.motorNW+tempEW.motorNW+rotation)/3;
	output.motorSW=(tempNS.motorSW+tempEW.motorSW+rotation)/3;
	return;
}

void smoothUpdate(TOmniOutput &targetVals, TOmniOutput &output){
	output.motorNE=output.motorNE+(output.motorNE>targetVals.motorNE)?-1:+1;
	output.motorNW=output.motorNW+(output.motorNW>targetVals.motorNW)?-1:+1;
	output.motorSE=output.motorSE+(output.motorSE>targetVals.motorSE)?-1:+1;
	output.motorSW=output.motorSW+(output.motorSW>targetVals.motorSW)?-1:+1;
}
