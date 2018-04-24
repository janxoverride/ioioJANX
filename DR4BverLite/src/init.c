#include "main.h"

void initializeIO() {
}

void initialize() {

////LCD
  lcdInit(uart1);
  lcdClear(uart1);
  lcdSetBacklight(uart1, 1);

///ENCODER
encoderL = encoderInit(5,6,0);
encoderR = encoderInit(7,8,0);

////GYRO
gyro = gyroInit(4,196);

//LCD DISP
  lcdClear(uart1);
  lcdSetText(uart1, 1, "DONE STUDYING");
delay(20);
  lcdClear(uart1);
delay(20);

myauto = 1;

while(1){
///SELECTING AUTO
lcdPrint(uart1, 1, "Auto%d", myauto);
delay(150);
if(lcdReadButtons(uart1) == 1){//LEFT BUTTON
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(100);//BUTTON CHANGING TIME
        myauto = myauto-1;}
if(lcdReadButtons(uart1) == 4){//RIGHT BUTTON
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(100);
        myauto = myauto+1;}
  if(isEnabled()){break;}

  switch(myauto){
     case 1:
       lcdSetText(uart1, 2, "Right 3 Cones");
     break;
     case 2:
       lcdSetText(uart1, 2, "Left 3 Cones");
     break;
     case 3:
       lcdSetText(uart1, 2, "stationary");
     break;
     case 4:
       lcdSetText(uart1, 2, "skills blue right");
     break;
     case 5:
       lcdSetText(uart1, 2, "left 5 point");
     break;
     case 6:
       lcdSetText(uart1, 2, "no");
     break;
     case 7:
       lcdSetText(uart1, 2, "no");
     break;
     case 8:
       lcdSetText(uart1, 2, "NO");
     break;
     case 9:
       lcdSetText(uart1, 2, "NO");
     break;
     case 10:
       lcdSetText(uart1, 2, "NO");
     break;
      }
      delay(20);
    }
      lcdClear(uart1);
  }
