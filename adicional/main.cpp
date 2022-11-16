#include <iostream>
#include <sys/resource.h>
using namespace std;

void Troca(int* a, int* b){
    //Descricao: Realiza a troca de posição

    int t = *a;
    *a = *b;
    *b = t;
}

//************************************QUICKSORT RECURSIVO******************************************//

void Selecao(int A[], int inicio, int fim){

    for (int step = 0; step < fim - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < fim; i++) {
            if (A[i] < A[min_idx])
                min_idx = i;
    }

    // put min at the correct position
    Troca(&A[min_idx], &A[step]);
    }
}

int Particao_Selecao(int A[], int inicio, int fim){
    //Descricao: Realiza a partição do algoritmo QuickSort Seleção

    int x = A[fim];
    int i = inicio;

    for (int j = inicio; j < fim ; j++) {
        if (A[j] <= x) {
        
            Troca(&A[i], &A[j]);
            i++;
        }
    }

    Troca(&A[i], &A[fim]);
    return i;
}

void Ordena_Selecao(int A[], int inicio, int fim, int m){
    int diferenca = fim-inicio;
    while(inicio < fim) {
        if (diferenca < m) {
            Selecao(A, inicio, fim);
            break;
        }
        else {
            int x = Particao_Selecao(A, inicio, fim);

            if (x-inicio < fim-x) {
                Ordena_Selecao(A, inicio, x-1, m);
                inicio = x+1;
            }
            else {
                Ordena_Selecao(A, x+1, fim, m);
                fim = x-1;
            }
        }
    }
}

void QuickSort_Selecao(int A[], int n, int m){

    Ordena_Selecao(A, 0, n-1, m);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){

    struct rusage resources;
    int rc;
    double utime, stime, total_time;
    int arr[20];

    if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
            perror("getrusage falhou");

    for(int i=0; i<20 ; i++){
        arr[i] = rand()%100;
        cout << arr[i] << " ";
    }
    cout << endl;

    QuickSort_Selecao(arr, 20, 10);

    utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
    stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
    total_time = utime+stime;

    cout << "Sorted array: \n";
    printArray(arr, 20);
    cout << "Tempo de processamento : " << total_time << endl;

    
    return 0;
}