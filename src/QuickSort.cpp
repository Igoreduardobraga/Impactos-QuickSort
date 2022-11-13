#include "QuickSort.hpp"
#include <fstream>

QuickSort::QuickSort(){  }

// QuickSort::QuickSort(int n){
//     registro = new Registro*[n];
//     for(int i=0 ; i<n ;i++){
        
//     }
// }

//************************************QUICKSORT RECURSIVO******************************************//

void QuickSort::Particao(int Esq, int Dir, int *i, int *j, Registro *A) {
    Registro x, w;
    *i = Esq; *j = Dir;
    x = A[(*i + *j)/2]; /* obtem o pivo x */
    do
    {
        metricas_QSR.Comparacoes++;
        while (x > A[*i]){
            (*i)++;
            metricas_QSR.Comparacoes++;
        }
        while (x < A[*j]){
            (*j)--;
            metricas_QSR.Comparacoes++;
        }
        if (*i <= *j)
        {
            metricas_QSR.Comparacoes++;
            w = A[*i]; A[*i] = A[*j]; A[*j] = w;
            metricas_QSR.Atribuicoes+=3;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void QuickSort::Ordena_Recursivo(int Esq, int Dir, Registro *A){ 
    int i, j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j){
        Ordena_Recursivo(Esq, j, A);
        metricas_QSR.Comparacoes++;
    }
    if (i < Dir) {
        Ordena_Recursivo(i, Dir, A);
        metricas_QSR.Comparacoes++;
    }
}

void QuickSort::Chama_QuickSort_Recursivo(int inicio, Registro *A, int n){
    Ordena_Recursivo(0, n-1, A);
}

//************************************QUICKSORT MEDIANA******************************************//

//função auxiliar para realizar as trocas de elementos
void QuickSort::swap(Registro A[], int i, int j){
    Registro temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    metricas_QSM.Atribuicoes += 3;
}

int QuickSort::Particao_Mediana(Registro A[], int inicio, int fim) {
    //procura a mediana entre inicio, meio e fim
    int meio = (inicio + fim) / 2;
    Registro a = A[inicio];
    Registro b = A[meio];
    Registro c = A[fim];
    int medianaIndice; //índice da mediana
    //A sequência de if...else a seguir verifica qual é a mediana
    metricas_QSM.Comparacoes++;
    if (a < b) {
        metricas_QSM.Comparacoes++;
        if (b < c) {
            //a < b && b < c
            medianaIndice = meio;
            metricas_QSM.Comparacoes++;
        } else {
            if (a < c) {
                //a < c && c <= b
                medianaIndice = fim;
                metricas_QSM.Comparacoes++;
            } else {
                //c <= a && a < b
                medianaIndice = inicio;
                metricas_QSM.Comparacoes++;
            }
        }
    } else {
        if (c < b) {
            //c < b && b <= a
            medianaIndice = meio;
            metricas_QSM.Comparacoes++;
        } else {
            if (c < a) {
                //b <= c && c < a
                medianaIndice = fim;
                metricas_QSM.Comparacoes++;
            } else {
                //b <= a && a <= c
                medianaIndice = inicio;
                metricas_QSM.Comparacoes++;
            }
        }
    }
    //coloca o elemento da mediana no fim para poder usar o Quicksort de Cormen
    swap(A, medianaIndice, fim);

    Registro pivo = A[fim];
    int i = inicio - 1;
    int j;
    /*
     * Este laço irá varrer os vetores da esquerda para direira
     * procurando os elementos que são menores ou iguais ao pivô.
     * Esses elementos são colocados na partição esquerda.         
     */
    for (j = inicio; j <= fim - 1; j++) {
        if (A[j] <= pivo) {
            metricas_QSM.Comparacoes++;
            i = i + 1;
            swap(A, i, j);
        }
    }

    swap(A, i + 1, fim);
    return i + 1; //retorna a posição do pivô
}

void QuickSort::Chama_QuickSort_Mediana(int inicio, Registro A[], int fim) {
    if (inicio < fim) {
        metricas_QSM.Comparacoes++;
        //realiza a partição
        int q = Particao_Mediana(A, inicio, fim);
        //ordena a partição esquerda
        Chama_QuickSort_Mediana(inicio, A, q - 1);
        //ordena a partição direita
        Chama_QuickSort_Mediana(q + 1, A, fim);
    }
}

//************************************QUICKSORT NAO RECURSIVO******************************************//

void QuickSort::swap_naoRec(Registro* a, Registro* b)
{
    Registro t = *a;
    *a = *b;
    *b = t;
    metricas_QSNR.Atribuicoes+=3;
}

int QuickSort::partition_naoRec(Registro A[], int inicio, int fim)
{
    Registro x = A[fim];
    int indice_naoRec = (inicio - 1);
 
    for (int j = inicio ; j <= fim - 1; j++) {
        metricas_QSNR.Comparacoes++;
        if (A[j] <= x) {
            indice_naoRec++;
            swap_naoRec(&A[indice_naoRec], &A[j]);
        }
    }
    swap_naoRec(&A[indice_naoRec + 1], &A[fim]);
    return (indice_naoRec + 1);
}

void QuickSort::QuickSortNaoRec(Registro A[], int inicio, int fim){
    //Descricao: Implementacao do Algoritmo QuickSortNaoRecursivo
    //Criando 
    int *pilha = new int[fim-inicio+1];
 
    //Inicializando o topo da pilha
    int topo_pilha = -1;
 
    // push initial values of l and h to pilha
    topo_pilha++;
    pilha[topo_pilha] = inicio;

    topo_pilha++;
    pilha[topo_pilha] = fim;
 
    // Keep popping from pilha while is not empty
    while (topo_pilha >= 0) {
        // Pop h and l
        fim = pilha[topo_pilha--];
        inicio = pilha[topo_pilha--];
 
        // Set pivot element at its correct position
        // in sorted array
        int particao = partition_naoRec(A, inicio, fim);
 
        // If there are elements on left side of pivot,
        // then push left side to pilha
        if (particao - 1 > inicio) {
            topo_pilha++;
            pilha[topo_pilha] = inicio;
            topo_pilha++;
            pilha[topo_pilha] = particao - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to pilha
        if (particao + 1 < fim) {
            topo_pilha++;
            pilha[topo_pilha] = particao + 1;
            topo_pilha++;
            pilha[topo_pilha] = fim;
        }
    }
    delete [] pilha;
}

void QuickSort::imprime_Metricas(int algoritmo, ofstream *saida, int n){
    //Descricao: Imprime as metricas de cada algoritmo
    if(algoritmo==1){
        *saida << "QuickSort " << n << ":" << endl;
        *saida << "Numero de comparacoes: " << metricas_QSR.Comparacoes << endl;
        *saida << "Numero de atribuicoes: " << metricas_QSR.Atribuicoes << endl;
    }
    else if(algoritmo==2){
        *saida << "QuickSort Mediana " << n << ":" << endl;
        *saida << "Numero de comparacoes: " << metricas_QSM.Comparacoes << endl;
        *saida << "Numero de atribuicoes: " << metricas_QSM.Atribuicoes << endl;
    }
    else if(algoritmo==3){
        *saida << "QuickSort Selecao " << n << ":" << endl;
        *saida << "Numero de comparacoes: " << metricas_QSS.Comparacoes << endl;
        *saida << "Numero de atribuicoes: " << metricas_QSS.Atribuicoes << endl;
    }
    else if(algoritmo==4){
        *saida << "QuickSort nao Recursivo " << n << ":" << endl;
        *saida << "Numero de comparacoes: " << metricas_QSNR.Comparacoes << endl;
        *saida << "Numero de atribuicoes: " << metricas_QSNR.Atribuicoes << endl;
    }
    else if(algoritmo==5){
        *saida << "QuickSort Empilha Inteligente " << n << ":" << endl;
        *saida << "Numero de comparacoes: " << metricas_QSEI.Comparacoes << endl;
        *saida << "Numero de atribuicoes: " << metricas_QSEI.Atribuicoes << endl;
    }
}