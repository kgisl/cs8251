## stringCat

Write a pointer version of the function  `strcat`  that `strcat(s,t)`  copies the string  `t`  to the end of  `s`  .


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
    char* swalk = s; 
    
    while (*swalk++);  /* Get to the end of the string */
    swalk--; // Move one step back 
    while((*swalk++ = *t++));
    
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
eyJoaXN0b3J5IjpbMjY3NzA2MTY1XX0=
-->