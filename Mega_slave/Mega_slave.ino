#include <Wire.h>

#include <ControladorLeds.h>

#define _ENDERECO_LOCAL_ 1
#define _INICIO_         50
#define _FIM_            53
#define _DELAY_          1000

ControladorLeds *leds = new ControladorLeds(_INICIO_,_FIM_,_DELAY_);

int mensagemRecebida = 0;

void setup(){
  Wire.begin(_ENDERECO_LOCAL_);
 	Wire.onReceive(receptor);
}

void loop(){
  if(mensagemRecebida > 0){
    leds->Acender(mensagemRecebida);
    mensagemRecebida = 0;
  }
}

void receptor(int qtd){
	if (Wire.available()){
      mensagemRecebida = Wire.read();
      Serial.println(mensagemRecebida); 
  }
}
