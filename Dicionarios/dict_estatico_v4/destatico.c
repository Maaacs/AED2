#include "destatico.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct estatistica{
  int nro_cmp;
  int nro_bsc;
}Estatistica;

struct destatico{
    void* *entradas;
    int tamanho;
    int ocupacao;

    TCompararDE comparar;

    Estatistica statistics;
};

TDEstatico* criar_DE(int tamanho, TCompararDE comparar){
    TDEstatico *de = malloc(sizeof(TDEstatico));
    de->tamanho = tamanho;
    de->ocupacao = 0;
    de->comparar = comparar;

    de->entradas = malloc(sizeof(void*)*de->tamanho);

    
    de->statistics.nro_bsc = 0;
    de->statistics.nro_cmp = 0;

    return de;
}


void* buscar_DE(TDEstatico* de, void* chave){

  de->statistics.nro_bsc++;

  void* entrada=NULL;
  int inicio=0;
  int fim = de->ocupacao-1;
  short encontrou = 0; // falso
  while( (!encontrou) && (inicio<=fim)){
      int meio = (inicio+fim)/2;
      int status = de->comparar(de->entradas[meio], chave);
      if (status == 0){
        de->statistics.nro_cmp+=1;
        encontrou=1; //verdade
        entrada = de->entradas[meio];
      }else if(status > 0){
        de->statistics.nro_cmp+=2;
        fim = meio-1;
      }else{
        de->statistics.nro_cmp+=3;
        inicio = meio+1;
      }
  }
  return entrada;
}

int ocupacao_DE(TDEstatico* de){
    return de->ocupacao;
}

void carga_DE(TDEstatico* de, void* info){
  de->entradas[de->ocupacao] = info;
  de->ocupacao++;
}

void dashboard_DE(TDEstatico *de){
  printf("Nro buscas: %d\n", de->statistics.nro_bsc );
  printf("Nro comparacoes: %d\n", de->statistics.nro_cmp );
  printf("Media comparacoes por busca: %.2lf\n", (double) de->statistics.nro_cmp/de->statistics.nro_bsc );
}
