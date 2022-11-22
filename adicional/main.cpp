#include <iostream>
#include <sys/resource.h>
#include <cmath>
using namespace std;

void Troca(int* a, int* b){
    //Descricao: Realiza a troca de posição

    int t = *a;
    *a = *b;
    *b = t;
}

int Mediana(int vetor[], int posicaoInicial, int poiscaoFinal, const int quantidadePossiveisPivos){

    unsigned int quantidadePivosSeraoEscolhidos = 0;
            if(quantidadePossiveisPivos >= (poiscaoFinal - posicaoInicial + 1)) {
                return vetor[posicaoInicial];
            }
            else {
                quantidadePivosSeraoEscolhidos = quantidadePossiveisPivos;
            }
            unsigned int posicoesEscolhidas[quantidadePivosSeraoEscolhidos];

            posicoesEscolhidas[0] = posicaoInicial+rand()%poiscaoFinal;
            for(unsigned int i = 1; i < quantidadePivosSeraoEscolhidos; i++) {
                unsigned int possivelPosicao = posicaoInicial+rand()%poiscaoFinal;

                for(unsigned int j = 0; j < i; j++) {
                    if(possivelPosicao == posicoesEscolhidas[j]) {
                        i--;
                        break;
                    }
                    
                    if(j == i - 1) {
                        posicoesEscolhidas[i] = possivelPosicao;
                        break;
                    }
                }
            }

            for(unsigned int i = 0; i < quantidadePivosSeraoEscolhidos; i++) {
                unsigned int indexMaior = 0;
                for(unsigned int j = 1; j < quantidadePivosSeraoEscolhidos-i; j++) {
                    if(posicoesEscolhidas[indexMaior] < posicoesEscolhidas[j]) {
                        indexMaior = j;
                    }
                }

                int conteudo = posicoesEscolhidas[quantidadePivosSeraoEscolhidos-i-1];
                posicoesEscolhidas[quantidadePivosSeraoEscolhidos-i-1] = posicoesEscolhidas[indexMaior];
                posicoesEscolhidas[indexMaior] = conteudo;
            }

            unsigned int indexMediana = std::floor(quantidadePivosSeraoEscolhidos / 2.0); 
            unsigned int indexPivoEscolhido = posicoesEscolhidas[indexMediana];

            return vetor[indexPivoEscolhido];
}

void particionarCrescente(int vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita, const int quantidadePossiveisPivos) {
            *indexEsquerda = posicaoInicial;
            *indexDireita = poiscaoFinal;

            int pivo = Mediana(vetor, posicaoInicial, poiscaoFinal, quantidadePossiveisPivos);

            do {
                
                while(pivo > vetor[*indexEsquerda]) {
                    
                    (*indexEsquerda)++;
                }

                
                while(pivo < vetor[*indexDireita]) {
                    
                    (*indexDireita)--;
                }

                if(*indexEsquerda <= *indexDireita) {
                    int trocaTemporaria = vetor[*indexEsquerda];
                    vetor[*indexEsquerda] = vetor[*indexDireita];
                    vetor[*indexDireita] = trocaTemporaria;

                    (*indexEsquerda)++;
                    (*indexDireita)--;
                }
            } while(*indexEsquerda <= *indexDireita);
}

void quickSortCrescente(int vetor[], int posicaoInicial, int poiscaoFinal, const int quantidadePossiveisPivos) { 
            int indexEsquerda = 0;
            int indexDireita = 0;

            particionarCrescente(vetor, posicaoInicial, poiscaoFinal, &indexEsquerda, &indexDireita, quantidadePossiveisPivos);

            if(posicaoInicial < indexDireita) {
                quickSortCrescente(vetor, posicaoInicial, indexDireita, quantidadePossiveisPivos);
            }

            if(indexEsquerda < poiscaoFinal) {
                quickSortCrescente(vetor, indexEsquerda, poiscaoFinal, quantidadePossiveisPivos);
            }

            return;
}

void ordenarCrescente(int vetor[], const unsigned int tamanho, const int quantidadePossiveisPivos) {
    quickSortCrescente(vetor, 0, tamanho - 1, quantidadePossiveisPivos);
    return;
}

int main(){

    int *a = new int[1000000];

    ordenarCrescente(a,1000000,3);

    for(int i=0 ; i<1000 ; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    delete [] a;
    
    return 0;
}



//     unsigned int quantidadePivosSeraoEscolhidos = 0;
//             if(quantidadePossiveisPivos >= (poiscaoFinal - posicaoInicial + 1)) {
//                 return vetor[posicaoInicial];
//             }
//             else {
//                 quantidadePivosSeraoEscolhidos = quantidadePossiveisPivos;
//             }
//             unsigned int* posicoesEscolhidas = new unsigned int[quantidadePivosSeraoEscolhidos];

//             posicoesEscolhidas[0] = Utils::gerarNumeroInteiroAleatorioEmUmaFaixa(posicaoInicial, poiscaoFinal);
//             for(unsigned int i = 1; i < quantidadePivosSeraoEscolhidos; i++) {
//                 unsigned int possivelPosicao = Utils::gerarNumeroInteiroAleatorioEmUmaFaixa(posicaoInicial, poiscaoFinal);

//                 for(unsigned int j = 0; j < i; j++) {
//                     if(possivelPosicao == posicoesEscolhidas[j]) {
//                         i--;
//                         break;
//                     }
                    
//                     if(j == i - 1) {
//                         posicoesEscolhidas[i] = possivelPosicao;
//                         break;
//                     }
//                 }
//             }

//             Selecao::ordenarCrescente(posicoesEscolhidas, quantidadePivosSeraoEscolhidos);

//             unsigned int indexMediana = std::floor(quantidadePivosSeraoEscolhidos / 2.0); 
//             unsigned int indexPivoEscolhido = posicoesEscolhidas[indexMediana];

//             delete[] posicoesEscolhidas;
//             return vetor[indexPivoEscolhido];
// }



// int diferenca = fim-inicio+1;
//     if(qntd_elementos_mediana>=diferenca){
//         return A[inicio];
//     }

//     int *posicoes_aleatorias = new int[qntd_elementos_mediana];
//     posicoes_aleatorias[0] = inicio+rand()%fim;

//     for(int i=1 ; i<qntd_elementos_mediana ; i++){
//         int m = inicio+rand()%fim;

//         for(int j=0 ; j<i ; j++){
//             if(m==posicoes_aleatorias[j]){
//                 i--;
//                 break;
//             }
//             if(j == i - 1) {
//                 posicoes_aleatorias[i] = m;
//                 break;
//             }
//         }
//     }
//     int i, j, maximo_index;

//     //Ordena o vetor de posições para o calculo da mediana em ordem crescente a partir do metodo selection sort
//     for (i = 0; i < qntd_elementos_mediana ; i++){
//         maximo_index = 0;
//         for (j = 1; j < qntd_elementos_mediana-i; j++){
//             if (posicoes_aleatorias[maximo_index] < posicoes_aleatorias[j]){
//                 maximo_index = j;
//             }
//         }

//         int aux = posicoes_aleatorias[qntd_elementos_mediana-i-1];
//         posicoes_aleatorias[qntd_elementos_mediana-i-1] = posicoes_aleatorias[maximo_index];
//         posicoes_aleatorias[maximo_index] = aux;
//         }
//         int novo_i = qntd_elementos_mediana/2;
//         int novo_x = posicoes_aleatorias[novo_i];

//         delete [] posicoes_aleatorias;
//         return A[novo_x];