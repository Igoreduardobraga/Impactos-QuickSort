#include "Registro.hpp"

Registro::Registro(){
    GeradorAleatorio gerar;
    for(int i=0 ; i<15 ; i++)
        if(i<10)
            vetor_reais[i] = gerar.numRealAleatorio();
        else
            vetor_string[i] = gerar.stringAleatoria();
}