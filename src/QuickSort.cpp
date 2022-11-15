#include "QuickSort.hpp"
#include <fstream>

QuickSort::QuickSort(){  }

void QuickSort::Troca(Registro* a, Registro* b){
    //Descricao:: Realiza a troca de posição

    Registro t = *a;
    *a = *b;
    *b = t;
    metricas.Atribuicoes+=3;
}

//************************************QUICKSORT RECURSIVO******************************************//

void QuickSort::Particao(int Esq, int Dir, int *i, int *j, Registro *A) {
    //Descricao:: Realiza a partição do algoritmo QuickSort Recursivo

    Registro x, w;
    *i = Esq; *j = Dir;
    x = A[(*i + *j)/2]; /* obtem o pivo x */
    do
    {
        metricas.Comparacoes++;
        while (x.key > A[*i].key){
            (*i)++;
            metricas.Comparacoes++;
        }
        while (x.key < A[*j].key){
            (*j)--;
            metricas.Comparacoes++;
        }
        if (*i <= *j)
        {
            metricas.Comparacoes++;
            w = A[*i]; A[*i] = A[*j]; A[*j] = w;
            metricas.Atribuicoes+=3;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void QuickSort::Ordena_Recursivo(int Esq, int Dir, Registro *A){ 
    int i, j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j){
        Ordena_Recursivo(Esq, j, A);
        metricas.Comparacoes++;
    }
    if (i < Dir) {
        Ordena_Recursivo(i, Dir, A);
        metricas.Comparacoes++;
    }
}

void QuickSort::QuickSort_Recursivo(Registro *A, int n){
    //Descricao: Chamada do algoritmo QuickSort Recursivo

    //Inicializa as comparacoes e atribuicoes
    metricas.Comparacoes=0;
    metricas.Atribuicoes=0;
    Ordena_Recursivo(0, n-1, A);
}

//************************************QUICKSORT SELEÇÃO******************************************

void QuickSort::Selecao(Registro A[], int inicio, int fim){
    int i, j, maximo_index;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = inicio; i < fim ; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        maximo_index = i;
        for (j = i+1; j < fim; j++)
            if (A[j].key < A[maximo_index].key){
                metricas.Comparacoes++;
                maximo_index = j;
            }
 
        // Swap the found minimum element
        // with the first element
        if(maximo_index!=i){
            metricas.Comparacoes++;
            Troca(&A[maximo_index], &A[i]);
        }
    }
}

void QuickSort::Ordena_Selecao(Registro A[], int inicio, int fim, int m){
    int diferenca = fim-inicio;
    while(inicio < fim) {
        metricas.Comparacoes++;
        if (diferenca < m) {
            metricas.Comparacoes++;
            Selecao(A, inicio, fim);
            break;
        }
        else {
            int x = Particao_Selecao(A, inicio, fim);

            if (x-inicio < fim-x) {
                metricas.Comparacoes++;
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

int QuickSort::Particao_Selecao(Registro A[], int inicio, int fim){
    //Descricao:: Realiza a partição do algoritmo QuickSort Seleção

    Registro x = A[fim];
    metricas.Atribuicoes++;
    int i = inicio;

    for (int j = inicio; j <= fim - 1; j++) {
        if (A[j].key <= x.key) {
            metricas.Comparacoes++;
            Troca(&A[i], &A[j]);
            i++;
        }
    }
    Troca(&A[i], &A[fim]);
    return i;
}

void QuickSort::QuickSort_Selecao(Registro A[], int n, int m){

    //Descrição: as comparacoes e atribuicoes
    metricas.Comparacoes=0;
    metricas.Atribuicoes=0;

    Ordena_Selecao(A, 0, n-1, m);
}

//************************************QUICKSORT MEDIANA******************************************

void QuickSort::QuickSort_Mediana(Registro A[], int n, int k){

    //Inicializa as comparacoes e atribuicoes
    metricas.Comparacoes=0;
    metricas.Atribuicoes=0;

    Ordena_Mediana(A,0,n-1,k);
}

void QuickSort::Ordena_Mediana(Registro A[], int inicio, int fim, int k){

}


//************************************QUICKSORT NAO RECURSIVO************************************

int QuickSort::Particao_naoRec(Registro A[], int inicio, int fim){
    //Descricao: Particiona 
    Registro x = A[fim];
    metricas.Atribuicoes++;
    int indice_naoRec = (inicio - 1);
 
    for (int j = inicio ; j <= fim - 1; j++) {
        if (A[j].key <= x.key) {
            metricas.Comparacoes++;
            indice_naoRec++;
            Troca(&A[indice_naoRec], &A[j]);
        }
    }
    Troca(&A[indice_naoRec + 1], &A[fim]);
    return (indice_naoRec + 1);
}

void QuickSort::Ordena_naoRec(Registro A[], int inicio, int fim){
    //Descricao: Implementacao do Algoritmo QuickSortNaoRecursivo

    //Criando pilha dinamicamente
    int *pilha = new int[fim-inicio+1];
 
    //Inicializando o topo da pilha
    int topo_pilha = -1;
 
    // push initial values of l and h to pilha
    topo_pilha++;
    pilha[topo_pilha] = inicio;
    metricas.Atribuicoes++;

    topo_pilha++;
    pilha[topo_pilha] = fim;
    metricas.Atribuicoes++;
 
    // Keep popping from pilha while is not empty
    while (topo_pilha >= 0) {
        metricas.Comparacoes++;
        // Pop h and l
        fim = pilha[topo_pilha--];
        inicio = pilha[topo_pilha--];
        metricas.Atribuicoes+=2;
 
        // Set pivot element at its correct position
        // in sorted array
        int particao = Particao_naoRec(A, inicio, fim);
 
        // If there are elements on left side of pivot,
        // then push left side to pilha
        if (particao - 1 > inicio) {
            metricas.Comparacoes++;
            topo_pilha++;
            pilha[topo_pilha] = inicio;
            topo_pilha++;
            pilha[topo_pilha] = particao - 1;
            metricas.Atribuicoes+=2;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to pilha
        if (particao + 1 < fim) {
            metricas.Comparacoes++;
            pilha[topo_pilha] = particao + 1;
            pilha[topo_pilha] = fim;
            metricas.Atribuicoes+=2;
        }
    }
    delete [] pilha;
}

void QuickSort::QuickSort_naoRec(Registro A[], int n){
    //Descrição: Chamada do algoritmo QuickSort não Recursivo

    //Inicializa as comparacoes e atribuicoes
    metricas.Comparacoes=0;
    metricas.Atribuicoes=0;

    Ordena_naoRec(A,0,n-1);
}

void QuickSort::imprime_Metricas(int algoritmo, int semente, ofstream *saida, int n){
    //Descricao: Imprime as metricas de cada algoritmo

    if(algoritmo==1){
        *saida << "QuickSort (" << n << ") - semente [" << semente << "]:" << endl;
        *saida << "Numero de comparacoes: " << metricas.Comparacoes << endl;
        *saida << "Numero de atribuicoes: " << metricas.Atribuicoes << endl;
    }
    else if(algoritmo==2){
        *saida << "QuickSort Mediana (" << n << ") - semente [" << semente << "]:" << endl;
        *saida << "Numero de comparacoes: " << metricas.Comparacoes << endl;
        *saida << "Numero de atribuicoes: " << metricas.Atribuicoes << endl;
    }
    else if(algoritmo==3){
        *saida << "QuickSort Selecao (" << n << ") - semente [" << semente << "]:" << endl;
        *saida << "Numero de comparacoes: " << metricas.Comparacoes << endl;
        *saida << "Numero de atribuicoes: " << metricas.Atribuicoes << endl;
    }
    else if(algoritmo==4){
        *saida << "QuickSort nao Recursivo (" << n << ") - semente [" << semente << "]:" << endl;
        *saida << "Numero de comparacoes: " << metricas.Comparacoes << endl;
        *saida << "Numero de atribuicoes: " << metricas.Atribuicoes << endl;
    }
    else if(algoritmo==5){
        *saida << "QuickSort Empilha Inteligente (" << n << ") - semente [" << semente << "]:" << endl;
        *saida << "Numero de comparacoes: " << metricas.Comparacoes << endl;
        *saida << "Numero de atribuicoes: " << metricas.Atribuicoes << endl;
    }
}