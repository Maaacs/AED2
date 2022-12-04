typedef struct agendaInfo TipoAgendaInfo; //tipo agenda
typedef struct elementoLSE TipoAgendaLSE;

TipoAgendaLSE* criar_agenda();
TipoAgendaLSE* agendar_evento(char *titulo, char *data, int tempolimite, char *local, char *descricao, int Prioridade);
// TipoAgendaLSE* agendar_evento(TipoAgendaInfo* carga, int Prioridade);
//void imprimir_agenda(TAgenda* l);