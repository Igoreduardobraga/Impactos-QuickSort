#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdio.h>
#include <iostream>
using namespace std;

class QuickSort{
    private:
        string nome_quick;
    public:
        QuickSort(string nome_quick);
        void Chama_QuickSort(int inicio, int *A, int n);
        void Print();
};

#endif