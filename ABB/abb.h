typedef struct ABB TABB;
typedef int(*TCompararABB)(void*, void*);
typedef void(*TImprimirABB)(void*);


TABB* criarABB(TCompararABB comparar, TImprimirABB IMPRESSORA);
// TABB* criarABB(TImprimirABB impressora, TCompararABB);
void inserirABB(TABB *abb, void *info);


