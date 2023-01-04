typedef int(*TCompararDD)(void*, void*);
typedef struct ddinamico TDDinamico;

TDDinamico* criar_DD(int tamanho, TCompararDD comparar);
void inserir_DD(TDDinamico *dd, int chave, void* info);
void* buscar_DD(TDDinamico *dd, int chave);
void* remover_DD(TDDinamico *dd, int chave);
