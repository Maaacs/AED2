typedef struct pilha TPilha; // para tornar o TPilha publico para ser acessado


TPilha* criar_pilha();
int empilhar(TPilha* p, void* item);
void* desempilhar(TPilha* p);
void* topo_pilha(TPilha* p);
int altura_pilha(TPilha* p);