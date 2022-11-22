#include "QuickSort.hpp"
#include <fstream>

QuickSort::QuickSort(){}

QuickSort::~QuickSort(){}

void QuickSort::Troca(Registro* a, Registro* b){
    //Descricao:: Realiza a troca de posição de dois registros
    //Entrada: *a, *b
    //Saida: não tem

    Registro t = *a;
    *a = *b;
    *b = t;
    metricas.Atribuicoes+=3;
    
    ESCREVEMEMLOG((long int)(&(*a)), sizeof(Registro), 0);
    ESCREVEMEMLOG((long int)(&(*b)), sizeof(Registro), 0);
}

//************************************QUICKSORT RECURSIVO******************************************//

void QuickSort::Particao(int Esq, int Dir, int *i, int *j, Registro *A) {
    //Descricao: Realiza a partição do algoritmo QuickSort Recursivo
    //Entrada: Esq, Dir, *i (indice esquerda), *j (indice direita), *A (vetor a ser ordenado)
    //Saida: não tem

    Registro x, w;
    *i = Esq; *j = Dir;
    x = A[(*i + *j)/2]; /* obtem o pivo x */
    metricas.Atribuicoes++;
    do
    {
        metricas.Comparacoes++;
        while (x.key > A[*i].key){
            LEMEMLOG((long int)(&(A[*i].key)), sizeof(int), 0);
            (*i)++;
            metricas.Comparacoes++;
        }
        while (x.key < A[*j].key){
            LEMEMLOG((long int)(&(A[*j].key)), sizeof(int), 0);
            (*j)--;
            metricas.Comparacoes++;
        }
        if (*i <= *j)
        {
            metricas.Comparacoes++;
            w = A[*i]; A[*i] = A[*j]; A[*j] = w;
            ESCREVEMEMLOG((long int)(&(A[*i])), sizeof(Registro), 0);
            ESCREVEMEMLOG((long int)(&(A[*j])), sizeof(Registro), 0);

            metricas.Atribuicoes+=3;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void QuickSort::Ordena_Recursivo(int Esq, int Dir, Registro *A){
    //Descricao: Realiza a ordenação do algoritmo QuickSort Recursivo
    //Entrada: Esq, Dir, *A (vetor a ser ordenado)
    //Saida: não tem

    int i, j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j){
        Ordena_Recursivo(Esq, j, A);
    }
    if (i < Dir) {
        Ordena_Recursivo(i, Dir, A);
    }
}

void QuickSort::QuickSort_Recursivo(Registro *A, int n){
    //Descricao: Chamada do algoritmo QuickSort Recursivo
    //Entrada: *A (vetor a ser ordenado), n (tamanho do vetor A[])
    //Saida: não tem

    //Inicializa as comparacoes e atribuicoes
    metricas.Comparacoes=0;
    metricas.Atribuicoes=0;
    Ordena_Recursivo(0, n-1, A);
}

//************************************QUICKSORT SELEÇÃO******************************************

void QuickSort::Selecao(Registro A[], int inicio, int fim){
    //Descricao: Realiza a ordenação do vetor por meio do algoritmo Selection Sort
    //Entrada: A[] (vetor a ser ordenado), inicio (inicio do vetor A[]), fim (fim do vetor A[])
    //Saida: não tem

    int i, j, Min;
    for (i = 0; i < fim - 1; i++){
        Min = i;
    for (j = i + 1 ; j < fim; j++){
        if (A[j].key < A[Min].key){
            LEMEMLOG((long int)(&(A[j].key)), sizeof(int), 0);
            LEMEMLOG((long int)(&(A[Min].key)), sizeof(int), 0);
            metricas.Comparacoes++;
            Min = j;
        }
    }
    Troca(&A[i], &A[Min]);
    }
}

void QuickSort::Ordena_Selecao(Registro A[], int inicio, int fim, int m){
    //Descricao: Realiza a ordenação do algoritmo QuickSort Seleção
    //Entrada: A[] (vetor a ser ordenado), inicio (inicio do vetor A[]), fim (fim do vetor A[])
    //Saida: não tem

    int i, j;

    if(fim-inicio<=m){
        Selecao(A,inicio,fim);
        i=j+1;
        j=0;
    }
    else{
        Particao(inicio,fim,&i,&j,A);
    }
        
}

void QuickSort::QuickSort_Selecao(Registro A[], int n, int m){
    //Descrição: Realiza a chamada do algoritmo QuickSort Seleção
    //Entrada: A[] (vetor a ser ordenado), n (tamanho do vetor), m (tamanho da particao que sera ordenada)
    //Saida: não tem

    //Descrição: Inicializa as comparacoes e atribuicoes
    metricas.Comparacoes=0;
    metricas.Atribuicoes=0;

    Ordena_Selecao(A, 0, n-1, m);
}

//************************************QUICKSORT MEDIANA******************************************

void QuickSort::QuickSort_Mediana(Registro A[], int n, int k){
    //Descrição: Realiza a chamada do algoritmo QuickSort Mediana
    //Entrada: A[] (vetor a ser ordenado), n (numero de elementos do vetor A[]), k (quantidade de elementos que serão usados para calcular a mediana)
    //Saida: não tem

    //Inicializa as comparacoes e atribuicoes
    metricas.Comparacoes=0;
    metricas.Atribuicoes=0;

    Ordena_Mediana(A,0,n-1,k);
}

void QuickSort::Ordena_Mediana(Registro A[], int Esq, int Dir, int k){
    //Descricao: Realiza a ordenação do vetor
    //Entrada: A[] (vetor a ser ordenado), Esq (posicao inicial do vetor A[]), Dir (posicao final do vetor A[]), k (quantidade de elementos que serão usados para calcular a mediana)
    //Saida: nao tem

    int i, j;
    Particao_Mediana(A, Esq, Dir, &i, &j, k);
    if (Esq < j){
        Ordena_Mediana(A, Esq, j, k);
    }
    if (i < Dir) {
        Ordena_Mediana(A, i, Dir, k);
    }
}

void QuickSort::Particao_Mediana(Registro A[], int Esq, int Dir, int *i, int *j, int k){
    //Descricao: Realiza o particionamento do algoritmo QuickSort Mediana
    //Entrada: A[] (vetor a ser ordenado), Esq, Dir, *i (indice esquerda), *j (indice direita), k (quantidade de elementos que serão usados para calcular a mediana)
    //Saida: não tem

    Registro x, w;
    *i = Esq; *j = Dir;
    x = Mediana(A,Esq,Dir,*i,*j,k);
    metricas.Atribuicoes++;
    do
    {
        metricas.Comparacoes++;
        while (x.key > A[*i].key){
            LEMEMLOG((long int)(&(A[*i].key)), sizeof(int), 0);
            (*i)++;
            metricas.Comparacoes++;
        }
        while (x.key < A[*j].key){
            LEMEMLOG((long int)(&(A[*j].key)), sizeof(int), 0);
            (*j)--;
            metricas.Comparacoes++;
        }
        if (*i <= *j)
        {
            metricas.Comparacoes++;
            w = A[*i]; A[*i] = A[*j]; A[*j] = w;
            ESCREVEMEMLOG((long int)(&(A[*i])), sizeof(Registro), 0);
            ESCREVEMEMLOG((long int)(&(A[*j])), sizeof(Registro), 0);

            metricas.Atribuicoes+=3;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

Registro QuickSort::Mediana(Registro A[], int inicio, int fim, int i, int j, int qntd_elementos_mediana){
    //Descricao: Realiza a mediana de k elementos do vetor A[] escolhidos aleatoriamente
    //Entrada: A[] (vetor a ser ordenado), inicio, fim, i, j, qntd_elementos_mediana (quantidade de elementos que serão escolhidos aleatoriamente para o calculo da mediana)
    //Saida: A[mediana]

    if(inicio+qntd_elementos_mediana>=fim){
        qntd_elementos_mediana = fim-inicio;
    }


    int posicoes_mediana[qntd_elementos_mediana];
    for(int i=0 ; i<qntd_elementos_mediana ; i++){
        posicoes_mediana[i] = inicio+rand()%qntd_elementos_mediana;
    }

    for (int step = 0; step <qntd_elementos_mediana-1  ; step++) {
        int min_index = step;
        for (int i = step + 1; i < qntd_elementos_mediana; i++) {
            if (posicoes_mediana[i] < posicoes_mediana[min_index]){
                min_index = i;
            }
        }
        int temp = posicoes_mediana[step];
        posicoes_mediana[step] = posicoes_mediana[min_index];
        posicoes_mediana[min_index] = temp;
    }

    int aux = qntd_elementos_mediana/2;
    int mediana = posicoes_mediana[aux];

    return A[mediana];
}

//************************************QUICKSORT NAO RECURSIVO************************************

int QuickSort::Particao_naoRec(Registro A[], int inicio, int fim){
    //Descricao: Realiza o particionamento do algoritmo QuickSort não Recursivo
    //Entrada: A[] (vetor a ser ordenado), inicio, fim
    //Saida: indice_naoRec + 1

    Registro x = A[fim];
    metricas.Atribuicoes++;
    int indice_naoRec = (inicio - 1);
 
    for (int j = inicio ; j <= fim - 1; j++) {
        if (A[j].key <= x.key) {
            LEMEMLOG((long int)(&(A[j].key)), sizeof(int), 0);
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
    //Entrada: A[] (vetor a ser ordenado), inicio (inicio do vetor A[]), fim (fim do vetor A[])
    //Saida: não tem

    //Criando pilha dinamicamente
    int *pilha = new int[fim-inicio+1];
 
    //Inicializando o topo da pilha
    int topo_pilha = -1;
 
    //colocando os valores de inicio e fim na pilha
    pilha[++topo_pilha] = inicio;

    pilha[++topo_pilha] = fim;
 
    //Enquanto a pilha não estiver vazia, desempilha
    while (topo_pilha >= 0) {

        fim = pilha[topo_pilha--];
        inicio = pilha[topo_pilha--];
 
        // Define o pivô na sua posição ideal
        int particao = Particao_naoRec(A, inicio, fim);
 
        //Se houver elementos no lado esquerdo do pivô, empilhe-o
        if (particao - 1 > inicio) {
            metricas.Comparacoes++;
            pilha[++topo_pilha] = inicio;
            pilha[++topo_pilha] = particao - 1;
        }
 
        //Se houver elementos no lado direito do pivô, empilhe-o
        if (particao + 1 < fim) {
            metricas.Comparacoes++;
            pilha[++topo_pilha] = particao + 1;
            pilha[++topo_pilha] = fim;
        }
    }
    delete [] pilha;
}

void QuickSort::QuickSort_naoRec(Registro A[], int n){
    //Descrição: Chamada do algoritmo QuickSort não Recursivo
    //Entrada:
    //Saida: não tem

    //Inicializa as comparacoes e atribuicoes
    metricas.Comparacoes=0;
    metricas.Atribuicoes=0;

    Ordena_naoRec(A,0,n-1);
}

//************************************QUICKSORT EMPILHA INTELIGENTE************************************

void QuickSort::QuickSort_EmpilhaInteligente(Registro A[], int n){
    //Descrição: Realiza a chamada do algoritmo QuickSort Empilha Inteligente
    //Entrada: A[] (vetor a ser ordenado), n (tamanho do vetor A[])
    //Saida: não tem

    //Inicializa as comparacoes e atribuicoes
    metricas.Comparacoes=0;
    metricas.Atribuicoes=0;

    Ordena_EmpilhaInteligente(A,0,n-1);
}

void QuickSort::Ordena_EmpilhaInteligente(Registro A[], int inicio, int fim){
    //Descricao: Realiza a ordenação do algoritmo QuickSort Empilha Inteligente
    //Entrada: A[] (vetor a ser ordenado), inicio (inicio do vetor), fim (fim do vetor)
    //Saida: não tem

    Pilha pilha;
    Item item; // campos esq e dir
    int esq, dir, i, j;
    dir = fim;
    esq = inicio;
    item.dir = dir;
    item.esq = esq;
    pilha.Empilha(item);

    do{
        if (dir > esq) {
        Particao(esq,dir,&i,&j,A);
            if ((j-esq)>(dir-i)) {
                item.dir = j;
                item.esq = esq;
                pilha.Empilha(item);
                esq = i;
            }
            else {
                item.esq = i;
                item.dir = dir;
                pilha.Empilha(item);
                dir = j;
            }
        }
        else{
            item = pilha.Desempilha();
            dir = item.dir;
            esq = item.esq;
        }
    } while(!pilha.estaVazio());
}

void QuickSort::imprime_Metricas(int algoritmo, int semente, ofstream *saida, int n){
    //Descricao: Imprime as metricas de cada algoritmo
    //Entrada: algoritmo (QuickSort alvo), semente (semente usada), *saida (arquivo de saida), n (tamanho do vetor de registro)
    //Saida: não tem

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