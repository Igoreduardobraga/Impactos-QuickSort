#ifndef GERADOR_ALEATORIO
#define GERADOR_ALEATORIO
using namespace std;
#include <stdlib.h>
#include <iostream>

class GeradorAleatorio{
    public:
        GeradorAleatorio() { };
        string stringAleatoria();
        int numAleatorio();
        double numRealAleatorio();
};

#endif