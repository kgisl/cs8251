#include <stdio.h> 

int main () { 
    printf ("I am destroyed before your compile completes!\n"); 
    remove ("a.out");
    perror("remove");
    return 0;

}