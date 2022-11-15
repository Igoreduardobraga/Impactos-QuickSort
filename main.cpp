#include <iostream>
using namespace std;

void Troca(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void Selecao(int A[], int inicio, int fim){
    int i, j, maximo_index;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = inicio; i < fim ; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        maximo_index = i;
        for (j = i+1; j < fim; j++)
            if (A[j] < A[maximo_index])
                maximo_index = j;
 
        // Swap the found minimum element
        // with the first element
        if(maximo_index!=i)
            Troca(&A[maximo_index], &A[i]);
    }
}

int Particao_Selecao(int A[], int inicio, int fim){
    int x = A[fim];
    int i = inicio;

    for (int j = inicio; j <= fim - 1; j++) {
        if (A[j] <= x) {
            Troca(&A[i], &A[j]);
            i++;
        }
    }
    Troca(&A[i], &A[fim]);
    return i;
}

void QuickSort_Selecao(int A[], int inicio, int fim, int m){
    int diferenca = fim-inicio;
    while(inicio < fim) {
        if (diferenca < m) {
            Selecao(A, inicio, fim);
            break;
        }
        else {
            int x = Particao_Selecao(A, inicio, fim);

            if (x-inicio < fim-x) {
                QuickSort_Selecao(A, inicio, x-1, m);
                inicio = x+1;
            }
            else {
                QuickSort_Selecao(A, x+1, fim, m);
                fim = x-1;
            }
        }
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    QuickSort_Selecao(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}