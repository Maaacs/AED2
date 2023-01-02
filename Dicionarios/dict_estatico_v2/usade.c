#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "destatico.h"

typedef struct pessoa{
  int idade;
  char nome[100];
  char apelido[20];
} TPessoa;

TPessoa* criar_pessoa(int idade, char nome[], char apelido[]){
    TPessoa* p = malloc(sizeof(TPessoa));
    p->idade = idade;
    strcpy(p->nome, nome);
    strcpy(p->apelido, apelido);

    return p;
}

void imprimir_pessoa(TPessoa *p){
  printf("idade: %d\nnome: %s\napelido: %s\n", p->idade, p->nome, p->apelido);
}


int main(int argc, char const *argv[]) {
  /* code */
  TDEstatico* pessoas =  criar_DE(100);
  // TPessoa* fulano = criar_pessoa(50, "maria da silva", "maria");
  // TEntradaDic entrada = criar_entrada(404176, fulano);
  // carga_DE(pessoas, entrada);

  char nome[100], apelido[20];
  for (int i=1;i<=100;i++){
    sprintf(nome,"joao da silva %d", i);
    sprintf(apelido, "joao %d", i);
    TPessoa* fulano = criar_pessoa(55, nome, apelido);
    TEntradaDic entrada = criar_entrada(404177+i, fulano);
    carga_DE(pessoas, entrada);
  }

  for (int i=1;i<1000;i++){
    TPessoa* fulano = buscar_DE(pessoas, 404176+i);
    if (fulano)
      imprimir_pessoa(fulano);
  }

  dashboard_DE(pessoas);

  return 0;
}
