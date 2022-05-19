#ifndef _CONTROLADOR_LEDS_H_
#define _CONTROLADOR_LEDS_H_

#include <Arduino.h>

class ControladorLeds{
    private:
        int inicio, fim, meio, tempoEspera;
    public:
        ControladorLeds(int start, int end, int d){
            inicio = start;
            fim = end;
            meio = ((end-start) / 2) + start;
            tempoEspera = d;
            IniciarPinos();
        }
        void IniciarPinos();
        void Acender(int funcao);
};

void ControladorLeds::IniciarPinos(){
    for(int i = inicio; i < fim + 1; i++)
        pinMode(i,OUTPUT);
}

void ControladorLeds::Acender(int funcao){
    int i;
    //1 - Inicio -> Meio
    //2 - Inicio <- Meio
    //3 - Meio -> Fim
    //4 - Meio <- Fim
    switch (funcao)
    {
    case 1:
        for(i = inicio; i < meio + 1; i++){
            if(i == inicio)
                digitalWrite(i,HIGH);
            else{
                digitalWrite(i-1,LOW);
                digitalWrite(i,HIGH);
            }
            delay(tempoEspera);      
        }   
        digitalWrite(i-1,LOW);
        break;
    case 2:
        for(i = meio; i > inicio - 1; i--){
            if(i == meio)
                digitalWrite(i,HIGH);
            else{
                digitalWrite(i+1,LOW);
                digitalWrite(i,HIGH);
            }
            delay(tempoEspera);      
        }   
        digitalWrite(i+1,LOW);
        break;
    case 3:
        for(i = meio; i < fim + 1; i++){
            if(i == meio)
                digitalWrite(i,HIGH);
            else{
                digitalWrite(i-1,LOW);
                digitalWrite(i,HIGH);
            }
            delay(tempoEspera);      
        } 
        digitalWrite(i-1,LOW);
        break;
    case 4:
        for(i = fim; i > meio - 1; i--){
            if(i == fim)
                digitalWrite(i,HIGH);
            else{
                digitalWrite(i+1,LOW);
                digitalWrite(i,HIGH);
            }
            delay(tempoEspera);      
        }
        digitalWrite(i+1,LOW);
        break;
    default:
        break;
    }
}
#endif