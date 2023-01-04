#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "ddinamico.h"

int main(int argc, char const *argv[]) {

  TDDinamico* meuDD = criar_DD(25, NULL);

  assert(meuDD!=NULL);

  return 0;
}