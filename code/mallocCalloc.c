// C program to demonstrate the use of calloc()
// and malloc()

// from https://www.geeksforgeeks.org/calloc-versus-malloc/
//
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
   int *arr;
    
   // malloc() allocate the memory for 5 integers
   // containing garbage values
   arr = (int *)malloc(5 * sizeof(int)); // 5* 4 bytes = 20 bytes
    
   // Deallocates memory previously allocated by malloc() function
   free( arr );
    
   // calloc() allocate the memory for 5 integers and
   // set 0 to all of them
   arr = (int *)calloc(5, sizeof(int)); // also 20 bytes
    
   // Deallocates memory previously allocated by calloc() function
   free(arr);
   
   // equivalent of calloc call 
   // ptr = malloc(size);
   // memset(ptr, 0, size);
 
   return(0);
}  

