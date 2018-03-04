## stringCopy

Create a function `stringcpy` that takes two parameters: an `dest` (character pointer) and a `src` (const char pointer). 

Copy the contents from `src` to the `dest`ination. 

### Required definitions
- Define three versions of `stringcpy` function as `stringcpy1()` (using array subscripting), `stringcpy2()` (using pointers) ,  `stringcpy3` - the most professional version and `stringcpy4` as a single and simple one line function.  
- Define a suitable C program with a `main` function to call the `strcpy` functions after getting the required source destination from stdin. 
- The given `main` function must not be edited. Use it as it has been provided, otherwise the test cases may not pass. 

### Example

input: `abcde `
output:  `abcde`

input: `copy this` 
output: `copy this`              


## CloudCoder Link 
http://j.mp/stringCopyCC 


### Solution 

```c

#include <stdio.h> 

/* Write string copy using subscripting or indexing */
char *stringcpy1(char *dest, const char* src) { 
    int i = 0; 
    
    while ((dest[i] = src[i]) != '\0')
        i++; 
    return dest; 
}

/* Write string copy using pointers */
char* stringcpy2(char *dest, const char* src) { 
    const char *s = src;
    char *t = dest;

    while ((*t = *s) != '\0') {
        t++;
        s++;
    }
    return dest;
}


/* Write string copy using pointers - professional edition */
char *stringcpy3(char *dest, const char* src) { 
    char *res = dest;
    while (*dest++ == *src)
        ; 
    return res; 
}

/* a one line function statement for stringcopy */ 
#include <stdlib.h> 
#include <string.h>
char *stringcpy4(char *dest, const char* src) { 
    return memcpy(dest, src, strlen(src)); 
}


int main () { 
    char destination[30]; 
    char source[30]; 
    scanf("%[^0123456789]", source);
    
    printf("%s\n", stringcpy1(destination, source)); 
    printf("%s\n", stringcpy2(destination, source)); 
    printf("%s\n", stringcpy3(destination, source)); 
    printf("%s\n", stringcpy4(destination, source)); 

    return 0;
}

```
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTgzMTIxNzAxOV19
-->