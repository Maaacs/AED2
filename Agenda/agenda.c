#include "stdio.h"
#include "stdlib.h"
#include "string.h" 
#include "agenda.h"
#include "filaFP.h" //chamando a lib filaFP

struct agenda{
    TFilaPrioridade *eventos;
};

// instancia agenda
TipoAgenda* criar_agenda(TCompararAgenda comparar){
    TipoAgenda*l = malloc(sizeof(TipoAgenda));
    l->eventos = criar_FP(0, comparar);
    return l;
}

void agendar_evento(TipoAgenda* agenda, void* evento){//insere um novo evento na agenda
    enfileirar_FP(agenda->eventos, evento);
}

void* proximo_evento(TipoAgenda* agenda){ // retorna o evento que está na eminência de ocorrer
    return primeiro_FP(agenda->eventos);
}


void* remover_evento(TipoAgenda* agenda){ // remove o evento que está na iminência de ocorrer
    desenfileirar_FP(agenda->eventos);
}



