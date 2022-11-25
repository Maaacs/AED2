#include "stdio.h"
#include "fila.h"
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

    TFila* para_ler = criar_fila(3);

    char titulo[60];
    int anoPubl;

    scanf("%s", titulo);
    while (strcmp(titulo, "FIM") != 0){
        scanf("%d\n", &anoPubl);

        TLivro* exemplar = criar_livro(titulo, anoPubl);
        enfileirar(para_ler, exemplar);
        scanf("%s", titulo);
    }

    TLivro* primeiro = desenfileirar(para_ler);
    imprimir_livro(primeiro);
    free(primeiro); //precisa liberar pq o primeiro é uma referencia ao elemento do vetor desempilhado. Portanto, embora no vetor, o elemento nao esteja mais
                    // sendo referenciado, a variavel primeiro ainda contem esse elemento, portanto apos imprimir pode desempilhar

    printf("tamanho: %d\n", tamanho_fila(para_ler));

    
    return 0;
}