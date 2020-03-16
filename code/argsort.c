/*
 * program sorts command line arguments in ascending order
 *   - if only 1 argument provided, the characters are sorted
 *   - sorting is accomplished using qsort and
 *   - and two comparators
 *
 *   Usage: ./a.out zyxghiabcd -> abcdghixyz
 *          ./a.out zero black argon -> argon black zero
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_strings(const void *a, const void *b) {
  const char *pa = *(const char **)a;
  const char *pb = *(const char **)b;
  printf("%s %s\n", pa, pb);
  return strcmp(pa, pb);

  // Cast 'a' to a pointer to a constant pointer
  // to a character and dereference that
  // Credits:
  // https://bewuethr.github.io/2015-03-07-sorting-strings-in-c-with-qsort.html
  // return strcmp(*(char* const*) a, *(char* const*) b);
}

int compare_chars(const void *a, const void *b) {
  printf("%c %c\n", *(char *)a, *(char *)b);
  return (*(char *)a - *(char *)b);
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    puts("No args to sort!\n");
    exit(0);
  }
  if (argc == 2) {
    qsort(argv[1], strlen(argv[1]), sizeof(char), compare_chars);
    puts("After sorting letters in argument 1...");
    printf("%s\n", argv[1]);
  }
  if (argc > 2) {
    qsort(&argv[1], argc - 1, sizeof(char *), compare_strings);
    puts("After sorting command line arguments..");
    for (int i = 1; i < argc; i++)
      printf("%s\n", argv[i]);
  }

  return 0;
}
