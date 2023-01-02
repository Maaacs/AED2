#include "stdio.h"
#include "stdlib.h"
#include "string.h" //chamando a bib
#include "agenda.h"
#include "filaFP.h"

struct agenda{
    TFilaPrioridade *eventos;
};

typedef struct agenda TipoAgenda;

// instancia agenda
TipoAgenda* criar_agenda(TCompararAgenda comparar){
    TipoAgenda*l = malloc(sizeof(TipoAgenda)); // aloca na memória o elementoLSE com seus campos acima
    l->eventos = criar_FP(0, comparar);
    return l;
}

void agendar_evento(TipoAgenda* agenda, void* evento){//insere um novo evento na agenda considerando os atributos que irão posicionar o evento na agenda
    enfileirar_FP(agenda->eventos, evento);

}

TipoAgendaInfo* proximo_evento(){ // retorna o evento que está na eminência de ocorrer
    TipoAgendaLSE *l; 
    return l->cargaMenorTempo; //já temos um campo que contém essa informação então só retornar o endereco desse evento
}

// Estou levando em consideraçao apenas o tempo. Devo levar em consideraçao a prioridade será? Talvez n pq isso é uma agenda. 
// Prioridade serviria somente lá para a fila de prioridade na hora que ela for organizar os elementos no vetor.
TipoAgendaInfo* remover_evento(){ // remove e retorna o evento que está na eminência de ocorrer. (mantendo sempre o menor tempo (o segundo menor tempo))
    TipoAgendaLSE *l;
    TipoAgendaInfo *aux;
    aux = l->cargaMenorTempo; // aux recebe o endereco do evento com o menor tempo
    l->cargaMenorTempo = l->cargaMenorTempoAuxiliar; // menor tempo recebe o endereco do segundo menor tempo
    free(aux); // remove o evento com o menor tempo
    return aux;
}


// void imprimir_eventoAgenda(TipoAgendaInfo* l){
//     printf("%d %s %s %d %s %s\n", l->prioridade, l->titulo, l->data, l->tempoLimite, l->local, l->descricao);
// }



