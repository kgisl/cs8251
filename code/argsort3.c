#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int compChars(const void* a, const void* b) { 
  // printf("%c %c\n", *(char *)a, *(char *)b);
  return (*(char *)a - *(char *)b);
}

int compTokens2(const void* a, const void* b) {
  const char *pa = *(const char **)a;
  const char *pb = *(const char **)b;
  //printf("%s %s\n", pa, pb);
  char *pac = malloc(strlen(pa)+1);
  strcpy(pac, pa);
  qsort(pac, strlen(pa), sizeof (char), compChars);
  char *pbc = malloc(strlen(pb)+1);
  strcpy(pbc, pb);
  qsort(pbc, strlen(pb), sizeof (char), compChars);
  //printf("%s %s\n", pac, pbc);
  //return strcmp(*(char* const*) pac, *(char* const*) pbc);
  printf("%s %s\n", pac, pbc);
  printf("%c %c\n", pac[0], pbc[0]);
  return (pac[0] - pbc[0]);
  //return strcmp(pa, pb);
  //printf("%s %s\n", pac, pbc);
  //return strcmp(pac, pbc);  
}

int compTokens(const void* a, const void* b) {
  const char *pa = *(const char **)a;
  const char *pb = *(const char **)b;
  printf("%s %s\n", pa, pb);
  return strcmp(*(char* const*) a, *(char* const*) b);
  //return strcmp(pa, pb);
  //return pa[0] - pb[0];
}

void qsort( void *ptr, size_t count, size_t size,
            int (*comp)(const void *, const void *) );

char *order_words (char *ordered, const char *words)
{
// ordered is pre-allocated and has enough room for a trailing space character ' '
// but dont forget to trim it !
// write to ordered and return it
	*ordered = '\0';
  strcpy(ordered, words);
  char *tokens[1000];
  tokens[0] = ordered;
  char *token = strtok(ordered, " ");
  int i = 1; 
  while (token) {
    puts(token);
    tokens[i] = token;
    qsort(tokens[i-1], strlen(tokens[i-1]), sizeof(char), compChars);
    i++;
    token = strtok(NULL, " ");
  }
  qsort(&tokens, i-1, sizeof(char *), compTokens);
  
  for(size_t n = 0; n < strlen(words); ++n)
        if(!ordered[n])
          ordered[n] = ' ';
  puts(ordered);
  return ordered;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        puts("No args to sort!");
        return -1;
    }
    void *list = argv[1];
    int element_count = strlen(argv[1]);
    int size_of_element = sizeof(char);
    int (*sortfunc)() = (int (*)(const void *, const void *))strcmp;

    if (argc > 2)
    {
        list = &argv[1];
        element_count = argc - 1;
        size_of_element = sizeof(char *);
        sortfunc = compare_strings;
    }

    char *ordered = malloc(strlen(argv[1])+1); 
    order_words(ordered, argv[1]);
    printf("ordered %s\n", ordered);

    return 0;
}
