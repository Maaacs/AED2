#include "stdio.h"
#include "filaFP.h"
#include "string.h"
#include "stdlib.h"
#include "agenda.h" // incluindo bib



int main(int argc, char const *arqv[]){

    TCompararFP comparar;
    TFilaPrioridade* para_ver = criar_FP(2,comparar); // cria fila - tamanho da fila e funcao de comparacao 
    TipoAgendaLSE* novaAgenda = criar_agenda();// cria agenda

    int prioridade;
    char titulo[60];
    char data[8]; // dia/mes/ano
    int tempoLimite; //tempo limite para a realização do evento desde o agendamento em segundos
    char local[20];
    char descricao[30];
    //int prioridade;

    scanf("%s", titulo);
    while (strcmp(titulo, "FIM") != 0){
       
       scanf("%d %s %d %s %s\n", &prioridade, data, &tempoLimite, local, descricao);  

        TipoAgendaLSE* novo_evento = agendar_evento(prioridade, titulo, data, tempoLimite, local, descricao); //infos e prioridade
        
        enfileirar_FP(para_ver, novo_evento);
        
        scanf("%s", titulo);
        
    }
    //tamanho_filaFP(para_ver);
    //imprimir_eventoAgenda();
    //printf("tamanho: %d\n", tamanho_filaFP(para_ver));

    //TFilaPrioridade* primeiro = desenfileirar(para_ver);
    //imprimir_livro(primeiro);
    //free(primeiro); //precisa liberar pq o primeiro é uma referencia ao elemento do vetor desempilhado. Portanto, embora no vetor, o elemento nao esteja mais
                    // sendo referenciado, a variavel primeiro ainda contem esse elemento, portanto apos imprimir pode desempilhar

    //printf("tamanho: %d\n", tamanho_fila(para_ler));

    return 0;
}
