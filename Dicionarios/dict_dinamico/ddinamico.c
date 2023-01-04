#include "stdio.h"
#include "assert.h"
#include "stdlib.h"
#include "lista.h"
#include "ddinamico.h"

struct ddinamico{
    // dados
    int tamanho;
    int nro_elementos; //numero de elementos (ocupacao)

    TListaSE* *entradas; // vetor dinamico de ponteiros para listas encadeadas
    // estatística

    int nro_consulta;
    int nro_busca;
    int nro_insercao;
    int nro_remocao;
    long int nro_cmps_por_rmc;
    long int nro_cmps_por_bsc;
};

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

typedef struct entrada{
    int chave;
    void* info;
}TEntradaDD;

TEntradaDD* criar_entrada_DD(int chave, void* info){ //retorna ponteiro
    TEntradaDD* e = malloc(sizeof(TEntradaDD));
    e->chave = chave;
    e->info = info;

    return e;
}

int compararEntradaDD (void* e1, void* e2){
    TEntradaDD* ee1 = e1;
    TEntradaDD* ee2 = e2;

    return (ee1->chave - ee2->chave); // ==0 se forem iguais,  <0 se primeiro for menor,  >0 se primeiro for maior
}

TDDinamico* criar_DD(int tamanho){
    TDDinamico* dd = malloc(sizeof(TDDinamico));

    dd->tamanho = primo_proximo(tamanho);
    dd->nro_elementos = 0;
    dd->entradas = malloc(sizeof(TListaSE*)*dd->tamanho); //multiplica pelo tamanho /sizeof de ponteiro (TListaSE)
    
    for(int i=0; i<dd->tamanho; i++){
        dd->entradas[i] = criarLSE(NULL,compararEntradaDD);
        //dd->entradas[i] = criarLSE(NULL, comparar);//se quiser comparar
    }
    dd->nro_busca = dd->nro_consulta = dd->nro_insercao = 0;
    dd->nro_cmps_por_bsc = dd->nro_cmps_por_rmc = 0;

    return dd;
}

void inserir_DD(TDDinamico *dd, int chave, void* info){
    int k = hashing(dd, chave);
    TListaSE* l =  dd->entradas[k];
    //pode fazer uma busca primeiro antes de inserir para verificar se a chave ja existe em uma palavra no dicionario
    inserirInicioLSE(l, criar_entrada_DD(chave, info));

    dd->nro_elementos++;
    dd->nro_elementos++;
}

void* buscar_DD(TDDinamico *dd, int chave){
    int k = hashing(dd, chave);
    TListaSE* l =  dd->entradas[k];
    //buscarConteudoLSE(l, (void*)&chave); //endereço de um inteiro convertido para void (casting), pois a funcao buscarConteudoLSE espera void e nao int
    TEntradaDD* e = buscarConteudoLSE(l, &chave);

    //para gerar estatística
    dd->nro_busca++;
    dd->nro_cmps_por_bsc = dd->nro_cmps_por_bsc + tamanhoLSE(l);

    return (e?e->info:e); //se existir info retorna info, senao retorna null
}

void* remover_DD(TDDinamico *dd, int chave){
    int k = hashing(dd, chave);
    TListaSE* l =  dd->entradas[k];

    TEntradaDD* e  = removerConteudoLSE(l, &chave);

    void* info = NULL;
    if( e != NULL){
        void* info = e->info;
        free(e);
    }

    dd->nro_remocao++;
    dd->nro_cmps_por_rmc += tamanhoLSE(l);

    return info;
}