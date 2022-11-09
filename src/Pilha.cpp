#include "Pilha.hpp"
#include "TipoItem.hpp"
#include <iostream>
using namespace std;

Pilha::Pilha(){
    topo = -1;
}

void Pilha::Empilha(TipoItem item){
    if(tamanho == MAXTAM)
        throw "A pilha está cheia!";
    
    topo++;
    itens[topo] = item;
    tamanho++;
}

TipoItem Pilha::Desempilha(){
    TipoItem aux;
    if(tamanho == 0)
        throw "A pilha está vazia!";
    
    aux = itens[topo];
    topo--;
    tamanho--;
    return aux;
}

bool Pilha::Vazia(){
    return tamanho=0;
}