/*
 * program sorts command line arguments in ascending order
 *   - if only 1 argument provided, the characters are sorted
 *   - sorting is accomplished using qsort and
 *   - and two comparators
 *
 *   Usage: ./a.out abcdzyxghi -> abcdghixyz
 *          ./a.out argon zero black -> argon black zero
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

int main(int argc, char *argv[]) {
  if (argc == 1) {
    puts("No args to sort!");
		return -1;
  }
	void *list = argv[1];
	int element_count = strlen(argv[1]);
	int size_of_element = sizeof(char); 
	int (*sortfunc)() = 
		(int (*)(const void *, const void *))strcmp;

	if (argc > 2) {
		list = &argv[1];
		element_count = argc - 1;
		size_of_element = sizeof(char *);
		sortfunc = compare_strings;
	}

	qsort(list, element_count, size_of_element, sortfunc);

	if (argc == 2){
    puts("After sorting letters in argument 1...");
    printf("%s\n", argv[1]);
  } else {
	  puts("After sorting command line arguments..");
    while (argc > 1)
      printf("%s\n", argv[--argc]);
	}
  return 0;
}
