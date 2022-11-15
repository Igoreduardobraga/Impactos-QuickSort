#include <iostream>
using namespace std;

void Troca(int* a, int* b){
    //Descricao:: Realiza a troca de posição

    int t = *a;
    *a = *b;
    *b = t;
}

//************************************QUICKSORT RECURSIVO******************************************//

int Particao_naoRec(int A[], int inicio, int fim){
    //Descricao: Particiona 
    int x = A[fim];
    
    int indice_naoRec = (inicio - 1);
 
    for (int j = inicio ; j <= fim - 1; j++) {
        if (A[j] <= x) {
            
            indice_naoRec++;
            Troca(&A[indice_naoRec], &A[j]);
        }
    }
    Troca(&A[indice_naoRec + 1], &A[fim]);
    return (indice_naoRec + 1);
}

void Ordena_naoRec(int A[], int inicio, int fim){
    //Descricao: Implementacao do Algoritmo QuickSortNaoRecursivo

    //Criando pilha dinamicamente
    int *pilha = new int[fim-inicio+1];
 
    //Inicializando o topo da pilha
    int topo_pilha = -1;
 
    // push initial values of l and h to pilha
    pilha[++topo_pilha] = inicio;
    

    pilha[++topo_pilha] = fim;
    
 
    // Keep popping from pilha while is not empty
    while (topo_pilha >= 0) {
        
        // Pop h and l
        fim = pilha[topo_pilha--];
        inicio = pilha[topo_pilha--];
 
        // Set pivot element at its correct position
        // in sorted array
        int particao = Particao_naoRec(A, inicio, fim);
 
        // If there are elements on left side of pivot,
        // then push left side to pilha
        if (particao - 1 > inicio) {
            
            pilha[++topo_pilha] = inicio;
            pilha[++topo_pilha] = particao - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to pilha
        if (particao + 1 < fim) {
            
            pilha[++topo_pilha] = particao + 1;
            pilha[++topo_pilha] = fim;
        }
    }
    delete [] pilha;
}

void QuickSort_naoRec(int A[], int n){
    //Descrição: Chamada do algoritmo QuickSort não Recursivo

    //Inicializa as comparacoes e atribuicoes

    Ordena_naoRec(A,0,n-1);
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[20];

    for(int i=0; i<20 ; i++){
        arr[i] = rand()%100;
        cout << arr[i] << " ";
    }
    cout << endl;

    QuickSort_naoRec(arr, 20);
    cout << "Sorted array: \n";
    printArray(arr, 20);
    return 0;
}