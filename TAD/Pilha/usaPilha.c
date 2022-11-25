#include "stdio.h"
#include "pilha.h"
#include "string.h"
#include "stdlib.h"
#include "livro.h" // incluindo bib

/*struct livro{
    char titulo[60];
    int anoPubl;
};

typedef struct livro TLivro; //tipo livro

TLivro* criar_livro(char *titulo, int anoPubl){
    TLivro *l = malloc(sizeof(TLivro));

    strcpy(l->titulo, titulo); //tem que passar cada elemento do vetor de char, por isso fazer uma copia com strcpy
    l->anoPubl = anoPubl;

    return l;
}

void imprimir_livro(TLivro* l){
    printf("%s %d\n", l->titulo, l->anoPubl);
}*/


int main(int argc, char const *arqv[]){

    TPilha* para_ler = criar_pilha(0);

    char titulo[60];
    int anoPubl;

    scanf("%s", titulo);
    while (strcmp(titulo, "FIM") != 0){
        scanf("%d\n", &anoPubl);

        TLivro* exemplar = criar_livro(titulo, anoPubl);
        empilhar(para_ler, exemplar);
        scanf("%s", titulo);
    }

    TLivro* topo = otopo_pilha(para_ler);
    //imprimir_livro(topo);
    free(topo);
    topo = desempilhar(para_ler);
    printf("altura: %d\n", altura_pilha(para_ler));

    
    return 0;
}