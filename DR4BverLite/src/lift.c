#include "main.h"
#include "lift.h"

void liftSet(int power){
  motorSet(liftTL,power);
  motorSet(liftTR,power);
  motorSet(liftB, -power);
  if(power < -90){power = -90;}
  if(power > 90){power = -90;}
}
