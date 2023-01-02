#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "destatico.h"


//funcao especialista

typedef struct pessoa{
    int idade;
    char nome[100];
    char apelido[20];
}TPessoa;

TPessoa* criar_pessoa(int idade, char nome[], char apelido[]){
    TPessoa* p = malloc(sizeof(TPessoa));
    p->idade = idade;
    strcpy(p->nome, nome);
    strcpy(p->apelido, apelido);
}

int main (int argc, char const *argv[]){
    TDEstatico* pessoas = criar_DE();

    int idade = 50;
    char nome[100] = "maria";
    char apelido[20] = "mah";
    int cpf = 404177;

    // int idade2 = 50;
    // char nome2[100] = "joao";
    // char apelido2[20] = "jo";
    // int cpf2 = 301233;

    TPessoa* fulano= criar_pessoa(idade, nome, apelido);
    TEntradaDic entrada = criar_entrada(cpf, fulano); // cpf esta associada a informacao (pessoa)

    // TPessoa* fulano= criar_pessoa(idade2, nome2, apelido2);
    // TEntradaDic entrada = criar_entrada(cpf2, fulano); // cpf esta associada a informacao (pessoa)

    carga_DE(pessoas, entrada); // carga tá esperando um dicionario e uma entrada

    fulano = buscar_DE(pessoas, 404177);
    //imprimir_pessoa(fulano);

    return 0;
}