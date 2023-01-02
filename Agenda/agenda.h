typedef int(*TCompararAgenda)(void*, void*);
typedef struct agenda TipoAgenda;

TipoAgenda* criar_agenda(TCompararAgenda comparar);
void agendar_evento(TipoAgenda* agenda, void* evento);
void* proximo_evento(TipoAgenda* agenda);
void* remover_evento(TipoAgenda* agenda);