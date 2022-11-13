#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "Registro.hpp"

class HeapSort{
    private:
        
    public:
        void Constroi(Registro *A, int n);
        void Refaz(int Esq, int Dir, Registro *A);
};

#endif