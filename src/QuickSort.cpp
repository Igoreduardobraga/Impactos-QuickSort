#include "QuickSort.hpp"
#include "Pilha.hpp"
#include "TipoItem.hpp"

QuickSort::QuickSort() { }

//************************************QUICKSORT RECURSIVO******************************************//

void Particao(int Esq, int Dir, int *i, int *j, int *A) {
    int x, w;
    *i = Esq; *j = Dir;
    x = A[(*i + *j)/2]; /* obtem o pivo x */
    do
    {
        while (x > A[*i]) (*i)++;
        while (x < A[*j]) (*j)--;
        if (*i <= *j)
        {
            w = A[*i]; A[*i] = A[*j]; A[*j] = w;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void Ordena_Recursivo(int Esq, int Dir, int *A){ 
    int i, j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j) Ordena_Recursivo(Esq, j, A);
    if (i < Dir) Ordena_Recursivo(i, Dir, A);
}

void QuickSort::Chama_QuickSort_Recursivo(int inicio, int *A, int n){
    Ordena_Recursivo(0, n-1, A);
}

//************************************QUICKSORT MEDIANA******************************************//

//função auxiliar para realizar as trocas de elementos
void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Particao_Mediana(int A[], int inicio, int fim) {
    //procura a mediana entre inicio, meio e fim
    int meio = (inicio + fim) / 2;
    int a = A[inicio];
    int b = A[meio];
    int c = A[fim];
    int medianaIndice; //índice da mediana
    //A sequência de if...else a seguir verifica qual é a mediana
    if (a < b) {
        if (b < c) {
            //a < b && b < c
            medianaIndice = meio;
        } else {
            if (a < c) {
                //a < c && c <= b
                medianaIndice = fim;
            } else {
                //c <= a && a < b
                medianaIndice = inicio;
            }
        }
    } else {
        if (c < b) {
            //c < b && b <= a
            medianaIndice = meio;
        } else {
            if (c < a) {
                //b <= c && c < a
                medianaIndice = fim;
            } else {
                //b <= a && a <= c
                medianaIndice = inicio;
            }
        }
    }
    //coloca o elemento da mediana no fim para poder usar o Quicksort de Cormen
    swap(A, medianaIndice, fim);

    int pivo = A[fim];
    int i = inicio - 1;
    int j;
    /*
     * Este laço irá varrer os vetores da esquerda para direira
     * procurando os elementos que são menores ou iguais ao pivô.
     * Esses elementos são colocados na partição esquerda.         
     */
    for (j = inicio; j <= fim - 1; j++) {
        if (A[j] <= pivo) {
            i = i + 1;
            swap(A, i, j);
        }
    }
    //coloca o pivô na posição de ordenação
    swap(A, i + 1, fim);
    return i + 1; //retorna a posição do pivô
}

void QuickSort::Chama_QuickSort_Mediana(int inicio, int A[], int fim) {
    if (inicio < fim) {
        //realiza a partição
        int q = Particao_Mediana(A, inicio, fim);
        //ordena a partição esquerda
        Chama_QuickSort_Mediana(inicio, A, q - 1);
        //ordena a partição direita
        Chama_QuickSort_Mediana(q + 1, A, fim);
    }
}

//************************************QUICKSORT NAO RECURSIVO******************************************//

void QuickSort::QuickSortNaoRec(int A, int n){
    Pilha pilha;
    TipoItem item; // campos esq e dir
    int esq, dir, i, j;
    FPVazia(&pilha);
    esq = 0;
    dir = n-1;
    item.dir = dir;
    item.esq = esq;
    Empilha(item, &pilha);

    do{
        if (dir > esq) {
        Particao(esq,dir,&i,&j,A);
            if ((j-esq)>(dir-i)) {
                item.dir = j;
                item.esq = esq;
                Empilha(item, &pilha);
                esq = i;
            }
            else {
                item.esq = i;
                item.dir = dir;
                Empilha(item, &pilha);
                dir = j;
            }
        }
        else{
            Desempilha(&pilha,&item);
            dir = item.dir;
            esq = item.esq;
        }
    } while(!Vazia(pilha));
}