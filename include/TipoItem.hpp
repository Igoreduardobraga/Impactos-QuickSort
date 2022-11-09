#ifndef TIPOITEM_H
#define TIPOITEM_H

typedef int TipoChave;

class TipoItem{
    public:
        TipoItem();
        TipoItem(TipoChave c);
        void SetChave(TipoChave c);
        TipoChave GetChave();

    private:
        TipoChave chave;
};

#endif