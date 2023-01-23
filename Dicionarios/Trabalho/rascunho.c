#include <stdio.h>
#include <string.h>


const char *dictionary[] = {"word1", "word2", "word3", "word4"};
const char *stop_words[] = {"a", "an", "the", "and", "or", "but", "for", "nor", "on", "at", "to", "from", "by"};

int num_dictionary_words = sizeof(dictionary) / sizeof(dictionary[0]);
int num_stop_words = sizeof(stop_words) / sizeof(stop_words[0]);

int is_stop_word(const char *word) {
    for (int i = 0; i < num_stop_words; i++) {
        if (strcmp(word, stop_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_in_dictionary(const char *word) {
    for (int i = 0; i < num_dictionary_words; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char word[256];
    printf("Enter a word: ");
    scanf("%s", word);
    if(is_stop_word(word)) {
      printf("'%s' is a stop word.\n", word);
    } else {
      if (is_in_dictionary(word)) {
          printf("'%s' is in the dictionary.\n", word);
      } else {
          printf("'%s' is not in the dictionary.\n", word);
      }
    }
    return 0;
}
// Esse programa tem uma lista estática de "dictionary words" (palavras presentes na base de dados) 
// e uma lista estática de "stop words" (palavras comuns que não devem ser incluídas na busca),
// e duas funções is_stop_word e is_in_dictionary que verifica se uma determinada palavra está nas respectivas listas.
// No main é pedido uma palavra e chamado a função is_stop_word, se for uma stop word é impresso "word is a stop word"
//  senão é chamado a função is_in_dictionary e é impresso "word is in the dictionary" ou "word is not in the dictionary"



