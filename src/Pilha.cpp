#include "Pilha.hpp"

Pilha::Pilha() //construtor
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

bool Pilha::estaVazio()
{
     //Descricao: Verifica se a pilha esta vazia
    return (NoTopo == NULL);
}

bool Pilha::estaCheio()
{
    //Descricao: Verifica se a pilha esta cheia
    No* NoNovo;
    try{
        NoNovo = new No;
        delete NoNovo;
        return false;
    } catch(std::out_of_range const&){
        return true;
    }
}

void Pilha::Empilha(Item item)
{
    //Descricao: Adiciona um item na pilha

    if (estaCheio()){
        cout << "A Pilha esta cheia!\n";
    } else{
        No* NoNovo = new No;
        NoNovo->valor = item;
        NoNovo->proximo = NoTopo;
        NoTopo = NoNovo;
    }
}

Item Pilha::Desempilha()
{
    //Descricao: Remove um item da pilha
        No* NoTemp;
        NoTemp = NoTopo;
        Item item = NoTopo->valor;
        NoTopo = NoTopo->proximo;
        delete NoTemp;
        return item;
}