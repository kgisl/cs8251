

## stringCat

Write a pointer version of the function`strcat`  that  `strcat(s,t)`  copies the string`t`  to the end of  `s`  .

### Example

**input**  
abc de  
**output**  
abcde

**input**  
hello world  
**output**  
helloworld


### Solution 

```c

#include <stdio.h>

char* stringcat(char *s, const char *t) { 
   char *swalk = s;
   while (*swalk)      /* find end of s */
        swalk++;
    while (*t)      /* copy t */
        *swalk++ = *t++;
    *swalk = '\0';
    return s;
}

int main(void)
{
  char S1[8192]; // = "String One";
  char S2[8192]; // = "String Two";


  scanf("%s", S1);
  scanf("%s", S2);

  stringcat(S1, S2);
  printf("%s", S1);

  return 0;
}

```
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE2MzI4NjkwMDIsMTA0ODQ1MDk5NSwtMT
I1NDYyMjc1MiwxMDYxOTcyODE5LDIwNDg4NTU3Nl19
-->