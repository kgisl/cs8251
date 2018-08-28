

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
eyJoaXN0b3J5IjpbLTE0ODQzNDg2OTUsNjM3NDY2NjQ2LC0xNz
U1MTQxMTIzLC03NjkzMzk2NDIsLTE2MzI4NjkwMDIsMTA0ODQ1
MDk5NSwtMTI1NDYyMjc1MiwxMDYxOTcyODE5LDIwNDg4NTU3Nl
19
-->