#include "stdio.h"
#include "stdlib.h"
#include "string.h" //chamando a bib
#include "agenda.h"


// struct agenda{
//     char data[8];
//     char hora[5];
//     int tempoLimite; //tempo limite para a realização do evento desde o agendamento em segundos
//     int prioridade; //de 1 a 4
// };
struct agendaInfo{
    char titulo[60];
    char data[8]; // dia/mes/ano
    int tempoLimite; //tempo limite para a realização do evento desde o agendamento em segundos
    char local[20];
    char descricao[30];
};

struct elementoLSE{
    TipoAgendaInfo* cargaUtil; //agendaInfo
    int prioridade;
    int deadline;
};


TipoAgendaLSE* criar_agenda(){

    TipoAgendaLSE *l = malloc(sizeof(TipoAgendaLSE)); // aloca na memória o elementoLSE que contem os campos: cargaUtil e deadline
    l->prioridade = 1;
    l->deadline = 0;
    return l;
}

TipoAgendaLSE* agendar_evento(char *titulo, char *data, int tempolimite, char *local, char *descricao, int Prioridade){
//TipoAgendaLSE* agendar_evento(TipoAgendaInfo* carga, int Prioridade){ //insere um novo evento na agenda considerando os atributos que irão posicionar o evento na agenda

    TipoAgendaLSE *l;    
    strcpy(l->cargaUtil->titulo, titulo); //tem que passar cada char do vetor de char, por isso fazer uma copia com strcpy
    strcpy(l->cargaUtil->data, data);
    l->cargaUtil->tempoLimite = tempolimite;
    strcpy(l->cargaUtil->local, local);
    strcpy(l->cargaUtil->descricao, descricao);
    //l->cargaUtil = carga;
    l->prioridade = Prioridade; //podemos tratar a prioridade como um elemento da LSE ou uma informaçao interna da AgendaInfo

    if (l->cargaUtil->tempoLimite < l->deadline){
        l->deadline = l->cargaUtil->tempoLimite; // grava o menor tempo sempre
    }

    return l;

}
//proximo_evento(); // retorna o evento que está na eminência de ocorrer

//remover_evento(); // remove e retorna o evento que está na eminência de ocorrer.



