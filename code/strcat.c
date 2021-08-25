
/*

 Exercise 5-3. Write a pointer version of the function strcat that we showed in
               Chapter 2: strcat(s,t) copies the string t to the end of s.

 implementation from chapter 2:

/ * strcat:  concatenate t to end of s; s must be big enough * /
void strcat(char s[], char t[])
{
 int i, j;

 i = j = 0;
 while (s[i] != '\0')  / * find end of s * /
   i++;
 while ((s[i++] = t[j++]) != '\0')  / * copy t * /
   ;
}


 Author : Bryan Williams

*/

/* strcat:  concatenate t to end of s; s must be big enough; pointer version */
void mystrcat(char *s, char *t)
{
    /* run through the destination string until we point at the terminating '\0'
     */
    while ('\0' != *s)
    {
        ++s;
    }

    /* now copy until we run out of string to copy */
    while ('\0' != (*s = *t))
    {
        ++s;
        ++t;
    }
}

// concise version of strcat
void mystrcat2(char *dest, const char *source)
{
    while (*dest)
        dest++;
    while ((*dest++ = *source++))
        ;
}

#define DRIVER 6

#if DRIVER
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char S1[33] = "String One";
    char S2[11] = "String Two";

    printf("String one is (%s)\n", S1);
    printf("String two is (%s)\n", S2);

    mystrcat(S1, S2);
    //"The combined string is (String OneString Two)"
    printf("The combined string is (%s)\n", S1);

    // before copying again, assert there is space in S1
    assert(sizeof(S1) > strlen(S1) + strlen(S2));
    mystrcat2(S1, S2);
    //"The combined string is (String OneString TwoString Two)"
    printf("The combined string is (%s)\n", S1);

    // before copying again, assert there is space in S1
    assert(sizeof(S1) > strlen(S1) + strlen(S2));
    mystrcat2(S1, S2); // will not execute, since assert will abort
    printf("The combined string is (%s)\n", S1);

    return 0;
}

#endif
