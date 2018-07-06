

Write a pointer version of the function  `strncat`  that `strncat(s,t, n)`  copies the first `n` characters of string  `t`  to the end of  `s`  .


### Example 

**input** 
abc de 2
**output** 
abcde

**input** 
hello world 3 
**output** 
hellowor 


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
eyJoaXN0b3J5IjpbMTA0ODQ1MDk5NSwtMTI1NDYyMjc1MiwxMD
YxOTcyODE5LDIwNDg4NTU3Nl19
-->