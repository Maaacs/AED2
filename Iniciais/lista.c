#include <stdio.h>

typedef struct info{
    char placa[10];
    char end[80];
    int CNH;
}TInfo;

typedef struct elem{
    TInfo info;
    struct elem *prox;
}TElemSE;

TElemSE* criarElemento (TInfo info){
    TElemSE *n = malloc (sizeof(TElemSE));
    n->info = info;
    n->prox= NULL;
    return n;
}

typedef struct lista{
    TElemSE *inicio;
    int tam;
}TLista;

inserirLSE(TLista *lse, TElemSE *novo){
    if(lse->inicio == NULL){
        lse->inicio = novo;
    }else{
        novo->prox = lse->inicio;
        lse->inicio = novo;
    }

}