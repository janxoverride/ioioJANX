#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "rollers.h"
#include "autofunctions.h"

void autoDrive(int direction, int target, int timeout){///DRIVING STRAIGHT

  int leftPower;
  int rightPower;
  int tics;
  int ticsL;
  int ticsR;
///RESET ALL VALUES AND SENSORS
  tics = 0;
  encoderReset(encoderL);
  encoderReset(encoderR);
  int startTime = millis();

while(tics < target && (millis()-startTime)<timeout){///UNDER TARGET

  ticsL = encoderGet(encoderL);
  ticsR = encoderGet(encoderR);
  tics = (abs(ticsL) + abs(ticsR))/2;

if(tics < target){
      leftPower = -90;
      rightPower = 77;}
    else{
      leftPower = 0;
      rightPower = 0;}
    // checking R
driveSet(direction*rightPower,direction*leftPower);
lcdPrint(uart1, 1, "tics%d", tics);
      delay(20);
}
}

void gyroTurnPID(int direction, int targetTurn, int timeout, float kp, float kd)
{
gyroReset(gyro);

int error = 0;
int error_last = 0;
int error_diff = 0;
int error_sum = 0;
int pos =  0;
float ki = 0;
float p;
float d;
float i;
int drivepower;

int startTime = millis();
while((millis()-startTime)<timeout)
{
lcdPrint(uart1, 1, "pos%d", pos);
lcdPrint(uart1, 2, "error%d", error);

pos = abs(gyroGet(gyro));
error =  targetTurn - pos;

error_diff = error - error_last;
error_last = error;
error_sum  += error; // same as errorsum  = errorsum + error

p = kp * error;

d  = kd * error_diff;
if(error < 5) //icap
{i = ki * error_sum;}

drivepower = p+i+d;
if(drivepower>90){drivepower = 90;}
if(drivepower<-90){drivepower = -90;}

int leftside = direction*drivepower;
int rightside = direction*drivepower;
driveSet(leftside, rightside);
delay(40);
}
lcdSetText(uart1,1,"done");
delay(20);
}

void mobileGoal(int direction, int target){
  int pos = analogRead(mgPot);
  int startTime = millis();

  if(direction == 1){//OUT
   pos = analogRead(mgPot);
   while(pos>target && (millis()-startTime)<2500)//OUT
   {
     pos = analogRead(mgPot);
     mgSet(-90);//CHANGE IF DIRECTION IS WRONG
   }
   }

    else{
    pos = analogRead(mgPot);
     while(pos<target && (millis()-startTime)<2500)
     {pos = analogRead(mgPot);
      mgSet(90);}//IN
    }
    mgSet(0);//STOP
    }

void lift(int direction, int target, int power){
int  pos = analogRead(liftPot);

///direction 1 is up, encoder decreases as lift moves up

if(direction == 1){
pos = analogRead(liftPot);
while(pos>target)
{
pos = analogRead(liftPot);
liftSet(-power);
delay(20);
}
}

if(direction == -1){
  while(pos<target){
  pos = analogRead(liftPot);
liftSet(power);
  delay(20);
  }
  }

liftSet(6*direction);//HOLD IN AUTO
}

void fourbar(int direction, int target){
  int pos = analogRead(fourPot);
    if(direction == 1){
     pos = analogRead(fourPot);
     while(pos>target)
     {
       pos = analogRead(fourPot);
       fourSet(90);
     }
     }
      else{
      pos = analogRead(fourPot);
       while(pos<target){
        pos = analogRead(fourPot);
        fourSet(-90);}
      }
      fourSet(0);
      }

void fourAUp(){
fourbar(1,1980);
}

void fourADown(){
  fourbar(-1,290);
  fourSet(-10);
}

void rollerOpen(){
  rollerSet(90);
  delay(200);
  rollerSet(0);
}

void rollerClose(){
  rollerSet(-90);
  delay(200);
  rollerSet(-10);
}

void autoStack(void*parameter){
  while(true){
    if(joystickGetDigital(2,8,JOY_DOWN)){
    stackglobal =1;
  int armpos = analogRead(liftPot);
  rollerSet(-10);
  lift(1,(armpos-2),90);
  lcdPrint(uart1,2,"lift up done");
  fourAUp();
  lcdPrint(uart1,2,"four up done");
  fourSet(12);
  lift(-1,(armpos-1),90);
  lcdPrint(uart1,2,"lift down done");
  rollerSet(127);
  delay(230);
  lift(1, (armpos-1),90);
  lcdPrint(uart1,2,"lift up done");
  delay(60);
  fourADown();
  lcdPrint(uart1,2,"four up done");
  delay(10);
  rollerSet(-90);
  delay(19);
  lift(-1,2500,90);
  stackglobal = 0;

  }
  delay(20);

}
}


void armTask(void*parameter){
  armTarget = analogRead(liftPot);
  int pos = analogRead(liftPot);
  int err;
  int power;
  int err_last;
  int err_diff;
  int p;
  int d;
  float kd = 0.8;
  float kp = 0.16;
  while(true){
  if(!isEnabled()){break;}
  lcdPrint(uart1,2,"err%d",err);
  lcdPrint(uart1,1,"pos%d",pos);
  pos = analogRead(liftPot);
  err = armTarget -pos;
  err_diff = err - err_last;
  err_last = err;
  p = kp * err;
  d  = kd * err_diff;
  power = p+d;
  liftSet(power);
  delay(20);
  }
  liftSet(0);
  taskDelete(armTaskHandle);
}

void fourbarTask(void*parameter){
  fourbarTarget = analogRead(fourPot);
  int pos = analogRead(fourPot);
  int err;
  int err_diff;
  int err_last;
  int power;
  float p;
  float d;
  float kd = 0;
  float kp = 0.07;
  while(true){
  if(!isEnabled()){break;}
  pos = analogRead(fourPot);
  err = fourbarTarget - pos;
  err_diff = err - err_last;
  err_last = err;
  p = kp * err;
  d  = kd * err_diff;
  power = p+d;
  fourSet(power);
  delay(20);
  }
  fourSet(0);
  taskDelete(fourbarTaskHandle);
}

void mgTask(void*parameter){
  mgTarget = analogRead(mgPot);
  int pos = analogRead(mgPot);
  int err;
  int power;
  float kp = 0.1;
  while(true){
  if(!isEnabled()){break;}
  pos = analogRead(mgPot);
  err = mgTarget - pos;
  power = err*kp;
  mgSet(power);
  delay(20);
  }
  mgSet(0);
  taskDelete(mgTaskHandle);
}

void stop()
{
  while (1) {
  motorSet(1, 0);
  motorSet(2, 0);
  motorSet(3, 0);
  motorSet(4, 0);
  motorSet(5, 0);
  motorSet(6, 0);
  motorSet(7, 0);
  motorSet(8, 0);
  motorSet(9, 0);
  motorSet(10, 0);
}
}
