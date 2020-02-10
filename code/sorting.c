#include <stdio.h>

#include <time.h>
#include <stdlib.h>

int rnd(int n) {
    int r = rand() % n;      // Returns a pseudo-random integer between 0 and RAND_MAX.
    int sign = rand() % 2;   // negative if 1 and positive if 0 
    if (sign) r = -r; 
    // printf("%d\n", r); 
    return r;
}

int comparefunc(const void* a,const void* b){
    const int *ia = (const int *)a; // casting pointer types 
    const int *ib = (const int *)b;
    return *ia  - *ib; 
	/* integer comparison: returns negative if b > a 
	and positive if a > b */ 
}

void qsort (void* base, size_t num, size_t size,  
            int (*comparator)(const void*,const void*));


int main () { 
    
    srand(time(NULL));   // Initialization, should only be called once.
    
    for (int i = 1; i < 10000; i *= 10) {
        int maxsize = 1000 *i;
        int array[maxsize];// = (int *)malloc(10 * sizeof(int)); 
        for (int i = 0; i < maxsize; i++) {
            array[i] = rnd(100);
            //printf("%d %d\n", i, array[i]); 
        }
        puts("---");

        clock_t start, end;
        double cpu_time_used;
        
        start = clock();
        qsort((void *)array, maxsize, sizeof(array[0]), comparefunc); 
        end = clock();
        cpu_time_used = ((double) (end - start));

        printf("%d : %.2f\n", maxsize, cpu_time_used);

        /*for (int i = 0; i < maxsize; i++)
            printf("%d, ", array[i]); 
        */
    }

    return 0;

}