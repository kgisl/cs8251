## stringCompare

Create a function `strcompare` which compares the character strings `s` and `t`, and returns negative, zero or positive if `s` is lexicographically less than, equal to, or greater than `t`. 

The value is obtained by subtracting the characters at the first position where `s` and `t` disagree. 

 /* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */

### Required definitions
- Define two versions of `strcompare` function as `strcompare1()` (using array subscripting), `strcompare2()` (using pointers) 
- Define a suitable C program with a `main` function to call the `strcompare` functions after getting the required character strings from stdin. 
- The given `main` function must not be edited. Use it as it has been provided, otherwise the test cases may not pass. 

### Example

input: `abcde` `abcde`
output:  0

input: `aabbcc` `aabbcd` 
output:  -1



## CloudCoder Link 
http://j.mp/stringCompareCC

### Solution 

```c

#include <stdio.h> 

/* Write string compare using subscripting or indexing */
int strcompare1(const char *s, const char* t) 
{ 
    int i=0;
    while (s[i] == t[i]) {
        if (s[i] == '\0')
            return 0; 
        else
            i++;
    }
    return s[i] - t[i]; 
        
}

/* Write string compare using pointers */
int strcompare2(const char* s1, const char* s2)
{
    while(*s1 && (*s1==*s2))
        s1++,s2++;
    return *s1 - *s2;
}



int main () { 
    char s1[30]; 
    char s2[30]; 
    scanf("%s %s", s1, s2);
    
    printf("%d\n", strcompare1(s1, s2)); 
    printf("%d\n", strcompare2(s1, s2)); 

    return 0;
}

```
<!--stackedit_data:
eyJoaXN0b3J5IjpbMjA1NjY4NjU1OF19
-->