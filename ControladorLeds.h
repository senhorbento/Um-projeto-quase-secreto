#ifndef _CONTROLADOR_LEDS_H_
#define _CONTROLADOR_LEDS_H_

class ControladorLeds{
    protected:
        int inicio, fim, meio, tempoEspera;
        bool naoPar;
    public:
        ControladorLeds(int start, int end, int d){
            naoPar = 0;
            tempoEspera = d;

            inicio = start;
            fim = end;

            meio = end-start;
            if(Par(meio))
                meio = (meio/2) + start;
            else{
                naoPar = 1; 
                meio = ((meio+1)/2) + start;
            }

            IniciarPinos(); 
        }
        void IniciarPinos();
        void Acender(int funcao);
	    bool Par(int n);
};

bool ControladorLeds :: Par(int n){
    return n % 2 == 0 ? 1 : 0;
}

void ControladorLeds :: IniciarPinos(){
    for(int i = inicio; i < fim + 1; i++)
        pinMode(i,OUTPUT);
}

void ControladorLeds :: Acender(int funcao){
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

#endif