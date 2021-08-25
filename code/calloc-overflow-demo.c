#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Thanks to https://vorpus.org/blog/why-does-calloc-exist/
// Also read http://j.mp/cs2851-dynamicMemory
//
int main(int argc, char **argv)
{
    size_t huge = INTPTR_MAX;

    void *buf = malloc(huge * huge);
    if (!buf)
        perror("malloc failed");
    printf("malloc(huge * huge) returned: %p\n", buf);
    free(buf);

    buf = calloc(huge, huge);
    if (!buf)
        perror("calloc failed");
    printf("calloc(huge, huge) returned: %p\n", buf);
    free(buf);
}