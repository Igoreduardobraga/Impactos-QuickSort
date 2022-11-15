#ifndef MERGESORT_H
#define MERGESORT_H

using namespace std;
#include "Metricas.hpp"
#include <iostream>
#include <fstream>

class MergeSort{
    private:
        Metricas metricas_MergeSort;

    public:
        MergeSort();
        void merge(int arr[], int p, int q, int r);
        void mergeSort(int arr[], int l, int r);
        void imprimir_metricas(ofstream *saida, int n); 
};

#endif