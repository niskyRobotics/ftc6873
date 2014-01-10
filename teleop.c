#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     driveLt,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     driveRt,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     flag,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     rack,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

void servoGrab(){
	nxtDisplayCenteredTextLine(2, "servoIn");
	servoTarget[servo1] = 237;
	servoTarget[servo3] = 149;
	wait10Msec(30);
	servoTarget[servo1] = 114;
	wait10Msec(10);
	servoTarget[servo3] = 71;
	wait10Msec(10);
	servoTarget[servo1] = 164;
	wait10Msec(10);
	//servoTarget[servo1] = 121;
	//wait10Msec(100);
	servoTarget[servo3] = 91;

	wait10Msec(10);

	servoTarget[servo3] = 103;
	wait10Msec(10);
	servoTarget[servo1] = 140;
	wait10Msec(10);
	servoTarget[servo3] = 79;
	wait10Msec(10);
	servoTarget[servo1] = 180;
}

void servoOut(){

}
/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of tele-op mode, you may want to perform some initialization on your robot
// and the variables within your program.
//
// In most cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
	// Place code here to sinitialize servos to starting positions.
	// Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the tele-op robot operation. Customize as appropriate for
// your specific robot.
//
// Game controller / joystick information is sent periodically (about every 50 milliseconds) from
// the FMS (Field Management System) to the robot. Most tele-op programs will follow the following
// logic:
//   1. Loop forever repeating the following actions:
//   2. Get the latest game controller / joystick settings that have been received from the PC.
//   3. Perform appropriate actions based on the joystick + buttons settings. This is usually a
//      simple action:
//      *  Joystick values are usually directly translated into power levels for a motor or
//         position of a servo.
//      *  Buttons are usually used to start/stop a motor or cause a servo to move to a specific
//         position.
//   4. Repeat the loop.
//
// Your program needs to continuously loop because you need to continuously respond to changes in
// the game controller settings.
//
// At the end of the tele-op period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
	initializeRobot();

	waitForStart();   // wait for start of tele-op phase

	int motorLeft = 0;
	int motorRight = 0;
	while(true){
		getJoystickSettings(joystick);

		motorLeft = (motorLeft + joystick.joy1_x1) / 2;
		motorRight = (motorRight + joystick.joy1_x1) / 2;
		motor[driveLt] = motorLeft;
		motor[driveRt] = motorRight;
		motor[flag] = joystick.joy2_y1;
		motor[rack] = joystick.joy2_y2;
		if(joy2Btn(2)==1){
			nxtDisplayCenteredTextLine(2, "servoIn");
			servoTarget[servo1] = 237;
			servoTarget[servo3] = 149;
			wait10Msec(40);
			servoTarget[servo1] = 114;
			wait10Msec(40);
			servoTarget[servo3] = 71;
			wait10Msec(40);
			servoTarget[servo1] = 164;
			wait10Msec(40);
			//servoTarget[servo1] = 121;
			//wait10Msec(100);
			servoTarget[servo3] = 91;

			wait10Msec(40);

			servoTarget[servo3] = 103;
			wait10Msec(40);
			servoTarget[servo1] = 140;
			wait10Msec(40);
			servoTarget[servo3] = 79;
			wait10Msec(40);
			servoTarget[servo1] = 180;
		}
		if(joy2Btn(4)==1){
			servoTarget[servo1] = 205;
			servoTarget[servo3] = 141;
			wait10Msec(40);

			servoTarget[servo1] = 196;
			servoTarget[servo3] = 61;
			wait10Msec(40);

			servoTarget[servo1] = 155;
			servoTarget[servo3] = 70;
			wait10Msec(40);

			servoTarget[servo1] = 170;
			servoTarget[servo3] = 69;
			wait10Msec(80);

			servoTarget[servo1] = 126;
			servoTarget[servo3] = 79;
			wait10Msec(40);
			servoTarget[servo1] = 237;
			servoTarget[servo3] = 149;
		}
	}
}
