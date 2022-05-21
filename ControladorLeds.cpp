#include <Arduino.h>

#include "ControladorLeds.h"

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
    //5 - Inicio -> Fim
    //6 - Inicio <- Fim
    switch (funcao){
    case 1:
        if(naoPar)
            meio--;
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
        if(naoPar)
            meio++;
        break;
    case 2:
        if(naoPar)
            meio--;
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
        if(naoPar)
            meio++;
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
    case 5:
        for(i = inicio; i < fim + 1; i++){
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
    case 6:
        for(i = fim; i > inicio - 1; i--){
            if(i == fim)
                digitalWrite(i,HIGH);
            else{
                digitalWrite(i+1,LOW);
                digitalWrite(i,HIGH);
            }
            delay(tempoEspera);      
        }
        digitalWrite(i+1,LOW);
    default:
        break;
    }
}