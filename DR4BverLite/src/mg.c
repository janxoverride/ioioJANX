#include "main.h"
#include "mg.h"

void mgSet(int power){
  motorSet(mg,-power);
  if(power > 90){power = 90;}
  if(power < -90){power = -90;}
}
