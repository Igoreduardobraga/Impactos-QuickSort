#include "QuickSort.hpp"
#include "memlog.h"
#include "msgassert.h"
//#include "QuickSort_Mediana.hpp"
#include <fstream>
#include <iostream>
#include <getopt.h>
#include <string.h>
using namespace std;

string arquivo_entrada;
string arquivo_saida;
int semente;
bool ativamem;
char lognome[100];
int algoritmo;

void AnalisaComando(int argc,char ** argv){
    // Descrição: analisa a linha de comando a partir do arc e agrv

    // Variavel externa do getopt
    extern char *optarg;

    // Inicializa ativamem com false. caso haja -l no comando ativamem torna-se verdadeira
    ativamem = 0;

    // Variavel auxiliar
    int opcao;

    // Inicializa lognome
    lognome[0] = 0;

    while ((opcao = getopt(argc, argv, "p:li:o:")) != EOF){
       switch(opcao) {
            case 'p':
                strcpy(lognome,optarg);
                break;
            case 's':
                semente = atoi(optarg);
                break;
            case 'l':
                ativamem = 1;
                break;
            case 'i':
                arquivo_entrada = optarg;
                break;
            case 'o':
                arquivo_saida = optarg;
                break;
            case 'v':
                algoritmo = atoi(optarg);
            default:
                exit(1);
       }
    }

    // Verifica se o usuário digitou as entradas dos comandos -p -o e -i
    erroAssert(arquivo_entrada.size()>0, "main - nome de arquivo de entrada tem que ser definido");
    erroAssert(arquivo_saida.size()>0, "main - nome de arquivo de saida tem que ser definido");
    erroAssert(strlen(lognome)>0, "main - nome de arquivo de registro de acesso tem que ser definido");
}

void criaSemente(){
    //Decrição: Configura a semente usada para gerar os numeros aleatórios

    srand(semente);
}

int main(int argc, char *argv[]) {

    unsigned int soma_testes = 0;
    unsigned int qntd_valores;
    unsigned int n;

    AnalisaComando(argc,argv);

    // Inicia o registo de acesso
    iniciaMemLog(lognome);

    // Se -l for encontrado no comando, ativa o registro de acesso. Caso não for encontrado, não ativa o registro de acesso
    if(ativamem){
        ativaMemLog();
    }
    else{
        desativaMemLog();
    }

    criaSemente();

    ifstream entrada;
    entrada.open(arquivo_entrada, std::ios::in);
    erroAssert(entrada.is_open(), "Não foi possivel abrir o arquivo de entrada");

    ofstream saida;
    saida.open(arquivo_saida, ios::app);
    erroAssert(saida.is_open(), "Não foi possivel abrir o arquivo de entrada");

    entrada >> qntd_valores;

    //Percorre o arquivo baseado na quantidade de testes existentes
    for(int i=0 ; i<qntd_valores ; i++){
        entrada >> n;
        Registro registro = new Registro[n];
        for(int k=0 ; k<n ; k++){
            registro[k].key = rand();
        }
    }

    switch (algoritmo){
        case 1:
            
                
            break;
    
    default:
        break;
    }

    QuickSort M;
    int *A = new int[30];
    //srand(time(0));

    for(int i=0 ; i<30 ; i++)
        A[i] = rand()%100;
    
    for(int i=0 ; i<30 ; i++)
        cout << A[i] << " ";

    cout << endl;

    int *B = new int[30];

    for(int i=0 ; i<30 ; i++){
        B[i] = A[i];
        cout << B[i] << " ";
    }

    cout << "\n\n";

    M.Chama_QuickSort_Recursivo(0,A,30);
    M.Chama_QuickSort_Mediana(0,B,30);
    for(int i=0 ; i<30 ; i++)
        cout << A[i] << " ";

    cout << "\n";

    for(int i=0 ; i<30 ; i++)
        cout << B[i] << " ";

    delete [] A;
    delete [] B;

    desativaMemLog();
    entrada.close();
    saida.close();
    return 0;
}