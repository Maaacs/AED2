#include "stdio.h"
#include "stdlib.h"
#include "abb.h"

//Árvore binária de busca

typedef struct no TNo;
struct no {
  void* info;
  TNo* sae;
  TNo* sad;
  TNo* pai;
};

TNo* criarNO(void* carga){
  TNo *no = malloc(sizeof(TNo));
  no->pai = NULL;
  no->sae = NULL;
  no->sad = NULL;
  no->info = carga;

  return no;
}

struct ABB{
  // callbacks
  // TImprimirABB impressora;
  TCompararABB comparar;
  // TDestroyABB destroy;

  TNo* raiz;
  int tamanho;
//  int altura;
};

TABB* criarABB (TCompararABB comparar){
  TABB *abb = malloc(sizeof(TABB));  

  abb->comparar = comparar;

  abb->raiz = NULL;
  abb->tamanho = 0;
  return abb;
}

// funcao recursiva
static TNo* _inserirABB(TNo *raiz, void *info, TCompararABB comparar){
    // raiz nula é a base da recursão
    if(raiz == NULL){
        return criarNO(info);
    }else{
        // se a nova informação for menor que a raiz, insere na esquerda
        if (comparar(raiz->info, info)>0){ // raiz > nova informação | ==0 raiz igual a nova informacao | <0 raiz maior que nova informacao
            // insere no lado esquerdo
            TNo *no = _inserirABB(raiz->sae, info, comparar);
            no->pai = raiz;
            raiz->sae = no;
        }else{
            TNo *no = _inserirABB(raiz->sad, info, comparar);
            no->pai = raiz;
            raiz->sad = no;
        }
        return raiz;
    }
}

void inserirABB(TABB *abb, void *info){
  abb->raiz = _inserirABB(abb->raiz, info, abb->comparar);
  abb->tamanho++;
}

