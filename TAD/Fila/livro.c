#include "stdio.h"
#include "stdlib.h"
#include "string.h" //chamando a bib
#include "livro.h"


struct livro{
    char titulo[60];
    int anoPubl;
};

//typedef struct livro TLivro; //tipo livro

TLivro* criar_livro(char *titulo, int anoPubl){
    TLivro *l = malloc(sizeof(TLivro));

    strcpy(l->titulo, titulo); //tem que passar cada elemento do vetor de char, por isso fazer uma copia com strcpy
    l->anoPubl = anoPubl;

    return l;
}

void imprimir_livro(TLivro* l){
    printf("%s %d\n", l->titulo, l->anoPubl);
}
