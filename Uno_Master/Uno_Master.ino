#include <Wire.h>

#include <ControladorLeds.h>

#define _INICIO_         10
#define _FIM_            13
#define _DELAY_          2000

ControladorLeds leds (_INICIO_,_FIM_,_DELAY_);

int qtd;

void setup(){
  Wire.begin();
  for(int i = 2; i < 7; i++)
    pinMode(i, INPUT_PULLUP);
}

void loop(){
  int aux = 0;

  for(int i = 2; i < 6; i++){
    if (digitalRead(i) == LOW){
      if(digitalRead(i+8) == LOW){
        digitalWrite(i+8, HIGH);
        delay(300);
      }
      else{
        digitalWrite(i+8, LOW);
        delay(300);
      }
    }
  }

  if (digitalRead(6) == LOW){
    for(int i = 10; i < 14; i++){
      if(digitalRead(i) == HIGH)
        aux++;
    }
    
    
    if(qtd % 2 == 0)
      Wire.beginTransmission(2);
    else
      Wire.beginTransmission(1);
    Wire.write(aux);
    Wire.endTransmission();
    qtd++;
    delay(_DELAY_);
  }
  
  
}
