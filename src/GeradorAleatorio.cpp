#include "GeradorAleatorio.hpp"

string GeradorAleatorio::stringAleatoria(){
    //Descricao: Gera uma string aleatoria de 200 caracteres
    
    string temp;

    for(int i=0 ; i<200 ; ++i){
        temp += 'a' + (char)(rand()%26);
    }
    return temp;
}

int GeradorAleatorio::numAleatorio(){
    return rand();
}

double GeradorAleatorio::numRealAleatorio(){
    return rand()*1000.0/RAND_MAX;
}