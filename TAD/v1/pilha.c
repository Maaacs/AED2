#include "stdio.h"
#include "stdlib.h"
#include "lista.h"
#include "pilha.h"

struct pilha{
    TListaSE* itens;
    int altura;
};

typedef struct pilha TPilha;

TPilha* criar_pilha(){
    TPilha* p = malloc(sizeof(TPilha));
    p->altura = 0;
    p->itens = criarLSE(NULL, NULL);

    return p;
}

                        //void* item (generico)
int empilhar(TPilha* p, void* item){
    int status = 1; // verdade, ocorreu o empilhamento
    if(p != NULL){
        inserirInicioLSE(p->itens, item);
        p->altura++;
    }else{
        status = 0; //falso, nao ocorreu o empilhamento
    }
    return status;
}

void* desempilhar(TPilha* p){
    void* item = NULL;

    if((p != NULL) && (p->altura>0)){ // se a pilha existe e possui pelo menos 1 elemento
        item = removerInicioLSE(p->itens); // remove item do topo
        p->altura--; // ao remover,  a aultra precisa ser decrementada
    }
    return item;
}

void* topo_pilha(TPilha* p){ // acessar o topo da pilha
    void* item = NULL;

    if((p != NULL) && (p->altura>0)){
        item = acessarLSE(p->itens,1); // o topo eh o primeiro elemento
    }
    return item;
}

int altura_pilha(TPilha* p){
    if(p != NULL)
        return p->altura;
    else
        return -1; // pilha indefinida
}