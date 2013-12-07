 #pragma config(Hubs,  S1, HTServo,  none,     none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S2_C1_1,     driveLt,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     driveRt,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     flag,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     rack,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
 ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////
  ////                                                   ////
  ////    Add your robot specific autonomous code here.  ////
  ////                                                   ////
  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////
 motor[driveLt]=100;
    motor[driveRt]=100;
    wait10Msec(100);
    motor[driveLt]=30;
    motor[driveRt]=-30;
    wait10Msec(50);
    motor[driveLt]=80;
    motor[driveRt]=80;
    wait10Msec(100);
    motor[driveLt]=0;
    motor[driveRt]=0;
  while (true)
  {}
