#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdio.h>
#include <iostream>
using namespace std;

class QuickSort{
    public:
        QuickSort(int n);
        void Chama_QuickSort_Recursivo(int inicio, int *A, int n);
        void Print();
        void QuickSortNaoRec(int A, int n);
        void Chama_QuickSort_Mediana(int inicio, int A[], int fim);
};

#endif