#include "GeradorAleatorio.hpp"

string GeradorAleatorio::stringAleatoria(){
    //Descricao: Gera uma string aleatoria de 200 caracteres
    static const char letras_numeros[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string temp;
    temp.reserve(200);

    for(int i=0 ; i<200 ; ++i){
        temp += letras_numeros[rand()%(sizeof(letras_numeros)-1)];
    }
    return temp;
}

int GeradorAleatorio::numAleatorio(){
    return rand();
}

double GeradorAleatorio::numRealAleatorio(){
    float min = 0;
    float max =  1000;
    float f = min + rand() * (max - min) / RAND_MAX;
    return f;
}