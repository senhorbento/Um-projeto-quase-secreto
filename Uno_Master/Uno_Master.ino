#include <Wire.h>

#include <ControladorLeds.h>

#define _INICIO_         10
#define _FIM_            13
#define _DELAY_          3600

void VaiVem(int linha){
    Wire.beginTransmission(linha);
    Wire.write(2);
    Wire.endTransmission();
    delay(_DELAY_);  
    Wire.beginTransmission(2);
    Wire.write(3);
    Wire.endTransmission();
    delay(_DELAY_);
}

void setup(){
  Wire.begin();
  for(int i = 2; i < 7; i++)
    pinMode(i, INPUT_PULLUP);
}

void loop(){
    for(int i = 0; i < 5 ; i++)
        VaiVem(i);
}
