#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

/* for the C Version Practice of 
  https://www.codewars.com/kata/55c45be3b2079eccff00010f/train/python

*/

/* Tests
./a.out "is2 Thi1s T4est 3a"
./a.out "d4o dru7nken sh2all w5ith s8ailor wha1t 3we a6"
./a.out "4of Fo1r pe6ople g3ood th5e the2"
*/

int comp_chars(const void* a, const void* b) { 
  // printf("%c %c\n", *(char *)a, *(char *)b);
  return (*(char *)a - *(char *)b);
  }

/*char *words[9] = {0}; 
int count = 0; 

void print_pointers() {
  for (int i = 0; i < count; i++)
    printf("%p %s\n", words[i], words[i]);
}
*/

int compTokens(const void* a, const void* b) {
  const char *pa = *(const char **)a;
  const char *pb = *(const char **)b;
  //printf("%s %s\n", pa, pb);
  char *pac = malloc(strlen(pa)+1);
  strcpy(pac, pa);
  qsort(pac, strlen(pa), sizeof (char), comp_chars);
  char *pbc = malloc(strlen(pb)+1);
  strcpy(pbc, pb);
  qsort(pbc, strlen(pb), sizeof (char), comp_chars);
  //printf("%s %s\n", pac, pbc);
  //return strcmp(*(char* const*) pac, *(char* const*) pbc);
  //printf("%s %s\n", pac, pbc);
  //printf("%c %c\n", pac[0], pbc[0]);
  return (pac[0] - pbc[0]);
  //return strcmp(pa, pb);
  //printf("%s %s\n", pac, pbc);
  //return strcmp(pac, pbc);  
}


int compare_strings(const void *a, const void *b)
{
    //print_pointers();
    const char *pa = *(const char **)a;
    const char *pb = *(const char **)b;
    //printf("%p %p %p %p\n", &pa, &pb, pa, pb);
    printf("%s %s\n", pa, pb);
    //return strcmp(pa, pb);
    return *pb - *pa;
    // return -1;

    // Cast 'a' to a pointer to a constant pointer
    // to a character and dereference that
    // Credits:
    // https://bewuethr.github.io/2015-03-07-sorting-strings-in-c-with-qsort.html
    // return strcmp(*(char* const*) a, *(char* const*) b);
}


char *order_words (char *ordered, const char *sentence)
{
// ordered is pre-allocated and has enough room for a trailing space character ' '
// but dont forget to trim it !
// write to ordered and return it
	//*ordered = '\0';
  int sentence_length = strlen(sentence);
  //char *cpy = malloc(sentence_length + 2);
  char *cpy = calloc(sentence_length + 1, 1);
  //strcpy(cpy, sentence); 
  char *words[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  words[0] = cpy;
  int count = 0;
  
  char *token = strtok(strcpy(cpy, sentence), " "); 
  do {
    words[count] = token; 
    puts(words[count]);
    count++;
  } while ( (token = strtok(NULL, " ")));
  
  qsort(&words, count, sizeof(char *), compTokens);
  
  *ordered = 0;
  for (int i = 0; i < 10; i++) 
    if (words[i]) 
        strcat(ordered, words[i]), strcat(ordered, --count ? " " : "");

	return free(cpy), ordered;
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
    int size_of_element = sizeof(char *);
    //int (*sortfunc)() = (int (*)(const void *, const void *))strcmp;

    char *ordered = malloc(strlen(argv[1])+1); 
    order_words(ordered, argv[1]);
    printf("ordered %s\n", ordered);

    return 0;
}

