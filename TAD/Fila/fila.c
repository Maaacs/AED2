#include "stdio.h"
#include "stdlib.h"
#include "fila.h"

struct fila{
    int ocupacao;
    int primeiro;
    int ultimo;
    int tamanho;
    short e_infinita;
    //int* elems[]; // vetor que contém endereços para inteiros
    //int* *elems;// vetor que contém endereços para inteiros (só que com * tira a necessiade de usar [])
    void* *elems;  // vetor que contém endereços para tipo genérico
};

//typedef struct fila TFila; // foi pro fila.h

TFila* criar_fila(int tamanho){
    TFila* f = malloc(sizeof(TFila)); //aloca a struct na memoria
    //f->tamanho = tamanho;
    //tamanho = (tamanho>0?tamanho:4); //se tamanho da fila for infinita (tam<0), define o tamanho inicial para 4
    f->tamanho = (tamanho>0?tamanho:4);
    f->e_infinita = (tamanho>0?0:1);

    //inicializando
    f->elems = malloc(sizeof(void*)*f->tamanho); // aloca os elementos na memoria
    f->primeiro=0;
    f->ultimo=-1;
    f->ocupacao=0;

    return f;
}

void enfileirar (TFila *f, void* elem){ // enfileira elementos // nesse formato TFIla *f, pq queremos inserir um cara
//enfileirar uma lista circular

    // vai enfileirar no ultimo + 1 [0,1,2,(novo -> ultimo+1), , ] // 3%6(assumindo tamanho 6 do vetor)= resto 3 (insere na posicao 3)
    f->ultimo = (f->ultimo+1 % f->tamanho); // essa operação já gera o ciclo

    if((f->e_infinita) && (f->ocupacao == f->tamanho)){ // redefinindo o tamanho
        f->tamanho *= 2; // tamanho é igual a multiplicacao de tamanho por 2
        f->elems = realloc(f->elems, sizeof(void*)*f->tamanho);

        if(f->ultimo < f->primeiro){
            //reposicionar os elementos
        }
    }
    f->elems[f->ultimo] = elem;
    f->ocupacao++;
}

void* desenfileirar (TFila* f){ // nesse formato TFila* f pq queremos trazer um cara

    if (f-> ocupacao > 0){
        void* elem = f->elems[f->primeiro]; //podemos enfileirar um elemento de tipo genérico
        f->primeiro = (f->primeiro+1 % f->tamanho); // fila circular
        f->primeiro++;

        f->ocupacao--;
        if(f->ocupacao == 0){ // restabalece a condiçao inicial de uma fila vazia
            f->primeiro=0;
            f->ultimo=-1;
        }
        return elem;
    }
    return NULL;
}

int tamanho_fila (TFila* f){
    return f->ocupacao;
}