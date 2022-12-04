typedef struct agendaInfo TipoAgendaInfo; //tipo agenda
typedef struct elementoLSE TipoAgendaLSE;

TipoAgendaLSE* criar_agenda();
TipoAgendaLSE* agendar_evento(char *titulo, char *data, int tempolimite, char *local, char *descricao, int Prioridade);
TipoAgendaInfo* proximo_evento();
TipoAgendaInfo* remover_evento();