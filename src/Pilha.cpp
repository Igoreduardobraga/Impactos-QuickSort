#include "Pilha.hpp"

Pilha::Pilha() //construtor //dynamic stack
{
    NoTopo = NULL;
}

Pilha::~Pilha(){ //destrutor
    No* NoTemp;
    while (NoTopo != NULL){
        NoTemp = NoTopo;
        NoTopo = NoTopo->proximo;
        delete NoTemp;
    }
}

bool Pilha::estaVazio() //isempty
{
    return (NoTopo == NULL);
}

bool Pilha::estaCheio() //tem memória //isfull
{
    No* NoNovo;
    try{
        NoNovo = new No;
        delete NoNovo;
        return false;
    } catch(std::out_of_range const&){
        return true;
    }
}

void Pilha::Empilha(Item item) //push
{
    if (estaCheio()){
        cout << "A Pilha esta cheia!\n";
    } else{
        No* NoNovo = new No;
        NoNovo->valor = item;
        NoNovo->proximo = NoTopo;
        NoTopo = NoNovo;
    }
}

Item Pilha::Desempilha() //pop
{
        No* NoTemp;
        NoTemp = NoTopo;
        Item item = NoTopo->valor;
        NoTopo = NoTopo->proximo;
        delete NoTemp;
        return item;
}