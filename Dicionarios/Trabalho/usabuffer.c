#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"

int main()
{
  FILE *infile = fopen("texto_aed2.txt", "r");

  if (!infile) {
    printf("Could not open file\n");
    exit(-1);
  }

  Buffer *B = create_buffer();

  int c;
  while ((c = fgetc(infile)) != EOF)
    buffer_add_char(B, c);

  // We shouldn't forget the terminating null.
  buffer_add_char(B, '\0');

  puts(B->data);

  destroy_buffer(B);
  fclose(infile);

  return 0;
}