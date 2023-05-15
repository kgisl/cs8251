
Also see http://j.mp/cs2851-dynamicMemory 

![dma](http://bit.ly/dynamicMemory)

#### Why Dynamic Allocation
From https://en.wikipedia.org/wiki/C_dynamic_memory_allocation

0. The C programming language manages memory statically, automatically, or dynamically. **Static-duration** variables are allocated in main memory, usually along with the executable code of the program, and persist for the lifetime of the program; **automatic-duration** variables are allocated on the stack and come and go as functions are called and return. For static-duration and automatic-duration variables, the size of the allocation must be compile-time constant (*except* for the case of variable-length automatic arrays, e.g. `int vals[n];`). 
1. In many situations the programmer requires **greater flexibility** in managing the lifetime of allocated memory. If the required size is not known until run-time (for example, if **data of arbitrary size is being read from the user or from a disk file**), then using fixed-size data objects is inadequate.
2. These limitations are avoided by using dynamic memory allocation in which memory is more explicitly (but more flexibly) managed, typically, by allocating it from the free store (informally called the "heap"), an area of memory structured for this purpose. In C, the library function **malloc** is used to allocate a block of memory on the heap. The program accesses this block of memory via a pointer that malloc returns. When the memory is no longer needed, the pointer is passed to **free** which deallocates the memory so that it can be used for other purposes.

### Function Overview 
The C language provides for 
|Function| Description|No of Arguments | Example |
|----------|-----------|-----|----|
| malloc| allocates the specified number of bytes | **1** - size required | `malloc (30); int* p = malloc( sizeof(int));` 
| realloc |increases or decreases the size of the specified block of memory. Reallocates it if needed| **1** - size required|
| calloc| allocates the specified number of bytes and initializes them to zero| **2** - size and value to initialize it to| `calloc (30, 4);`
| free| releases the specified block of memory back to the system | **1** - the pointer variable which points to memory previously allocated to| `free(p);` // p has to be a valid pointer variable

### Usage Example 
Creating an array of ten integers with automatic scope is straightforward in C:

    int array[10];

However, the size of the array is fixed at compile time. If one wishes to allocate a similar array dynamically, the following code can be used:

    int * array = malloc(10 * sizeof(int));

This computes the number of bytes that ten integers occupy in memory, then requests that many bytes from malloc and assigns the result to a pointer named array (due to C syntax, pointers and arrays can be used interchangeably in some situations). Because malloc might not be able to service the request, it might return a **null pointer** and it is good programming practice to check for this:

    int * array = malloc(10 * sizeof(int));
    if (NULL == array) {
      printf("malloc failed\n");
      return(-1);
    }

Reallocate memory size from 4 bytes to 6 bytes (assume size of integer is 2 bytes). 

    int* ptr = (int *)malloc(sizeof(int)*2);
    int* ptr_new = (int *)realloc(ptr, sizeof(int)*3);

When the program no longer needs the dynamic array, it should call free to return the memory it occupies to the free store:

    free(array);

The memory set aside by malloc is not initialized and may contain **cruft** _(**garbage value**, the remnants of previously used and discarded data)_. After allocation with **malloc,** elements of the array are uninitialized variables. The command calloc will allocate and clear the memory in one step:

    int * array = calloc(10, sizeof (int));

allocates a region of memory large enough to hold 10 integers, and sets to zero all the bytes within that memory space.

Assume integer is 2 bytes wide. How many bytes will be allocated for
the following code?

```c
#include<stdio.h>
#include<stdlib.h>
#define MAXROW 3
#define MAXCOL 4

int main() {
	int *q;
	q = (int *)malloc(20);
	printf("%d\n", sizeof(q));
	free(q);

	int (*p)[MAXCOL];
	p = (int (*)[MAXCOL]) malloc( MAXROW* sizeof(*p));
	printf("%d, %d\n", sizeof(p), sizeof(*p));
	
	return 0;
}

```



### Dynamically allocating a matrix of size 3x4

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int r = 3, c = 4;
	int *arr = (int *)malloc(r * c * sizeof(int));

	int i, j, count = 0;
	for (i = 0; i < r; i++)
	for (j = 0; j < c; j++)
		*(arr + i*c + j) = ++count;

	for (i = 0; i < r; i++) {
    	for (j = 0; j < c; j++)
    		printf("%2d ", *(arr + i*c + j));
	    printf("\n"); 
	}

    /* Code for further processing and free the 
	dynamically allocated memory */
    free(arr); 
    
    return 0;
}
```
What will be the output? 

<!--stackedit_data:
eyJoaXN0b3J5IjpbMTExMDcyNTEwMSw2MjI0ODI1OTUsLTExMj
g2MTY0NDhdfQ==
-->
