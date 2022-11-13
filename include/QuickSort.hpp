#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Metricas.hpp"
#include "Registro.hpp"
#include "TipoItem.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;

class QuickSort{
    private:
        //Metricas do algoritmo QuickSort recursivo
        Metricas metricas_QSR;
        //Metricas do algoritmo QuickSort mediana
        Metricas metricas_QSM;
        //Metricas do algoritmo QuickSort selecao
        Metricas metricas_QSS;
        //Metricas do algoritmo QuickSort nao recursivo
        Metricas metricas_QSNR;
        //Metricas do algoritmo QuickSort empilha inteligente
        Metricas metricas_QSEI;

    public:
        QuickSort();
        //QuickSort(int n);

        void Chama_QuickSort_Recursivo(int inicio, Registro *A, int n);
        void Particao(int Esq, int Dir, int *i, int *j, Registro *A);
        void Ordena_Recursivo(int Esq, int Dir, Registro *A);

        void swap(Registro A[], int i, int j);
        int Particao_Mediana(Registro A[], int inicio, int fim);
        void Chama_QuickSort_Mediana(int inicio, Registro A[], int fim);

        void swap_naoRec(Registro* a, Registro* b);
        int partition_naoRec(Registro A[], int inicio, int fim);
        void QuickSortNaoRec(Registro *A, int inicio, int fim);

        void imprime_Metricas(int algoritmo, ofstream *saida, int i);
};

#endif