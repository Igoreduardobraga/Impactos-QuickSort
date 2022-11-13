#include "HeapSort.hpp"

void HeapSort::Constroi(Registro *A, int n) {
    int Esq;
    Esq = n / 2 + 1;
    while (Esq > 1) {
        metricas_HeapSort.Comparacoes++;
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
        metricas_HeapSort.Comparacoes++;
        if (j < Dir){
            metricas_HeapSort.Comparacoes++;
            if (A[j].key < A[j+1].key) {
                metricas_HeapSort.Comparacoes++;
                j++;
        }
        }
        if (x.key >= A[j].key){
            metricas_HeapSort.Comparacoes++;
            break;
        }
        A[i] = A[j];
        i = j;
        j = i *2;
        metricas_HeapSort.Atribuicoes+=3;
    }
    A[i] = x;
    metricas_HeapSort.Atribuicoes++;
}

