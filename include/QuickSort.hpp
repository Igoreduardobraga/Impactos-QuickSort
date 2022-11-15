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
        Metricas metricas;

    public:
        QuickSort();

        //Metodos QuickSort Recursivo
        void QuickSort_Recursivo(Registro *A, int n);
        void Particao(int Esq, int Dir, int *i, int *j, Registro *A);
        void Ordena_Recursivo(int Esq, int Dir, Registro *A);

        //Metodos QuickSort Seleção
        void Selecao(Registro A[], int inicio, int fim);
        void QuickSort_Selecao(Registro A[], int n, int m);
        void Ordena_Selecao(Registro A[], int inicio, int fim, int m);
        int Particao_Selecao(Registro A[], int inicio, int fim);

        //Metodos QuickSort Mediana
        void QuickSort_Mediana(Registro A[], int fim, int k);
        void Ordena_Mediana(Registro A[], int inicio, int fim, int k);
        
        //Metodos QuickSort não recursivo
        void Troca(Registro* a, Registro* b);
        int Particao_naoRec(Registro A[], int inicio, int fim);
        void QuickSort_naoRec(Registro A[], int n);
        void Ordena_naoRec(Registro A[], int inicio, int fim);

        //Metodos QuickSort Empilha Inteligente

        void imprime_Metricas(int algoritmo, int semente, ofstream *saida, int i);
};

#endif