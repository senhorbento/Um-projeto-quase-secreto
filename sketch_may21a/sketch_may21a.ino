#include <NetworkUNO.h>
#include <ControladorLeds.h>

#define _ENDERECO_LOCAL_ 0
#define _INICIO_         10
#define _FIM_            13
#define _DELAY_          1000

NetworkUNO network;
ControladorLeds leds (_INICIO_,_FIM_,_DELAY_);

void setup(){
  network.IniciarComunicacao();
  network.SetEnderecoLocal(_ENDERECO_LOCAL_);
  for(int i = 2; i < 7; i++)
    pinMode(i, INPUT_PULLUP);
}
int qtd = 1;
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
      network.EscreverMensagem(_ENDERECO_LOCAL_, 2, aux,0);
    else
      network.EscreverMensagem(_ENDERECO_LOCAL_, 1, aux,0);
    network.EnviarMensagem();
    qtd++;
    delay(_DELAY_);
  }
  
}
