#include "stdio.h"
#include "stdlib.h"
#include "lista.h"

typedef struct { // atributos de uma pessoa
  long int rg;
  double altura;
  int idade;
  double peso;
} TPessoa;

void imprimirPessoa(void* carga){
  TPessoa* Pessoa = carga;
  //printf("%d %lf\n", Pessoa.matricula, Pessoa.nota);
  printf("%ld %lf %lf %d\n", Pessoa->rg, Pessoa->altura, Pessoa->peso, Pessoa->idade);
  //printf("Vou imprimir a Pessoarmação\n");

}

int compararPessoa(void* cargautil, void *chave){
    //tipo como uma lupa que vai olhar para o primeiro campo da lista (pode ser int tbm, char). 
    //Caso queria olhar para os demais campos(n seguro), deve-se somar os bytes dos campos anteriores.
  long int *rg = chave;

     //casting que permitirá acessar os campos da lista
  TPessoa* Pessoa = cargautil;
    //Apos os casting, podemos acessar o campo rg
  return Pessoa->rg - *rg;
}


int main(int argc, char const *argv[]) {
  //printf("%lu %lu\n", sizeof(int*), sizeof(double*));
  long int rg;
  double peso, altura;
  int idade;

  TListaSE* lista_pessoas = criarLSE(imprimirPessoa, compararPessoa);
  scanf("%ld", &rg);
  while(rg > 0){
    scanf("%lf %lf %d", &altura, &peso, &idade);


    TPessoa *novo = malloc(sizeof(TPessoa));
    novo->rg=rg;
    novo->peso=peso;
    novo->altura = altura;
    novo->idade = idade;

    inserirFinalLSE(lista_pessoas, novo);
    scanf("%ld", &rg);
  }
  imprimirLSE(lista_pessoas);
  scanf("%ld", &rg);
  
  TPessoa* procurado = buscarConteudoLSE(lista_pessoas, &rg);
  if(procurado != NULL){
      imprimirPessoa(procurado);
  }else{
      printf("Procurado não encontrado!");
  }

  return 0;

}
