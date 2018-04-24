#include "autofunctions.h"
#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "rollers.h"




void autonomous() {
	TaskHandle armTaskHandle = taskCreate(armTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  TaskHandle mgTaskHandle = taskCreate(mgTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	TaskHandle fourbarTaskHandle = taskCreate(fourbarTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

   switch(myauto){

     //gyroTurnPID(1,47,1200,3,6);//45degrees with mobile goal
     //gyroTurnPID(1,91,1200,3,6);//90 degrees with mobile goal
     //gyroTurnPID(1,135,1200,3,6);//135 degrees with mobile goal

//mgin with mg in mgTarget = 1190;
//mgout mgTarget = 3000;
//fourbar down fourbarTarget = 2380;
//four up fourbarTarget = 650;
//driveSet(-90,90);//hold power

     case 1:
		 delay(30);
 		rollerSet(40);
 		fourbarTarget = 1920;
		delay(20);
		armTarget = 2100;
 		delay(200);
 		mgTarget = 3000;
 		delay(200);
 		autoDrive(-1,1100,2000);//1170
 		delay(100);
 		mgTarget = 1190;
 		delay(1100);
 		armTarget = 2370;
 		delay(100);
 		rollerSet(-90);
 		delay(180);
 		//second cone
		armTarget = 2270;
 		autoDrive(-1,90,600);
 		rollerSet(90);
 		fourbarTarget = 320;
 		delay(100);
 		armTarget = 2460;//drop on cone
 		delay(400);
 		rollerSet(40);
 		armTarget = 2150;
 		delay(150);
 		fourbarTarget = 1820;
 		delay(400);
 		armTarget = 2360;
 		delay(200);
 		rollerSet(-90);
 		delay(200);
 		armTarget = 2100;
 		//third cone
 		autoDrive(-1,70,500);
 		 rollerSet(90);
 		 fourbarTarget = 320;
 		 delay(200);
 		 armTarget = 2460;
 		 delay(400);
 		 rollerSet(40);
 		 armTarget = 2000;
 		 delay(200);
 		 fourbarTarget = 1920;
 		 delay(300);

 			gyroTurnPID(1,7,500,4,6);
 		 autoDrive(1,1430,2000);//1500
 		 gyroTurnPID(1,45,550,3,6);//first turn

 		 autoDrive(1,560,1100);//drive AlONG 10 point pipe
 		 gyroTurnPID(1,84,650,3,6);//78 squareup with pipe
 		armTarget = 2280;
 		delay(100);
 		rollerSet(-90);
 		delay(100);
 		 armTarget = 1900;
 		 autoDrive(-1,500,1000);// drive inside zone
 		 driveSet(-30,30);
 		delay(100);
 		 mgTarget = 3000;
 		delay(1200);
 		mgTarget = 2000;
 		rollerSet(0);
 		autoDrive(1,350,800);//back back out of the shit
		gyroTurnPID(-1,130,700,3,6);
		autoDrive(-1,600,1000);

     break;

		 case 2://left side 3 cones
		 delay(30);
		 rollerSet(40);
		 fourbarTarget = 1920;
		 delay(20);
		 armTarget = 2100;
		 delay(200);
		 mgTarget = 3000;
		 delay(200);
		 autoDrive(-1,1100,2000);//1170
		 delay(100);
		 mgTarget = 1190;
		 delay(1100);
		 armTarget = 2370;
		 delay(100);
		 rollerSet(-90);
		 delay(180);
		 //second cone
		 armTarget = 2270;
		 autoDrive(-1,90,600);
		 rollerSet(90);
		 fourbarTarget = 320;
		 delay(100);
		 armTarget = 2460;//drop on cone
		 delay(400);
		 rollerSet(40);
		 armTarget = 2150;
		 delay(150);
		 fourbarTarget = 1820;
		 delay(400);
		 armTarget = 2360;
		 delay(200);
		 rollerSet(-90);
		 delay(200);
		 armTarget = 2100;
		 //third cone
		 autoDrive(-1,70,500);
		 rollerSet(90);
		 fourbarTarget = 320;
		 delay(200);
		 armTarget = 2460;
		 delay(400);
		 rollerSet(40);
		 armTarget = 2000;
		 delay(200);
		 fourbarTarget = 1920;
		 delay(300);

		  gyroTurnPID(-1,7,500,4,6);
		 autoDrive(1,1430,2000);//1500
		 gyroTurnPID(-1,45,550,3,6);//first turn

		 autoDrive(1,560,1100);//drive AlONG 10 point pipe
		 gyroTurnPID(-1,84,650,3,6);//78 squareup with pipe
		 armTarget = 2280;
		 delay(100);
		 rollerSet(-90);
		 delay(100);
		 armTarget = 1900;
		 autoDrive(-1,500,1000);// drive inside zone
		 driveSet(-30,30);
		 delay(100);
		 mgTarget = 3000;
		 delay(1200);
		 mgTarget = 2000;
		 rollerSet(0);
		 autoDrive(1,350,800);//back back out of the shit
		 gyroTurnPID(1,130,700,3,6);
		 autoDrive(-1,600,1000);
		 break;


		 case 3: ///stationary
		 delay(20);
rollerSet(40);
delay(20);
fourbarTarget = 320;
delay(200);
armTarget = 1250;
delay(700);
autoDrive(-1,300,500);
armTarget = 1600;
rollerSet(-90);
delay(200);
armTarget = 1250;
autoDrive(1,100,500);


		 break;

case 4://skills auto
delay(30);
rollerSet(40);
fourbarTarget = 1920;
delay(20);
armTarget = 2100;
delay(200);
mgTarget = 3000;
delay(200);
autoDrive(-1,1100,2000);//1170
delay(100);
mgTarget = 1190;
delay(1100);
armTarget = 2370;
delay(100);
rollerSet(-90);
delay(180);
//second cone
armTarget = 2270;
autoDrive(-1,90,600);
rollerSet(90);
fourbarTarget = 320;
delay(100);
armTarget = 2460;//drop on cone
delay(400);
rollerSet(40);
armTarget = 2150;
delay(150);
fourbarTarget = 1820;
delay(400);
armTarget = 2360;
delay(200);
rollerSet(-90);
delay(200);
armTarget = 2100;
//third cone
autoDrive(-1,70,500);
rollerSet(90);
fourbarTarget = 320;
delay(200);
armTarget = 2460;
delay(400);
rollerSet(40);
armTarget = 2000;
delay(200);
fourbarTarget = 1920;
delay(300);

 gyroTurnPID(1,7,500,4,6);
autoDrive(1,1430,2000);//1500
gyroTurnPID(1,45,550,3,6);//first turn

autoDrive(1,560,1100);//drive AlONG 10 point pipe
gyroTurnPID(1,84,650,3,6);//78 squareup with pipe
armTarget = 2280;
delay(100);
rollerSet(-90);
delay(100);
armTarget = 1900;
autoDrive(-1,500,1000);// drive inside zone
driveSet(-30,30);
delay(100);
mgTarget = 3000;
delay(1200);
mgTarget = 2000;
rollerSet(0);
autoDrive(1,350,800);//back back out of the shit

//secondo mobile goal
gyroTurnPID(1,91,1000,3,6);//78 squareup with pipe
autoDrive(1,260,1700);//drive AlONG 10 point pipe
gyroTurnPID(1,91,1000,3,6);//78 squareup with pipe
autoDrive(1,110,1100);//SQUAREUP
mgTarget = 3000;
delay(1200);
autoDrive(-1,600,1100);//pickup mg
delay(100);

mgTarget = 1190;//mg back in
delay(1200);

autoDrive(1,200,2000);
delay(200);
gyroTurnPID(1,190,1500,3,6);//180 turn
delay(200);

autoDrive(-1,30,2000);//scoring mg
mgTarget = 3000;
delay(1200);
autoDrive(1,90,2000);
mgTarget=1190;
delay(700);

gyroTurnPID(-1,192,1500,3,6);//78 squareup with pipe

delay(300);
mgTarget = 3000;
delay(1000);
autoDrive(-1,1635,4000);
delay(100);
mgTarget = 1190;
delay(1200);
autoDrive(-1,700,700);

gyroTurnPID(-1,91,1000,3,6);//78 squareup with pipe
autoDrive(-1,450,1500);

gyroTurnPID(1,91,1000,3,6);//78 squareup with pipe
autoDrive(-1,500,1500);
mgTarget = 3000;
delay(1300);

autoDrive(-1,90,200);
autoDrive(1,70,200);//jiggle drive to push mg further inside
mgTarget = 1190;
delay(1100);
autoDrive(1,230,2000);//drive out of the shit

//SECOND SET

gyroTurnPID(1,91,1000,3,6);//78 squareup with pipe
autoDrive(1,275,1700);//drive AlONG 10 point pipe
gyroTurnPID(1,91,1000,3,6);//78 squareup with pipe
autoDrive(1,110,1100);//SQUAREUP
mgTarget = 3000;
delay(1200);
autoDrive(-1,500,1100);//pickup mg
delay(100);

mgTarget = 1190;//mg back in
delay(1200);

autoDrive(1,200,2000);
gyroTurnPID(1,188,1500,3,6);//180 turn

autoDrive(-1,30,2000);//scoring mg
mgTarget = 3000;
delay(1200);
autoDrive(1,90,2000);
mgTarget=1190;
delay(700);

gyroTurnPID(-1,189,1500,3,6);//78 squareup with pipe

delay(300);
mgTarget = 3000;
autoDrive(-1,1650,4000);
delay(100);
mgTarget = 1190;
delay(1200);
autoDrive(-1,700,700);

gyroTurnPID(-1,91,1000,3,6);//78 squareup with pipe
autoDrive(-1,450,1500);

gyroTurnPID(1,91,1000,3,6);//78 squareup with pipe
autoDrive(-1,200,1500);
mgTarget = 3000;
delay(1300);

autoDrive(-1,90,200);
autoDrive(1,70,200);//jiggle drive to push mg further inside
mgTarget = 1190;
delay(1100);
autoDrive(1,250,1600);//drive out of the shit

stop();

break;

case 5: //5 point right side
delay(30);
rollerSet(40);
fourbarTarget = 1920;
delay(20);
armTarget = 2100;
delay(200);
mgTarget = 3000;
delay(200);
autoDrive(-1,1100,2000);//1170
delay(100);
mgTarget = 1190;
delay(1100);
armTarget = 2370;
delay(100);
rollerSet(-90);
delay(180);
//second cone
armTarget = 2270;
autoDrive(-1,90,600);
rollerSet(90);
fourbarTarget = 320;
delay(100);
armTarget = 2460;//drop on cone
delay(400);
rollerSet(40);
armTarget = 2150;
delay(150);
fourbarTarget = 1820;
delay(400);
armTarget = 2360;
delay(200);
rollerSet(-90);
delay(200);
armTarget = 2100;
//third cone
autoDrive(-1,70,500);
rollerSet(90);
fourbarTarget = 320;
delay(200);
armTarget = 2460;
delay(400);
rollerSet(40);
armTarget = 2000;
delay(200);
fourbarTarget = 1920;
delay(300);

 gyroTurnPID(1,7,500,4,6);
autoDrive(1,900,2000);//1500
gyroTurnPID(1,180,550,3,6);//first turn

armTarget = 2280;
delay(100);
rollerSet(-90);
delay(100);
armTarget = 1900;
delay(300);
mgTarget = 3000;
delay(1200);
mgTarget = 2000;
rollerSet(0);
autoDrive(1,100,800);//back back out of the shit
gyroTurnPID(1,87,700,3,6);
autoDrive(-1,600,1000);

break;
}
  }
