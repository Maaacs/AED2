typedef struct entrada TEntradaDic;
typedef struct destatico TDEstatico;

TDEstatico* criar_DE(); // significa criar uma instancia do TDEstatico
void* buscar_DE(TDEstatico*, int chave); // assinatura 
int ocupacao_DE(TDEstatico*); // assinatura
void carga_DE(TDEstatico* de, TEntradaDic entrada); // assinatura da carga

TEntradaDic criar_entrada(int chave, void* info);