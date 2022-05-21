#ifndef _CONTROLADOR_LEDS_H_
#define _CONTROLADOR_LEDS_H_

bool Par(int n){
    return n % 2 == 0 ? 1 : 0;
}

class ControladorLeds{
    private:
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
};

#endif