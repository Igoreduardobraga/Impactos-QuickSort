#ifndef PILHA_H
#define PILHA_H

class Pilha{
    private:
        int topo;
        static const int MAXTAM = 100;
        TipoItem itens[MAXTAM];
        int tamanho;

    public:
        Pilha();
        void Empilha(TipoItem item);
        TipoItem Desempilha();
        void Limpa();
        bool Vazia();
};

#endif