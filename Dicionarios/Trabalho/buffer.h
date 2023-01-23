typedef struct {
  int primeiraPosicaoLivre;
  int capacidade;
  char *data;
}Buffer;

// Retorna um ponteiro para um novo buffer
Buffer *create_buffer();

// Destrói um buffer, liberando qualquer memória que ele ocupe
void destroy_buffer(Buffer *B);

// Adiciona um caractere ao final do buffer. Retorna diferente de zero em caso de sucesso, zero em caso de falha
int buffer_add_char(Buffer *B, char c);

// Anexa o conteúdo de uma string, exceto para o nulo de terminação
// caractere, para um buffer. Retorna diferente de zero em caso de sucesso, zero em caso de falha.
int buffer_add_str(Buffer *B, char *s);

// Limpa o buffer. Novas chamadas para buffer_add_char e buffer_add_str substituirá o conteúdo antigo.
void clear_buffer(Buffer *B);
