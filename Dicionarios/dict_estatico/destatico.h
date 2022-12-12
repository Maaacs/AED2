
typedef struct entrada TEntradaDic;
typedef struct destatico TDEstatico;

TDEstatico* criar_DE(); // significa criar uma instancia do TDEstatico
void* buscar_DE(TDEstatico*, int chave);
int ocupacao_DE(TDEstatico*);

void carga_DE(TDEstatico*);