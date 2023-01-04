#include "stdio.h"
#include "assert.h"
#include "stdlib.h"
#include "lista.h"

struct ddinamico{
    // dados
    int tamanho;
    int nro_elementos; //numero de elementos (ocupacao)

    TListaSE* *entradas; // vetor dinamico de ponteiros para listas encadeadas
    // estatística

    int nro_consulta;
    int nro_busca;
    int nro_insercao;
    long int nro_cmps_por_rmc;
    long int nro_cmps_por_bsc;
};

typedef int (* TCompararDD)(void*, void*);
typedef struct ddinamico TDDinamico;


static int hashing(TDDinamico* dd, int chave){
    return (chave % dd->tamanho);
}

static int primo_proximo(int num){
    short encontrou = 0;
    while(!encontrou){
        int i=2;
        while((i<num) && ((num%i)!=0)){
            i++;
        }
        if(i == num){
            encontrou=1;
        }else{
            num+=1;
        }
    }
    return num;
}

TDDinamico* criar_DD(int tamanho, TCompararDD comparar){
    TDDinamico* dd = malloc(sizeof(TDDinamico));

    dd->tamanho = primo_proximo(tamanho);
    dd->nro_elementos = 0;
    dd->entradas = malloc(sizeof(TListaSE*)*dd->tamanho); //multiplica pelo tamanho
    
    for(int i=0; i<dd->tamanho; i++){
        dd->entradas[i] = criarLSE(NULL,NULL);
        //dd->entradas[i] = criarLSE(NULL, comparar);//se quiser comparar
    }
    dd->nro_busca = dd->nro_consulta = dd->nro_insercao = 0;
    dd->nro_cmps_por_bsc = dd->nro_cmps_por_rmc = 0;

    return dd;
}

void inserir_DD(TDDinamico *dd, int chave, void* info){

}

void* buscar_DD(TDDinamico *dd, int chave){

  return NULL;
}

void* remover_DD(TDDinamico *dd, int chave){
  return NULL;
}