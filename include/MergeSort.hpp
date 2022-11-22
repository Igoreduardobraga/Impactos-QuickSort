#ifndef MERGESORT_H
#define MERGESORT_H

using namespace std;
#include "Metricas.hpp"
#include "Registro.hpp"
#include <iostream>
#include <fstream>

class MergeSort{
    private:
        Metricas metricas;

    public:
        MergeSort(){}
        void merge(Registro A[], int const esq, int const mid, int const right);
        void mergeSort(Registro A[], int const begin, int const end);
        void imprimir_metricas(ofstream *saida, int semente, int n); 
};

#endif