#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "agenda.h"
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

TFilaPrioridade* criar_FP(int tamanho, TCompararFP comparar){
    TFilaPrioridade* f = malloc(sizeof(TFilaPrioridade)); //aloca a struct na memoria
    //se tamanho da fila for infinita (tam<0), define o tamanho inicial para 4
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

int enfileirar_FP(TFilaPrioridade *f, void* elem){ // enfileira novos eventos

    if(!(f->e_infinita) && (f->ocupacao == f->tamanho)){// lista finita está cheia
        return 0;
    }
    if((f->e_infinita) && (f->ocupacao == f->tamanho)){ // aumentando o tamanho (para lista infinita)
        f->tamanho *= 2; // tamanho é igual a multiplicacao de tamanho por 2
        f->elems = realloc(f->elems, sizeof(void*)*f->tamanho);
    }
    //enfileira os elementos
    f->elems[f->ocupacao] = elem;
    f->ocupacao++;
    
    //validar a propriedade da ordem
    int i = f->ocupacao-1;
    int pai = floor((i-1/2)); //retorna o maior inteiro menor ou igual a x (ou seja, arredonda para baixo) 
    while((i!=0) && (f->compararFP(f->elems[pai], f->elems[i]) < 0)){ //menor do que zero signfica que o pai é maior que o filho // vai olhar para o primeiro campo da lista (prioridade)
        trocar(f->elems, i, pai);
        i = pai;
        pai = floor((i-1)/2); //retorna o maior inteiro menor ou igual a x (ou seja, arredonda para baixo)   
    }
    // enfileirou
    return 1;
}

// remove o primeiro elemento na fila com prioridade
void* desenfileirar_FP (TFilaPrioridade* f){ // nesse formato TFila* f pq queremos trazer um elemento para cá
    TipoAgendaLSE* l;

    if (f-> ocupacao == 0){ // para o caso em que a fila está vazia
        return NULL;
    }

    void* elem = f->elems[0]; //elemento de tipo genérico com maior prioridade
    f->ocupacao--;
    trocar(f->elems, 0, f->ocupacao);
    //validar a propriedade da ordem
    int i, imaior = 0; // nesse instante, i e imaior "está no" pai
    
    do{ // toda vez que encontra-se um filho maior na esquerda ou à direita, deve-se trocar pelo pai
        i = imaior;
        int iesq = 2*i+1; // filho à esquerda
        int idir = 2*i+2; // filho à direita

        if((iesq < f->ocupacao) && (f->compararFP(f->elems[i], f->elems[iesq]) < 0)){ //se o filho é maior que o pai
            imaior = iesq;
        }
        if((idir < f->ocupacao) && (f->compararFP(f-imaior, f->elems[idir]) < 0)){// filho da direita é o maior entre os 3
            imaior = idir;
        }
        trocar(f->elems, i , imaior);

    }while(i!=imaior);

    return elem;
}


void destroy_FP(TFilaPrioridade* f){
    if (f->ocupacao == 0){ // para o caso em que a fila está vazia
        f = NULL;
    }else{
        int i = 0;
        void* elem = f->elems[i]; //recebe primeiro elemento do vetor
        while((f->elems[i]) != NULL){
            void* aux = elem;
            void* elem = f->elems[i+1];//recebe o proximo
            free(aux);
            i++;
        }   
    }
}


// int tamanho_filaFP (TFilaPrioridade* f){
//     return f->ocupacao;
// }

