#include <NetworkMEGA.h>
#include <ControladorLeds.h>

#define _ENDERECO_LOCAL_ 1
#define _INICIO_         50
#define _FIM_            53
#define _DELAY_          1000

#define _MAX_BUFFER_ 10

NetworkMEGA network;
ControladorLeds *leds = new ControladorLeds(_INICIO_,_FIM_,_DELAY_);

char message[12];
int i = 0;

void setup(){
  network.IniciarComunicacao();
  network.SetEnderecoLocal(_ENDERECO_LOCAL_);
}

void loop(){
  while (Serial.available()){
      char inBuffer = Serial.read();
      if (inBuffer != '*' && (i < _MAX_BUFFER_ - 1)){
          message[i] = inBuffer;
          i++;
      }
      else{
          char remetente[2]{message[0],'\0'};
          char destinario[2]{message[1],'\0'};
          char mensagemRecebida[2]{message[2],'\0'};
          network.EscreverMensagem(atoi(remetente),atoi(destinario),atoi(mensagemRecebida),0);
          if(network.ReceberMensagem())
            leds->Acender(network.GetMensagem());
          i = 0;
      }
  }
}
