#include <stdio.h>
#include <time.h> 
#include <string.h>
#include <assert.h> 
#include <stdarg.h>
#include <math.h> 

int compare_chars(const void *a, const void *b)
{
    //printf("%c %c\n", *(char *)a, *(char *)b);
    //return strncmp((char*)a, (char*)b, 1);
    return (*(char *)a - *(char *)b);
}

void selection_sort(char *astring) {
  if (!*astring) return;
  char *minc = astring; 
  for (const char *p = astring+1; *p; p++) {
    if (*p < *minc)
      minc = p;
  }
  if (minc != astring) {
    char temp = *astring; 
    *astring = *minc;
    *minc = temp;
  }
  selection_sort(astring+1);
}

void qsort( void *ptr, size_t count, size_t size,
            int (*comp)(const void *, const void *) );

/*
int main() { 
  
  void (*sortfunction[2])(const char* fmt, ...) = {
        selection_sort, 
        qsort
    };  

  char buf[100] = "alsdkfjaslkdjf";
  sortfunction[0](buf);
  printf("selection_sort: %s\n", buf);
  strcpy(buf, "asodfiaslkdjflkjqweroiuqwer");
  sortfunction[1](buf, strlen(buf), sizeof(char), compare_chars);
  printf("qsort: %s\n", buf);
}
*/

int main(int argc, char *argv[]) {
  
  char buf[1000], teststring[1000];
  int execs = 1000000;
  if (argc == 1) 
    strcpy(buf, "samplesamplestringforsorting"); 
  else
    strcpy(buf, argv[1]), strncat(buf, buf, 20);
  strcpy(teststring, buf);
  printf("Len of test string %ld\n", strlen(teststring));

  clock_t begin = clock();
  // here, do your time-consuming job 
  int count = execs;
  while(count--> 0) {
    strcpy(buf, teststring);
    qsort(buf, strlen(buf), sizeof(char), compare_chars);
  }
  clock_t end = clock();
  double time_gold = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time spent by qsort %.4f seconds\n", time_gold);
  char gold[1000]; 
  strcpy(gold, buf);

  // Get timing information for custom sort function
  count = execs;
  begin = clock();
  while(count--> 0) {
    strcpy(buf, teststring);
    selection_sort(buf);
  }
  end = clock();
  // sanity check whether your sort is valid 
  printf("Sorted string %s\n", buf);
  assert (strcmp(gold, buf)==0);
  
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time spent by selectionsort %.4f seconds\n", time_spent);

  // Step 3 - analysis of the comparison
  double diff = fabs(time_spent - time_gold);
  printf("selectionsort is %.2f%c %s!\n", 
    (diff/time_spent)*100, 
    '%',
    time_spent < time_gold? "faster" : "slower" );

  double timediff = difftime(end, begin) /CLOCKS_PER_SEC;
;
  printf("%f\n", timediff);
  return 0;
}
