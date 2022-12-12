#include "destatico.h"

// typedef struct entrada{
//     int chave;
//     void* info;
// }TEntradaDic;
// typedef struct destatico{
//     TEntradaDic entradas[100];
//     int tamanho;
//     int ocupacao;
// }TDEstatico;

struct entrada{
    int chave;
    void* info;
};

struct destatico{
    TEntradaDic entradas[100];
    int tamanho;
    int ocupacao;
};


// definindo as operacoes sobre o conjunto acima

TDEstatico* criar_DE(); // significa criar uma instancia do TDEstatico
void* buscar_DE(TDEstatico*, int chave);
int ocupacao_DE(TDEstatico*);

void carga_DE(TDEstatico*);