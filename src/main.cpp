#include "Network.h"

#include "ControladorLeds.h"

#define _ENDERECO_LOCAL_ 0
#define _INICIO_         22
#define _FIM_            46
#define _DELAY_          100

Network network;
ControladorLeds *leds = new ControladorLeds(_INICIO_,_FIM_,_DELAY_);

void setup(){
  network.IniciarComunicacao();
  network.SetEndereco(_ENDERECO_LOCAL_);
}

void loop(){
  leds->Acender(1);
  delay(2000);
  leds->Acender(2);
  delay(2000);
  leds->Acender(3);
  delay(2000);
  leds->Acender(4);
  delay(2000);
}