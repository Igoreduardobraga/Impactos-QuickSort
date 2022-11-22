#include "MergeSort.hpp"

void MergeSort::merge(Registro A[], int const esq, int const x, int const Dir){
    //Descricao: realiza a ordenacao do vetor pelo algoritmo mergesort

    int subVetorUm = x - esq + 1;
    int subVetorDois = Dir - x;
    metricas.Atribuicoes+=2;
 
    Registro *esqVetor = new Registro[subVetorUm], *DirVetor = new Registro[subVetorDois];
 
    for (int i = 0; i < subVetorUm; i++){
        esqVetor[i] = A[esq + i];
        metricas.Atribuicoes++;
    }
    for (int j = 0; j < subVetorDois; j++){
        DirVetor[j] = A[x + 1 + j];
        metricas.Atribuicoes++;
    }
 
    int index_subVetorUm = 0, index_subVetorDois = 0; 
    int indexOfMergedVetor = esq; 

    while (index_subVetorUm < subVetorUm && index_subVetorDois < subVetorDois) {
        if (esqVetor[index_subVetorUm].key <= DirVetor[index_subVetorDois].key) {
            metricas.Comparacoes++;
            A[indexOfMergedVetor] = esqVetor[index_subVetorUm];
            metricas.Atribuicoes++;
            index_subVetorUm++;
        }
        else {
            A[indexOfMergedVetor] = DirVetor[index_subVetorDois];
            index_subVetorDois++;
        }
        indexOfMergedVetor++;
    }
    
    while (index_subVetorUm < subVetorUm) {
        A[indexOfMergedVetor] = esqVetor[index_subVetorUm];
        metricas.Atribuicoes++;
        index_subVetorUm++;
        indexOfMergedVetor++;
    }
    
    while (index_subVetorDois < subVetorDois) {
        A[indexOfMergedVetor] = DirVetor[index_subVetorDois];
        metricas.Atribuicoes++;
        index_subVetorDois++;
        indexOfMergedVetor++;
    }
    delete[] esqVetor;
    delete[] DirVetor;
}

void MergeSort::mergeSort(Registro A[], int const inicio, int const fim){
    //Descricao: Chamada do algoritmo Mergesort

    //Inicializando as metricas
    metricas.Atribuicoes=0;
    metricas.Comparacoes=0;

    if (inicio >= fim)
        return;
 
    auto x = inicio + (fim - inicio) / 2;
    mergeSort(A, inicio, x);
    mergeSort(A, x + 1, fim);
    merge(A, inicio, x, fim);
}

void MergeSort::imprimir_metricas(ofstream *saida, int semente, int n) {
    //Descricao: Imprime as metricas do Mergesort

    *saida << "MergeSort (" << n << ") - semente [" << semente << "]:" << endl;
    *saida << "Numero de comparacoes: " << metricas.Comparacoes << endl;
    *saida << "Numero de atribuicoes: " << metricas.Atribuicoes << endl;
}