#include "stdio.h"
#include "filaFP.h"
#include "string.h"
#include "stdlib.h"
#include "agenda.h" // incluindo bib
#include "assert.h"

typedef struct evento{
int prio;
char descricao [100];
}TEvento;

int compararEvento (void* e1, void* e2) {
    TEvento *ee1 = e1;
    TEvento *ee2 = e2;
    return (ee1->prio - ee2->prio);
}

void test_criar_agenda(){
    assert(criar_agenda(compararEvento)!=NULL);
    printf("Teste criar_agenda OK\n");
}

TEvento* criar_evento(int prio, char mens []){
    TEvento *e = malloc (sizeof (TEvento));
    e->prio = prio;
    strcpy (e->descricao, mens);
    printf("Teste criar_evento OK\n");
    return e;
}

void test_agendar_evento(){
    TipoAgenda *agenda = criar_agenda(compararEvento);   
    //TipoAgenda *agenda = criar_agenda(10, compararEvento); 
    //TipoAgenda *agenda = criar_agenda(NULL, compararEvento);   
    agendar_evento(agenda, criar_evento(1, "evento de prioridade"));
    TEvento *e = proximo_evento(agenda);    
    printf("Teste criar_evento OK\n");
    assert(e!=NULL);
}


// void test_prioridade_evento(){

//     TipoAgenda *agenda = criar_agenda(10, compararEvento);

//     agendar_evento(agenda, criar_evento(1, "evento de prioridade"));

//     agendar_evento(agenda, criar_evento(2, "evento de prioridade"));

//     TEvento* e = proximo_evento(agenda);

//     assert(e !=NULL);
//     assert(e->prio == 2);
//     remover_evento(agenda);

//     e = proximo_evento(agenda);
//     assert(e !=NULL);
//     assert(e->prio == 2);

//     printf("Teste prioridade_evento");
// }

int main(int argc, char const *arqv[]){
    test_criar_agenda();
    test_agendar_evento();
    //test_prioridade_evento();
    //test_remover_evento();
    //test_agenda_vazia();
}

