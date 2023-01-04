typedef int (*TCompararFP)(void*, void*); // ponteiro de funcao
typedef struct filaPrioridade TFilaPrioridade;


TFilaPrioridade* criar_FP(int tamanho, TCompararFP comparar);
int enfileirar_FP (TFilaPrioridade *f, void* elem);
void* desenfileirar_FP (TFilaPrioridade* f);
void destroy_FP(TFilaPrioridade* f);
void* primeiro_FP(TFilaPrioridade* f);
//int tamanho_filaFP (TFilaPrioridade* f);

