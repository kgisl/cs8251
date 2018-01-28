
[TOC]

# Sorting

This document presents two solutions for the sorting of strings. 

  - The first solution uses a fixed sized array (of size `MAX_LEN = 100`). The array is filled up with 4 arbitrary strings ( in the `main` function which is a sample driver). Sorting is accomplished using `Selection Sort` (the pseudo code in Python is presented in [here](#selection-sort-pseudo-code) below. 

A scaffold code might help get you started. 
```c
#include <stdio.h> 
#include <string.h> 
#define MAX_LEN 100

void selection_sort(char strings[][MAX_LEN], int size){
    return;
}

int main () { 
    char strings[10][MAX_LEN]; 
    int i = 0;
    int c = 0;
    //Read the strings into the array #1
    while((c=scanf("%s", strings[i])) != -1) {
        //printf("%s ", strings[i++]);
        //strings[i][strlen(strings[i])] = '\0';
        i++;
    }
    // The most important part #3
    // How to sort them?
    selection_sort(strings, i);

    //Print the strings from the array #2
    while (i>0)
    //for (int j = 0; j <i; j++)
        printf("%s ", strings[--i]);
    
    //sliming effort! 
    //printf("alpha beta omega phi zeta");
}
```

## Selection sort of strings (Unit 2)


```c
#include <stdio.h> 
#include <string.h> 
// C program to implement selection sort for
// array of strings.
#define MAX_LEN 100
// Sorts an array of strings where length of every
// string should be smaller than MAX_LEN
// Essentially, a two step process
//   - STEP 1 select the index of the minimum out of the sub-array
//   - STEP 2 swap the value with a pre-determined location 
//   - do it for the entire list of numbers 
void selection_sort(char arr[][MAX_LEN], int n)
{
    int i, j, min_idx;
    char minStr[MAX_LEN];
    for (i = 0; i < n-1; i++){
        // Find the minimum element in unsorted array
        min_idx = i;
        strcpy(minStr, arr[i]);
        for (j = i+1; j < n; j++){
            // If min is greater than arr[j]
            if (strcmp(minStr, arr[j]) > 0){
                // make arr[j] as minStr and update min_idx
                strcpy(minStr, arr[j]);
                min_idx = j;
            }
        }
  
        // Swap the found minimum element with element
        // in predetermined location 'i'
        if (min_idx != i){
            char temp[MAX_LEN];
            strcpy(temp, arr[i]); //swap item[pos] and item[i]
            strcpy(arr[i], arr[min_idx]);
            strcpy(arr[min_idx], temp);
        }
    }
}
// Driver code
int main(){
    char names[100][MAX_LEN] = {"beta", "alpha", "zeta", "omega"};
    int count = 4;
    selection_sort(names, count);
    printf("\nSorted array is\n");
    for (int i = 0; i < count; i++)
        printf("%s ", names[i]);
    return 0;
}
```
## Array of Pointers (Unit 3)

  - The second solution uses an array of pointers which each point to a dynamically allocated array of characters. The sorting is done using `qsort` which comes standard as part of the C library


```c
#include <stdio.h> 
#include <string.h> 

int comparator(const void* a, const void* b){
    const char* pa = *(const char**)a; 
    const char* pb = *(const char**)b; 
    //printf("%s %s\n", pa, pb); 
    return strcmp(pa, pb); 
    //return (*(char*)a) < (*(char*)b);
    
}

int main () { 
    char *names[10];
    int res;
    int count = 0;
    char buf[20];
    while ((res = scanf("%s", buf)) != EOF){
    //while (fgets(buf, 20, stdin) != NULL){
        names[count] = malloc(sizeof(int)*res);
        strcpy(names[count++], buf); 
        printf("%s ", buf);
    }

    qsort(names, count, sizeof(char*), comparator); 
    for (int i = 0; i < count; i++)
        printf("%s ", names[i]);
        
    return 0;
}

```

## CloudCoder link
- http://j.mp/selectionSortCC (pseudo code)  
- http://j.mp/sortLikeUnix

### Selection Sort Pseudo code

```python
def selectionsort(alist):
    for i in range(len(alist)-1):
        #form a sublist containing unsorted elements
        sublist = alist[i:]
        
        #select the smallest value and find its index
        smallest = min(sublist)
        index_of_smallest = alist.index(smallest, i)
        
        #swap it with element at index 'i'
        if index_of_smallest != i:
            temp = alist[i]
            alist[i] = alist[index_of_smallest]
            alist[index_of_smallest] = temp        
    return alist
```