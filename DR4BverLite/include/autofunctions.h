#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_
#include "main.h"

void autoDrive(int direction, int target, int timeout);

void gyroTurnPID(int direction, int targetTurn, int timeout, float kp, float kd);

void mobileGoal(int direction, int target);

void mgTask(void*parameter);
TaskHandle mgTaskHandle;

void lift(int direction, int target, int power);

void armTask(void*parameter);
TaskHandle armTaskHandle;

void fourbar(int direction, int target);

void fourbarTask(void*parameter);
TaskHandle fourbarTaskHandle;

void autoStack(void*parameter);
TaskHandle autoStackHandle;

void fourAUp();

void fourADown();

void stop();
#endif
