#include "stdio.h"
#include "stdlib.h"
#include "pilha.h"

struct pilha{
  //TListaSE* itens; //nao eh mais lista
  void* *itens; //cada compartimento desse vetor de ponteiro armazena um ponteiro de tipo genérico
  int topo; //indice do elemento topo
  int altura;
  int altura_max; // se igual a zero, então é infinita
};

TPilha* criar_pilha(int altura_max){

  TPilha* p = malloc(sizeof(TPilha));
  p->altura = 0;
  p->topo = -1;
  p->altura_max = altura_max;
  //p->itens = criarLSE(NULL,NULL);
  int k_itens = (altura_max>0?altura_max:2);//se altura_max for maior que 0, pega altura_max. Senão, usa 2. (se pilha for infinita comeca com 2)
  p->itens = malloc(sizeof(void*)*1000);
  return p;
}

int empilhar(TPilha* p, void* item){
  int status = 1; // verdade, ocorreu o empilhamento
  if((p!=NULL) && ((p->altura_max==0) || (p->altura < p->altura_max))){
    //inserirInicioLSE(p->itens, item);
    p->topo++;
    p->itens[p->topo] = item;
    p->altura++;
  }else{
    status=0; // falso, não ocorreu o empilhamento
  }
  return status;
}

void* desempilhar(TPilha* p){
  void* item = NULL;
  if((p!=NULL) && (p->altura>0)){
    //item = removerInicioLSE(p->itens);
    item = p->itens[p->topo];
    p->topo--; //onde está o indice do vetor

    p->altura--; //só uma informação da altura
  }
  return item;
}

void* otopo_pilha(TPilha* p){
  void* item = NULL;
  if ((p!=NULL) && (p->altura>0)){
    //item = acessarLSE(p->itens,1);
    int k = p->topo;
    item = p->itens[k];
  }
  return item;
}

int altura_pilha(TPilha* p){
  if (p!=NULL)
    return p->altura;
  else
    return -1; // pilha indefinida
}
