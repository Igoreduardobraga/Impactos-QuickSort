#ifndef REGISTRO_H
#define REGISTRO_H
#include <iostream>
#include "GeradorAleatorio.hpp"
using namespace std;

class Registro{
    private:
        string vetor_string[15];
        float vetor_reais[10];

    public:
        Registro();
        ~Registro() {}
        int key = 0;
};

#endif