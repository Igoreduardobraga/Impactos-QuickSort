// Selection sort in C++

#include <iostream>
using namespace std;

// function to swap the the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Selecao(int A[], int inicio, int fim){
    int i, j, maximo_index;
 
    for (i = inicio; i <= fim ; i++){
        maximo_index = i;
        for (j = i+1; j <= fim; j++){
            if (A[j] < A[maximo_index]){
                
                maximo_index = j;
            }
        }

        swap(&A[i], &A[maximo_index]);
    }
}

int Particao_Selecao(int A[], int inicio, int fim){
    //Descricao:: Realiza a partição do algoritmo QuickSort Seleção

    int x = A[fim];
    
    int i = inicio;

    for (int j = inicio; j < fim ; j++) {
        if (A[j] <= x) {
            
            swap(&A[j], &A[i]);
            i++;
        }
    }
    swap(&A[i], &A[fim]);
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

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

// driver code
int main() {
  int data[] = {20, 12, 10, 15, 2, 231, 42, 2312, 432, 234, 124, -123, -2, -2424, -2321, 242232123};
  int size = sizeof(data) / sizeof(data[0]);
  QuickSort_Selecao(data, size,10);
  cout << "Sorted array in Acsending Order:\n";
  printArray(data, size);
}