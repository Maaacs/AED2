#include "destatico.h"
#include "stdio.h"

// typedef struct entrada{
//     int chave;
//     void* info;
// }TEntradaDic;
// typedef struct destatico{
//     TEntradaDic entradas[100];
//     int tamanho;
//     int ocupacao;
// }TDEstatico;

struct entrada{
    int chave; // cada info está associada à uma chave. Podemos realizar as buscas a partir dessas chaves.
    void* info;
};

struct destatico{
    TEntradaDic entradas[100]; //cada entrada do vetor (indice) é do tipo acima (ou seja, contem 2 campos: chave, info). Mas como o void* info 
    int tamanho;                // eh um ponteiro para void, podemos colocar qualquer coisa dentro de info
    int ocupacao;
};


// definindo as operacoes sobre o conjunto acima

TDEstatico* criar_DE(){ // significa criar uma instancia do TDEstatico
    TDEstatico *de = malloc(sizeof(TDEstatico));
    de->tamanho = 100;
    de->ocupacao = 0;
};

void* buscar_DE(TDEstatico* de , int chave){
    void* entrada = NULL;
    int inicio = 0;
    int fim = de->ocupacao-1;
    
    short encontrou = 0;

    do{//busca binaria no dicionario
        int meio = (inicio+fim)/2; // toda vez que mexer no inicio ou fim precica-se redefinir o meio
        if (de->entradas[meio].chave == chave){
            encontrou=1; // verdade, encontrou-se o objeto
            entrada = de->entradas[meio].info;
        } else if(de->entradas[meio].chave > chave){
            fim = meio-1;
        }else{
            inicio = meio+1;
        }
    }while ((!encontrou) && (inicio<fim)); 

    return entrada;
};

int ocupacao_DE(TDEstatico* de){
    return de->ocupacao;
};

void carga_DE(TDEstatico*);