#include <iostream>
using namespace std;

typedef string TipoChave;

class TipoItem{
    public:
        TipoItem();
        TipoItem(TipoChave c);
        void SetChave(TipoChave c);
        TipoChave GetChave();

    private:
        TipoChave chave;
};

TipoItem::TipoItem(){
    chave = " "; // indica um item vazio}
}

TipoItem::TipoItem(TipoChave c){
    chave = c;
}

void TipoItem::SetChave(TipoChave c){
    chave = c;
}

TipoChave TipoItem::GetChave(){
    return chave;
}

class TipoNo
{
public:
    TipoNo();
private:
    TipoItem item;
    TipoNo *esq;
    TipoNo *dir;
    friend class ArvoreBinaria;
};

TipoNo::TipoNo()
{
    item = " ";
    esq = NULL;
    dir = NULL;
}

class ArvoreBinaria{
    public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(TipoItem item);
    void Caminha(int tipo);
    TipoItem Pesquisa(TipoChave chave);
    void Remove(TipoChave chave);
    void Limpa();
    private:
    void InsereRecursivo(TipoNo* &p, TipoItem item);
    void ApagaRecursivo(TipoNo* p);
    TipoItem PesquisaRecursivo(TipoNo* p, TipoChave chave);
    void RemoveRecursivo(TipoNo* &p, TipoChave chave);
    void Antecessor(TipoNo* q, TipoNo* &r);
    void PorNivel();
    void PreOrdem(TipoNo* p);
    void InOrdem(TipoNo* p);
    void PosOrdem(TipoNo* p);
    TipoNo *raiz;
};

TipoItem ArvoreBinaria::Pesquisa(TipoChave chave) {
    return PesquisaRecursivo(raiz, chave);
}
TipoItem ArvoreBinaria::PesquisaRecursivo(TipoNo *no, TipoChave chave) {
    TipoItem aux;
    if (no == NULL) {
        aux.SetChave(""); // Flag para item não presente
    return aux;
    }
    if (chave < no->item.GetChave())
        return PesquisaRecursivo(no->esq, chave);
    else if (chave>no->item.GetChave())
        return PesquisaRecursivo(no->dir, chave);
    else
        return no->item;
}   

void ArvoreBinaria::Insere(TipoItem item){
    InsereRecursivo(raiz,item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, TipoItem item){
    if(p==NULL){
        p = new TipoNo();
        p->item = item;
    }
    else{
        if(item.GetChave() < p->item.GetChave())
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}

void ArvoreBinaria::RemoveRecursivo(TipoNo* &no, TipoChave chave){
    TipoNo *aux;
    if (no == NULL) {
        throw("Item nao está presente");
    }
    if (chave < no->item.GetChave())
        return RemoveRecursivo(no->esq, chave);
    else if (chave>no->item.GetChave())
        return RemoveRecursivo(no->dir, chave);
    else {
        if (no->dir == NULL) {
            aux = no;
            no = no->esq;
        free(aux);
    }
    else if(no->esq == NULL) {
        aux = no;
        no = no->dir;
        free(aux);
    }
    else
        Antecessor(no, no->esq);
    }
}

int main(){
    char assassino[9], assassinado[9]; 
    
    while(scanf("%s %s", assassino, assassinado)!=EOF){
        Insere(assassino)
    }
}