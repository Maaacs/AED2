#include "stdio.h"
#include "ab.h"

//Árvore binária

struct no {
    void* info;
    TNo* sae;
    TNo* sad;
    TNo* pai;
};

TNo* criarNo(TNo* pai, void *c){
    TNo* p=malloc(sizeof(TNo));
    p->info = c;
    p->sae = NULL;
    p->sad = NULL;
    p->pai = pai;
    return p;
}

TNo* inserirAB(TNo* raiz, void *info){
    if(raiz == NULL){
        TNo *novo = criarNo(info);
        return novo;
    }
    if(sorteio(0,1) == 1){
        TNo* sae = inserirAB(raiz->sae, info);
        conectaRaizSAE(raiz, sae);
    }else{
        TNo *sad = inserirAB(raiz->sad,info);
        conectarRaizSAD(raiz,sad);
    }
    return raiz;
}

void imprimir (TNo* raiz){
    if (raiz == NULL){
        return  0;
    }
    print(raiz->info);
    imprimir(raiz->sae);
    imprimir(raiz->sad);
}

int buscar (TNo* a, void *chave){
    if (vazia(a)){
        return 0;
    }else{
        void *e = a->info;
        return (comparar(0, chave) == 0) || buscar(a->sad,chave);
    }
}

void destruir (TNo* a){
    if (vazia(a)){
        return 0;
    }else{
        destruir(a->sae);
        destruir(a->sad);
        free(a);
    }
}