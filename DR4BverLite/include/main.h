#ifndef MAIN_H_
#define MAIN_H_

#include <API.h>
#ifdef __cplusplus
extern "C" {
#endif

#define DriveBR 1
  #define DriveBR_Dir -1

#define DriveFL 2
  #define DriveFL_Dir -1

#define liftTL 3

#define rollers 4

#define fourBar 5

#define liftB 6


#define mg 7

#define liftTR 8


#define DriveFR 9
  #define DriveFR_Dir -1

#define DriveBL 10
  #define DriveBL_Dir -1

#define dirL 1
#define dirR 1

#define mgPot 1
#define fourPot 2
#define liftPot 3

Encoder encoderL;
Encoder encoderR;
Gyro gyro;

int myauto;
int stackglobal;
int armTarget;
int fourbarTarget;
int mgTarget;

void autonomous();
void initializeIO();
void initialize();
void operatorControl();
#ifdef __cplusplus
}
#endif

#endif
