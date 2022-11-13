#include "HeapSort.hpp"

void HeapSort::Constroi(Registro *A, int n) {
    int Esq;
    Esq = n / 2 + 1;
    while (Esq > 1) {
        Esq--;
        Refaz(Esq, n, A);
    }
}

void HeapSort::Refaz(int Esq, int Dir, Registro *A){
    int i, j;
    Registro x;
    i = Esq;
    j = i * 2;
    x = A[i];
    while (j <= Dir){
        if (j < Dir)
        if (A[j].key < A[j+1].key) j++;
        if (x.key >= A[j].key) break;
        A[i] = A[j];
        i = j;
        j = i *2;
    }
    A[i] = x;
}

