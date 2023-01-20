typedef struct ABB TABB;
typedef int(*TCompararABB)(void*, void*);
typedef void(*TImprimirABB)(void*);

TABB* criarABB(TCompararABB comparar);
// TABB* criarABB(TImprimirABB impressora, TCompararABB);

