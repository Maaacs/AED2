typedef int (*TCompararFP)(void*, void*);
typedef struct filaPrioridade TFilaPrioridade;


TFilaPrioridade* criar_FP(int tamanho, TCompararFP comparar);
void enfileirar_FP (TFilaPrioridade *f, void* elem);
//void* desenfileirar_FP (TFilaPrioridade* f);
//destroy_FP();

