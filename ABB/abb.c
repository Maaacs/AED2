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
  TImprimirABB impressora;
  TCompararABB comparar;
  TDestroyABB destroy;

  TNo* raiz;
  int tamanho;
//  int altura;
};

TABB* criarABB (TCompararABB comparar, TImprimirABB IMPRESSORA, TDestroyABB destroy){
  TABB *abb = malloc(sizeof(TABB));  

  abb->impressora = IMPRESSORA;
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

static void _imprimirNo(TNo *no, TImprimirABB impressora){
  if (no == NULL) {
    return;
  }
  _imprimirNo (no->sae, impressora);
  impressora (no->info);
  _imprimirNo (no->sad, impressora);
}

void imprimirABB(TABB *abb) {
  _imprimirNo (abb->raiz, abb->impressora);
}

static TNo* _buscarNo (TNo *raiz, void *buscado, TCompararABB comparar) {
  TNo *sae, *sad;
    if (raiz == NULL) {
      return NULL;
    }
  short status = comparar (raiz->info,buscado);
  if (status==0){
    return raiz;
  }else if (status > 0){
    return _buscarNo (raiz->sae, buscado, comparar);
  }else{
    return _buscarNo (raiz->sad, buscado, comparar);
  }
}


void *buscarABB(TABB *abb, void *buscado){
  TNo *no = _buscarNo (abb->raiz, buscado, abb->comparar);
  return (no?no->info:NULL);
}


#define MAX(a,b) (a>b?a: b)
static int _alturaABB (TNo *no) {
  if (no == NULL) { 
    return -1;
  }else{
    return (MAX(_alturaABB (no->sae), _alturaABB(no->sad)) + 1);
  }
}

int alturaABB (TABB *ab) {
  TNo *raiz = ab->raiz;
  int altura = _alturaABB(raiz);
  return altura;
}


static int _tamanhoNo (TNo *raiz){// atualiz sempre o tamanho
  if (raiz==NULL) {
    return 0;
  }
  return _tamanhoNo (raiz->sae) + _tamanhoNo (raiz->sad) + 1;
}


int tamanhoABB (TABB *abb) {
  return _tamanhoNo (abb->raiz); // opcao 1
  // return abb->tamanho; // opcao 2
}

void* _podarNo (TNo* raiz, TDestroyABB destroy) {
  if (raiz==NULL)
    return NULL;
  
  raiz->sae = _podarNo (raiz->sae, destroy);
  raiz->sad = _podarNo (raiz->sad, destroy);
  destroy (raiz->info);
  free (raiz);
  return NULL;
}

void podarABB (TABB *abb, void *chave) {
  TNo *podavel = _buscarNo (abb->raiz, chave, abb->comparar);
  if (podavel != NULL) {
    int podas=_tamanhoNo (podavel) ;
    abb->tamanho -= podas;
    
    TNo* pai = podavel->pai;

    if (pai==NULL) { // podando a raiz?
      abb->raiz = _podarNo (podavel, abb->destroy); // destroy funcao especialista que remove
    }else if (pai->sae == podavel) { // podando a subarvore esquerda ?
      pai->sae = _podarNo (podavel, abb->destroy);
    }else{ // podando a subarvore direita?
      pai->sad = _podarNo (podavel, abb->destroy); 
    }
  }
}

void static _trocarInfo(TNo *n1, TNo *n2){
  void *aux = n1->info;
  n1->info = n2->info;
  n2->info = aux;
}

