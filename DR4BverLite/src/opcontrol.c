#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "rollers.h"
#include "autofunctions.h"
void operatorControl() {


		bool liftUp;
		bool liftDown;
		int joystickLift;

		int fourbarError;
		int fourbarCurrent;
		int fourbarPower;
		int fourbarTarget;
		bool fourUp;
		bool fourDown;
		bool fourPU;
		bool fourPD;
		float tkp = 0.07;//was 0.3

		bool mgLiftUp;
		bool mgLiftDown;
		bool scoremg;
		bool safemg;

		int power, turn;

		bool rollerOpen;
		bool rollerClose;

		fourbarTarget = analogRead(fourPot);
		stackglobal = 0;

	TaskHandle autoStackHandle = taskCreate(autoStack, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
		while (1==1) {


		//%%%%%%%% JOYSTICK DEFINITIONS %%%%%%%%%//
		mgLiftUp = joystickGetDigital(1,6, JOY_UP);
		mgLiftDown = joystickGetDigital(1,6, JOY_DOWN);
		liftUp = joystickGetDigital(1,5, JOY_UP);
		liftDown = joystickGetDigital(1,5, JOY_DOWN); //out
		fourUp = joystickGetDigital(2,7, JOY_UP);
		fourDown = joystickGetDigital(2,7, JOY_DOWN);
		fourPU = joystickGetDigital(2,5, JOY_UP);
		fourPD = joystickGetDigital(2,5, JOY_DOWN);
		power = joystickGetAnalog(1,1);
		turn = joystickGetAnalog(1,3);
		rollerClose = joystickGetDigital(2,6,JOY_UP);
		rollerOpen = joystickGetDigital(2,6,JOY_DOWN);
		scoremg = joystickGetDigital(1,8,JOY_DOWN);
		safemg = joystickGetDigital(1,8,JOY_UP);



int mgs = analogRead(mgPot);
lcdPrint(uart1,1,"mg%d",mgs);
//up 860 down 2510 
//int mgx = analogRead(mgPot);
//lcdPrint(uart1,1,"mg%d",mgx);
//in 2950 out 1020 mobile goal
//fourbar up 200
//fourbar down 105
//mg 250 in
//mg out
//lift starting pos 2530
//lift up beginning 2050
		//^^^^^^^^ MOBILE GOAL lift ^^^^^^^^^^^//
		if(mgLiftUp == 1){mgSet(-90);}
		else if(mgLiftDown == 1){mgSet(90);}
		else{mgSet(0);}

		if(safemg == 1){
			if(analogRead(mgPot)<1250){mgSet(90);}
			else{mgSet(0);}
		}

		if(scoremg == 1){
			if(analogRead(mgPot)>1550){mgSet(-90);}
			else{mgSet(0);}
		}

		//******** DRIVE ********//
		driveSet(power - turn, power + turn);

	////AUTOSTACKING AND LIFT FOURBAW roller FUNCTIONS/////

if(stackglobal != 1){


	//$$$$$$$$$ fourbar $$$$$$$$$//
	if(fourUp == 1 ){
		fourSet(90);
		fourbarTarget = analogRead(fourPot);
	}
	else if(fourDown == 1 ){
		fourSet(-90);
		fourbarTarget = analogRead(fourPot);
	}
	else if((fourUp == 0 && fourDown == 0 )){
		fourbarCurrent = analogRead(fourPot);
		fourbarError = fourbarTarget - fourbarCurrent;
		fourbarPower = fourbarError*tkp;
		fourSet(fourbarPower);
	}


	/////presets fourbar
	if(fourPU ==1){fourbarTarget = 1920;}
	if(fourPD ==1){fourbarTarget = 320;}

	/////lift/////
	joystickLift = joystickGetAnalog(2,3);


	if(joystickLift>10){liftSet(-joystickLift);}
	else if(joystickLift<(-10)){liftSet(-joystickLift);}

	else if(joystickLift>-10 &&joystickLift<10 && liftUp == 0 && liftDown == 0){liftSet(0);}///// add in  && analogRead(liftPot)>liftvalue

	else if(liftUp == 1){
		liftSet(-90);
	}
	else if(liftDown == 1){
		liftSet(90);
	}

/////roller/////

if(rollerOpen == 1){
	rollerSet(-90);
}
	else if(rollerClose == 1){
		rollerSet(90);
	}
		else{rollerSet(10);}

	delay(20);
}
else{
	if(joystickGetDigital(2,8,JOY_RIGHT)){
		taskDelete(autoStackHandle);
			liftSet(-10);
			fourSet(0);
			rollerSet(-10);
			stackglobal = 0;
			fourbarTarget = analogRead(fourPot);
			autoStackHandle = taskCreate(autoStack, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
			}
			delay(20);
}
}
delay(20);
}
