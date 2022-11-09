#include "HeapSort.hpp"

void HeapSort::Constroi(Item *A, int n) {
    int Esq;
    Esq = n / 2 + 1;
    while (Esq > 1) {
        Esq--;
        Refaz(Esq, n, A);
    }
}

void HeapSort::Refaz(int Esq, int Dir, Item *A){
    int i, j;
    Item x;
    i = Esq;
    j = i * 2;
    x = A[i];
    while (j <= Dir){
        if (j < Dir)
        if (A[j].Chave < A[j+1].Chave) j++;
        if (x.Chave >= A[j].Chave) break;
        A[i] = A[j];
        i = j;
        j = i *2;
    }
    A[i] = x;
}

