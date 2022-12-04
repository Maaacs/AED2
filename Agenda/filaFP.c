#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "filaFP.h"



struct filaPrioridade{
    int ocupacao;
    int tamanho;
    short e_infinita;
    TCompararFP compararFP; //endereço da função especialista
    //int* elems[]; // vetor que contém endereços para inteiros
    //int* *elems;// vetor que contém endereços para inteiros (só que com * tira a necessiade de usar [])
    void* *elems;  // vetor que contém endereços para tipo genérico (nesse caso nossa agenda)
};

//typedef struct fila TFila; // foi pro filaFP.h

TFilaPrioridade* criar_fila_FP(int tamanho, TCompararFP comparar){
    TFilaPrioridade* f = malloc(sizeof(TFilaPrioridade)); //aloca a struct na memoria
    //f->tamanho = tamanho;
    //tamanho = (tamanho>0?tamanho:4); //se tamanho da fila for infinita (tam<0), define o tamanho inicial para 4
    f->tamanho = (tamanho>0?tamanho:4);
    f->e_infinita = (tamanho>0?0:1);

    //inicializando
    f->elems = malloc(sizeof(void*)*f->tamanho); // aloca os elementos na memoria
    f->ocupacao=0;

    f->compararFP = comparar;

    return f;
}

static void trocar (void* elems[], int i, int j){
    void* aux = elems[i];
    elems[i] = elems[j];
    elems[j] = aux;
}

void enfileirar_FP(TFilaPrioridade *f, void* elem){ // enfileira novos eventos
    if((f->e_infinita) && (f->ocupacao == f->tamanho)){ // redefinindo o tamanho
        f->tamanho *= 2; // tamanho é igual a multiplicacao de tamanho por 2
        f->elems = realloc(f->elems, sizeof(void*)*f->tamanho);
    }
    f->elems[f->ocupacao] = elem;
    f->ocupacao++;
    //validar a propriedade da ordem
    int i = f->ocupacao-1;
    int pai = floor((i-1/2));
    while((i!=0) && (f->compararFP(f->elems[pai], f->elems[i]) < 0)){ //menor do que zero signfica que o pai é maior que o filho
        trocar(f->elems, i, pai);
        i = pai;
        pai = floor((i-1)/2); //retorna o maior inteiro menor ou igual a x (ou seja, arredonda para baixo)
        
    }
}

// desenfileirar_FP()
// destroy_FP()