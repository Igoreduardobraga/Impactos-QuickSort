#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "Registro.hpp"
#include "Metricas.hpp"
#include <fstream>
using namespace std;

class HeapSort{
    private:
        Metricas metricas;
        
    public:
        HeapSort(){}
        void Troca(Registro *a, Registro *b);
        void Refaz(Registro A[], int n, int i);
        void heapSort(Registro A[], int n);
        void imprimir_metricas(ofstream *saida, int semente, int n);
};

#endif