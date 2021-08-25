#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rnd(int n)
{
    int r = rand() % n;    // Returns a pseudo-random integer between 0 and RAND_MAX.
    int sign = rand() % 2; // negative if 1 and positive if 0
    if (sign)
        r = -r;
    // printf("%d\n", r);
    return r;
}

int comparefunc(const void *a, const void *b)
{
    const int *ia = (const int *)a; // casting pointer types
    const int *ib = (const int *)b;
    return *ia - *ib;
    /* integer comparison: returns negative if b > a
    and positive if a > b */
}

void qsort(void *base, size_t num, size_t size, int (*comparator)(const void *, const void *));

int main()
{

    srand(time(NULL)); // Initialization, should only be called once.
    int maxsize = 100;
    for (int i = 1; i < 10000; i *= 5)
    {
        int maxsize = 100 * i;
        int array[maxsize];
        for (int i = 0; i < maxsize; i++)
        {
            array[i] = rnd(100);
            // printf("%d %d\n", i, array[i]);
        }
        puts("---");

        clock_t start, end;
        double cpu_time_used;

        start = clock();
        qsort((void *)array, maxsize, sizeof(array[0]), comparefunc);
        end = clock();
        cpu_time_used = ((double)(end - start));

        double base_time;

        if (maxsize == 100)
            base_time = cpu_time_used;

        printf("%6d %4.2f ", maxsize, cpu_time_used);
        printf(" ratio: %.1f", log10(100) / base_time * cpu_time_used / (log10(maxsize) * i));

        // assert (cpu_time_used == maxsize * log10(msize));

        /*for (int i = 0; i < maxsize; i++)
            printf("%d, ", array[i]);
        */
    }
    puts("\n-----end----");

    return 0;
}