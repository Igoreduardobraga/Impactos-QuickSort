#ifndef PILHA_H
#define PILHA_H

#include "Item.hpp"
#include <iostream>
using namespace std;

struct No
{
    Item valor;
    No* proximo;
};

class Pilha{
    private:
    No* NoTopo;

    public:
    Pilha(); //construtor
    ~Pilha(); //destrutor
    bool estaVazio();
    bool estaCheio();
    void Empilha(Item item);
    Item Desempilha();
    void imprimir();

    
};

#endif