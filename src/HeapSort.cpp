#include "HeapSort.hpp"

void HeapSort::Troca(Registro *a, Registro *b){
    //Descricao:: Troca dois elementos de posição

    Registro temp = *a;
    *a = *b;
    *b = temp;
    metricas.Atribuicoes+=3;
}

void HeapSort::Refaz(Registro A[], int n, int i){
    //Descicao: Refaz a condiçao do heap

    int maior = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < n && A[l].key > A[maior].key){
        metricas.Comparacoes++;
        maior = l;
    }
 
    if (r < n && A[r].key > A[maior].key){
        metricas.Comparacoes++;
        maior = r;
    }
 
    if (maior != i) {
        Troca(&A[i], &A[maior]);
 
        Refaz(A, n, maior);
    }
}

void HeapSort::heapSort(Registro A[], int n){
    //Descricao: Chamada do algoritmo HeapSort

    //Inicializando as metricas
    metricas.Atribuicoes=0;
    metricas.Comparacoes=0;
    
    for (int i = n / 2 - 1; i >= 0; i--)
        Refaz(A, n, i);
 
    
    for (int i = n - 1; i >= 0; i--) {
        Troca(&A[0], &A[i]);
        Refaz(A, i, 0);
    }
}

void HeapSort::imprimir_metricas(ofstream *saida, int semente, int n) {
    //Descricao: Imprime as métricas do algoritmo HeapSort

    *saida << "HeapSort (" << n << ") - semente [" << semente << "]:" << endl;
    *saida << "Numero de comparacoes: " << metricas.Comparacoes << endl;
    *saida << "Numero de atribuicoes: " << metricas.Atribuicoes << endl;
}