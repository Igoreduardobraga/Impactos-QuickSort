#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "Registro.hpp"
#include "Metricas.hpp"

class HeapSort{
    private:
        Metricas metricas_HeapSort;
        
    public:
        void Constroi(Registro *A, int n);
        void Refaz(int Esq, int Dir, Registro *A);
};

#endif