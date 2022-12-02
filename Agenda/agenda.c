#include "stdio.h"
#include "stdlib.h"
#include "string.h" //chamando a bib
#include "agenda.h"


struct agenda{
    char titulo[60];
    char diaMesAno[8];
    char hora[5];
    char local[20];
    char descricao[30];
};

//typedef struct agenda TAgenda; //tipo livro

TAgenda* criar_agenda(char *titulo, char *diaMesAno, char *hora, char *local, char *descricao){
    TAgenda *l = malloc(sizeof(TAgenda));

    strcpy(l->titulo, titulo); //tem que passar cada char do vetor de char, por isso fazer uma copia com strcpy
    strcpy(l->diaMesAno, diaMesAno);
    strcpy(l->hora, hora);
    strcpy(l->local, local);
    strcpy(l->descricao, descricao);

    return l;
}

void imprimir_agenda(TAgenda* l){
     printf("%s %s %s %s %s\n", l->titulo, l->diaMesAno, l->hora, l->local, l->descricao);
}



