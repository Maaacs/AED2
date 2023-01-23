typedef struct ABB TABB;
typedef int(*TCompararABB)(void*, void*);
typedef void(*TImprimirABB)(void*);
typedef void(*TDestroyABB)(void*);


TABB* criarABB(TCompararABB comparar, TImprimirABB IMPRESSORA, TDestroyABB destroy);
// TABB* criarABB(TImprimirABB impressora, TCompararABB);
void inserirABB(TABB *abb, void *info);
void imprimirABB(TABB *abb);
// static int _tamanhoNo (TNo *raiz);
// int tamanhoABB (TABB *abb);
// void* _podarNo (TNo* raiz, TDestroyABB destroy);
void podarABB (TABB *abb, void *chave);


