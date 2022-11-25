#include "stdio.h"
#include "stdlib.h"
#include "lista.h"

typedef struct { // atributos de um computador
  long int serial;
  char processador;
  int RAM;
  int ssd;
  char placaDeVideo;
} TMaquina;

void imprimirMaquina(void* carga){
  TMaquina* PC = carga;
  //printf("%d %lf\n", Pessoa.matricula, Pessoa.nota);
  printf("%ld %c %d %d %c\n", PC->serial, PC->processador, PC->RAM, PC->ssd, PC->placaDeVideo);
  //printf("Vou imprimir a Pessoarmação\n");

}

int compararPessoa(void* cargautil, void *chave){
    //tipo como uma lupa que vai olhar para o primeiro campo da lista (pode ser int tbm, char). 
    //Caso queria olhar para os demais campos(n seguro), deve-se somar os bytes dos campos anteriores.
  long int *serial = chave;

     //casting que permitirá acessar os campos da lista
  TMaquina* Maquina = cargautil;
    //Apos os casting, podemos acessar o campo rg
  return Maquina->serial - *serial;
}


int main(int argc, char const *argv[]) {
  //printf("%lu %lu\n", sizeof(int*), sizeof(double*));
  long int serial;
  char processador;
  int RAM, ssd;
  char placaDeVideo;

  TListaSE* lista_maquinas = criarLSE(imprimirMaquina, compararPessoa);
  scanf("%ld", &serial);
  while(serial > 0){
    scanf("%c %d %d %c", &processador, &RAM, &ssd, &placaDeVideo);


    TMaquina *novo = malloc(sizeof(TMaquina));
    novo->serial=serial;
    novo->processador=processador;
    novo->RAM = RAM;
    novo->ssd = ssd;
    novo->placaDeVideo = placaDeVideo;

    inserirFinalLSE(lista_maquinas, novo);
    scanf("%ld", &serial);
  }
  imprimirLSE(lista_maquinas);
  scanf("%ld", &serial);
  
  TMaquina* maquina = buscarConteudoLSE(lista_maquinas, &serial);
  if(maquina != NULL){
      imprimirMaquina(maquina);
  }else{
      printf("Procurado não encontrado!");
  }

  return 0;

}
