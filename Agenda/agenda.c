#include "stdio.h"
#include "stdlib.h"
#include "string.h" //chamando a bib
#include "agenda.h"
#include "filaFP.h"

struct agenda{
    TFilaPrioridade *eventos;
};

typedef int(*TCompararAgenda)(void*, void*);
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

void* proximo_evento(TipoAgenda* agenda){ // retorna o evento que está na eminência de ocorrer
    return primeiro_FP(agenda->eventos);
}

// Estou levando em consideraçao apenas o tempo. Devo levar em consideraçao a prioridade será? Talvez n pq isso é uma agenda. 
// Prioridade serviria somente lá para a fila de prioridade na hora que ela for organizar os elementos no vetor.
void* remover_evento(TipoAgenda* agenda){ // remove e retorna o evento que está na eminência de ocorrer. (mantendo sempre o menor tempo (o segundo menor tempo))
    desenfileirar_FP(agenda->eventos);
}



