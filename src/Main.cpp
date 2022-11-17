#include "QuickSort.hpp"
#include "memlog.h"
#include "Registro.hpp"
#include "msgassert.h"
#include "GeradorAleatorio.hpp"
//#include "QuickSort_Mediana.hpp"
#include <fstream>
#include <sys/resource.h>
#include <iostream>
#include <getopt.h>
#include <string.h>
using namespace std;

string arquivo_entrada;
string arquivo_saida;
unsigned int algoritmo, semente, m, k;
bool ativamem;
char lognome[100];

void AnalisaComando(int argc, char ** argv){
    // Descrição: analisa a linha de comando a partir do arc e agrv

    // Variavel externa do getopt
    extern char *optarg;

    // Inicializa ativamem com false. caso haja -l no comando ativamem torna-se verdadeira
    ativamem = 0;

    // Variavel auxiliar
    int opcao;

    // Inicializa lognome
    lognome[0] = 0;

    while ((opcao = getopt(argc, argv, "p:li:o:v:s:m:k:")) != EOF){
       switch(opcao) {
            case 'p':
                strcpy(lognome,optarg);
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
            case 's':
                semente = atoi(optarg);
                break;
            case 'm':
                m = atoi(optarg);
                break;
            case 'k':
                k = atoi(optarg);
                break;
            default:
                exit(1);
       }
    }

    // Verifica se o usuário digitou as entradas dos comandos -p -o e -i
    erroAssert(arquivo_entrada.size()>0, "main - nome de arquivo de entrada tem que ser definido");
    erroAssert(arquivo_saida.size()>0, "main - nome de arquivo de saida tem que ser definido");
    erroAssert(strlen(lognome)>0, "main - nome de arquivo de registro de acesso tem que ser definido");
}

int main(int argc, char *argv[]) {

    struct rusage resources;
    int rc;
    double utime, stime, total_time;
    int qntd_valores;
    int n;
    QuickSort quicksort;
    GeradorAleatorio gerar;

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

    srand(semente);

    cout << arquivo_entrada << endl;

    try{
    ifstream entrada;
    entrada.open(arquivo_entrada, std::ios::in);
    if(!entrada.is_open()){
        throw "Nao foi possivel abrir o arquivo de entrada";
    }
    ofstream saida;
    saida.open(arquivo_saida, ios::out);
    if(!saida.is_open()){
        throw "Nao foi possivel abrir o arquivo de saida";
    }

    entrada >> qntd_valores;

    //Percorre o arquivo baseado na quantidade de testes existentes
    for(int i=0 ; i<qntd_valores ; i++){
        entrada >> n;
        Registro *registro = new Registro[n];
        for(int k=0 ; k<n ; k++){
            registro[k].key = gerar.numAleatorio();
        }

        if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
            perror("getrusage falhou");

        switch (algoritmo){
            case 1:
                quicksort.QuickSort_Recursivo(registro, n);
                break;
            case 2:
                quicksort.QuickSort_Mediana(registro, n, k);
                break;
            case 3:
                quicksort.QuickSort_Selecao(registro,n,m);
                break;
            case 4:
                quicksort.QuickSort_naoRec(registro, n);
                break;
            case 5:
                //quicksort.QuickSort_EmpilhaInteligente(registro,n);
            default:
                break;
        }
        
        utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
        total_time = utime+stime;

        quicksort.imprime_Metricas(algoritmo, semente, &saida, n);
        saida << "Tempo de processamento: " << total_time << endl  << endl;

        delete [] registro;
    }
    desativaMemLog();
    entrada.close();
    saida.close();
    } catch(const char *e){
        cout << "ERRO: " << e << endl;
    }
    return 0;
}