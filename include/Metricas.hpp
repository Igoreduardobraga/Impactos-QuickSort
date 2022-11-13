#ifndef METRICAS_H
#define METRICAS_H

class Metricas{
    public:
        unsigned int Comparacoes = 0;
        unsigned int Atribuicoes = 0;
        Metricas() { };
        void Imprimir();
};

#endif