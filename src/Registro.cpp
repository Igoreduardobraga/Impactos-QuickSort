#include "Registro.hpp"

Registro::Registro(){
     //Descricao: Preenche os componentes de cada registro(vetores de numeros reais e strings) 

    GeradorAleatorio gerar;
    for(int i=0 ; i<15 ; i++){
        if(i<10)
            vetor_reais[i] = gerar.numRealAleatorio();
        vetor_string[i] = gerar.stringAleatoria();
    }
}