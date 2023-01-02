typedef struct destatico TDEstatico;
typedef struct entrada TEntradaDic;

struct entrada{
  int chave;
  void* info;
};

TEntradaDic criar_entrada(int chave, void* info);


TDEstatico* criar_DE(int tamanho);

void* buscar_DE(TDEstatico* de, int chave);
int ocupacao_DE(TDEstatico* de);

void carga_DE(TDEstatico* de, TEntradaDic entrada);
void dashboard_DE(TDEstatico *de);
