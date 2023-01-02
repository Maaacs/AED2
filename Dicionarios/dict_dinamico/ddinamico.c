#include "stdio.h"
#include "stdlib.h"
#include "lista.h"

struct ddinamico{
    // dados
    int tamanho;
    int nro_elementos; //numero de elementos (ocupacao)

    TListaSE* *entradas; // vetor dinamico de ponteiros para listas encadeadas
    // estatística
};