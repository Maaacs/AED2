typedef struct agenda TAgenda; //tipo agenda
TAgenda* criar_agenda(char *titulo, char *diaMesAno, char *hora, char *local, char *descricao);
void imprimir_agenda(TAgenda* l);