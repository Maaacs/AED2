#include "buffer.h"
#include <stdlib.h>

// Um buffer contém um array de caracteres, a primeira posição livre no
// array e o tamanho do array. A matriz NÃO é terminada em nulo.
// typedef struct {
//   int primeiraPosicaoLivre;
//   int capacidade;
//   char *data;
// } Buffer;

Buffer *create_buffer(){
  Buffer *ret = malloc(sizeof(Buffer));

  if (!ret){
    return 0;
  } 

  ret->primeiraPosicaoLivre = 0;
  ret->capacidade = 2;
  ret->data = malloc(ret->capacidade * sizeof(char));

  if (!ret->data){
    return 0;
  }

  return ret;
}


void destroy_buffer(Buffer *B){
  free(B->data);
  free(B);
}


int buffer_add_char(Buffer *B, char c){
  if (B->primeiraPosicaoLivre == B->capacidade) {
    //se tiver cheio aumentamos o tamanho
    char *tmp = malloc(2 * B->capacidade * sizeof(char));

    if (!tmp) return 0;

    for (int i = 0; i < B->capacidade; i++) tmp[i] = B->data[i];

    free(B->data);
    B->data = tmp;
    B->capacidade *= 2;
  }

  B->data[B->primeiraPosicaoLivre++] = c;

  return 1;
}


int buffer_add_str(Buffer *B, char *s){
  while (*s && buffer_add_char(B, *s++));

  return !(*s);
}


void clear_buffer(Buffer *B){
  B->primeiraPosicaoLivre = 0;
}