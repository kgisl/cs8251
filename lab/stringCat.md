

## stringCat

Write a pointer version of the function`strcat`  that  `strcat(s,t)`  copies the string`t`  to the end of  `s`  .

### Example

**input**  
`abc` `de`  
**output**  
`abcde`

**input**  
`hello` `world`  
**output**  
`helloworld`


### Solution 

```c

#include <stdio.h>

char* stringcat(char *swalk, const char *t) { 
    char *start = swalk; 
    while (*swalk && swalk++)
        ; // move to the end of s
    while((*swalk++ = *t++))
        ; // copy from t at the end of s
    return start;
}


int main(void)
{
  char S1[8192]; // = "String One";
  char S2[8192]; // = "String Two";


  scanf("%s", S1);
  scanf("%s", S2);

  printf("%s", stringcat(S1, S2));

  return 0;
}

```
<!--stackedit_data:
eyJoaXN0b3J5IjpbNjM3NDY2NjQ2LC0xNzU1MTQxMTIzLC03Nj
kzMzk2NDIsLTE2MzI4NjkwMDIsMTA0ODQ1MDk5NSwtMTI1NDYy
Mjc1MiwxMDYxOTcyODE5LDIwNDg4NTU3Nl19
-->