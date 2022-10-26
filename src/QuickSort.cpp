#include "QuickSort.hpp"

QuickSort::QuickSort() {

}

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

void Ordena(int Esq, int Dir, int *A){ 
    int i, j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j) Ordena(Esq, j, A);
    if (i < Dir) Ordena(i, Dir, A);
}

void QuickSort::Chama_QuickSort(int *A, int n){
    Ordena(0, n-1, A);
}

void QuickSort::Print() {
    printf("QuickSort\n");
}