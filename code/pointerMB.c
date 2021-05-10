// was used to create flashcards on 
// Memcode at http://bit.ly/memPointer

#include <stdlib.h> 
int main() { 
    void *a = malloc(100000); 
    int *ap = a;
    if (ap != 0) 
        for (int i = 0; i < 100000/sizeof(int); i++) {
            *ap = 1; 
            ap++; 
        }
    free(a);
    return 0;
}

