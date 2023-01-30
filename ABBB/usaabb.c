#include "stdio.h"
#include "stdlib.h"
#include "abb.h"
#include "assert.h"

typedef struct palavra{
    int ocorrencia;
    int pagina;
}TPalavra;

TPalavra* criarPalavra(int ocorrencia, int pagina){
    TPalavra* p = malloc(sizeof(TPalavra));
    p->pagina = pagina;
    p->ocorrencia = ocorrencia;
    return p;
}
void destruirPalavra(void* palavra){
    free(palavra);
}

void imprimirPalavra(void *palavra) {
    TPalavra* p = palavra;
    printf ("Pagina: %d Ocorrencia: %d\n" , p->pagina, p->ocorrencia);
}

int compararPalavra(void* p1, void* p2){
    // casting
    TPalavra *pp1 = p1;
    TPalavra *pp2 = p2;

    //insere as palavras baseado na página
    return (pp1->pagina - pp2->pagina);
}

int main(int argc, char const *argv[]){
    TABB* dasPalavras = criarABB(compararPalavra, imprimirPalavra, destruirPalavra);
    assert(dasPalavras!=NULL);
    int pagina, ocorre;
    scanf("%d", &pagina);
    while(pagina!=-1){
        scanf("%d", &ocorre);
        TPalavra* p = criarPalavra(ocorre, pagina);
        inserirABB(dasPalavras, p );
        scanf("%d", &pagina);
    }
    imprimirABB(dasPalavras);

    scanf ("%d", &pagina);
    while (pagina!=-1) {
        podarABB(dasPalavras, &pagina);
        scanf ("%d", &pagina);
        printf("=====>Podado:%d\n", pagina);
        imprimirABB (dasPalavras);
    }

    return 0;
}