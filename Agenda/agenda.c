#include "stdio.h"
#include "stdlib.h"
#include "string.h" //chamando a bib
#include "agenda.h"

struct agendaInfo{
    char titulo[60];
    char data[8]; // dia/mes/ano
    int tempoLimite; //tempo limite para a realização do evento desde o agendamento em segundos
    char local[20];
    char descricao[30];
};

struct elementoLSE{
    TipoAgendaInfo* cargaUtil; //agendaInfo
    TipoAgendaInfo *cargaMenorTempo;
    TipoAgendaInfo *cargaMenorTempoAuxiliar;
    int prioridade;
    int deadline;
};


TipoAgendaLSE* criar_agenda(){
    TipoAgendaLSE *l = malloc(sizeof(TipoAgendaLSE)); // aloca na memória o elementoLSE com seus campos acima
    l->cargaMenorTempo = l->cargaUtil;
    l->prioridade = 1; // valor baixo (prioridade vai de 1 a 4)
    l->deadline = 2419200; // Um tempo alto de 4semanas==672h==40320min==249200s
    return l;
}

TipoAgendaLSE* agendar_evento(char *titulo, char *data, int tempolimite, char *local, char *descricao, int Prioridade){//insere um novo evento na agenda considerando os atributos que irão posicionar o evento na agenda
//TipoAgendaLSE* agendar_evento(TipoAgendaInfo* carga, int Prioridade){ 
    TipoAgendaLSE *l;    
    strcpy(l->cargaUtil->titulo, titulo); //tem que passar cada char do vetor de char, por isso fazer uma copia com strcpy
    strcpy(l->cargaUtil->data, data);
    l->cargaUtil->tempoLimite = tempolimite;
    strcpy(l->cargaUtil->local, local);
    strcpy(l->cargaUtil->descricao, descricao);
    l->prioridade = Prioridade; //podemos tratar a prioridade como um elemento da LSE ou uma informaçao interna da AgendaInfo

    if (l->cargaUtil->tempoLimite < l->deadline){
        l->deadline = l->cargaUtil->tempoLimite; // grava o menor tempo sempre
        l->cargaMenorTempoAuxiliar = l->cargaMenorTempo; // endereco do evento com o segundo menor tempo
        l->cargaMenorTempo = l->cargaUtil; //endereco do evento com o menor tempo
    }

    return l;

}

TipoAgendaInfo* proximo_evento(){ // retorna o evento que está na eminência de ocorrer
    TipoAgendaLSE *l; 
    return l->cargaMenorTempo; //já tempos um campo que contém essa informação
}

// EStou levando em consideraçao apenas o tempo. Devo levar em consideraçao a prioridade será? Talvez n pq isso é uma agenda. 
// Prioridade serviria somente lá para a fila de prioridade na hora de organizar os elementos no vetor
TipoAgendaInfo* remover_evento(){ // remove e retorna o evento que está na eminência de ocorrer. (mantendo sempre o menor tempo (o segundo menor tempo))
    TipoAgendaLSE *l;
    TipoAgendaInfo *aux;

    aux = l->cargaMenorTempo; // aux recebe o endereco do evento com o menor tempo
    l->cargaMenorTempo = l->cargaMenorTempoAuxiliar; // menor tempo recebe o endereco do segundo menor tempo
    free(aux); // remove o evento com o menor tempo

    return aux;
}



