typedef struct agendaInfo TipoAgendaInfo; //tipo agenda
typedef struct elementoLSE TipoAgendaLSE;

TipoAgendaLSE* criar_agenda();
TipoAgendaLSE* agendar_evento(int Prioridade, char *titulo, char *data, int tempolimite, char *local, char *descricao);
TipoAgendaInfo* proximo_evento();
TipoAgendaInfo* remover_evento();
//void imprimir_eventoAgenda(TipoAgendaInfo* l);