


### Pointer Declarations

http://j.mp/pointerArray10 vs http://j.mp/pointerToArray10

|Declaration
|:--------|
|`int (*p)[10];` |declare p as pointer to array of `size 10` of **int**|
|`int *p[10];` | declare p as array of `size 10` of pointer to int |
|`int (*p[10])();` |
|`int (*p)(char);`|  declare p as pointer to *function (char)* returning **int**, `isspace(char)` is an example|
|`int (*rp)[3][4]`| declare `rp` as pointer to array 3 of array 4 of int; rp points to a 2D array/matrix containing 4 rows and 3 columns
|`int (*(*foo)(void))[3];`| declare **foo** as pointer to *function (void)* returning pointer to array 3 of **int**|
|`int * (* (*fp1) (int) ) [10];`| declare fp1 as pointer to *function (int)* returning pointer to array 10 of pointer to **int**|

https://www.codeproject.com/articles/7042/how-to-interpret-complex-c-c-declarations#examples


### Which of the following options are valid? 

#### Option A
```c 

void swap (int* a, int* b) { 
	int* t;
	t = a; 
	a = b; 
	b = t; 	
}
```
####Option B
```c
void swap (int* a, int* b) { 
	int t;
	t  = *a; 
	*a = *b; 
	*b = t; 
}
```
#### Option C
```c
void swap (int* a, int* b) { 
	int t = *a; 
	*a    = *b; 
	*b    = t; 
}
```
#### Option D
```c
void swap (int* a, int* b) { 
	int* t = (int *)malloc (sizeof (int) );
	*t = *a; 
	*a = *b; 
	*b = *t;  
}
```

#### Option E

```c
void swap (int*a , int* b) { 
	int t = *a; 
	*a    = *b; 
	*b    = *t; 
}
```

### CC Exercise

http://j.mp/swapNumbers


#### Key for Declarations
|Declaration | Meaning | 
|:--------|:------------|
|`int (*p)[10];` |declare p as pointer to array of `size 10` of **int**|
|`int *p[10];` | declare p as array of `size 10` of pointer to `int` |
|`int (*p[10])();`| declare p as array of size 10 of pointer to `function returning int` |
|`int (*p)(char)`|  declare p as pointer to *function (char)* returning **int**, `isspace(char)` is an example|
|`int (*rp)[3][4]`| declare `rp` as pointer to array 3 of array 4 of int; rp points to a 2D array/matrix containing 4 rows and 3 columns
|`int (*(*foo)(void))[3];`| declare **foo** as pointer to *function (void)* returning pointer to array 3 of **int**|
|`int * (* (*fp1) (int) ) [10];`| declare fp1 as pointer to *function (int)* returning pointer to array 10 of pointer to **int**|


### Pointer to pointers 

```c

void swapPointers ();   // declaration could be wrong 

int main () { 
	int A = 5;  int* pA = &A; 
	int B = 50; int* pB = &B; 
	
	// define and call a swapPointers function to make 
	// ap point --> b and bp point --> a
	
	*pA = *pA + 1; 
	printf ("value of B incremented to %d!", *pA); 
	return 0; 
}

```

#### Quiz 2 

(1) All valid numbers are ***not*** pointers. 
(2) All valid pointers are **valid** numbers. 
(3) Some of positive whole numbers are **not** pointers. 
(4) All valid pointer values (other than **_0_**) are positive whole numbers. 

- All statements are true
- All statements are false 
- Statements 1 is false; Statements 2 is true
- Statements 2 is true; Statements 1 is false 
- Statement 3 is true and Statement 4 is true 
- All are ambiguous statements unless further information is available 
 

#### Spoiler ALERT! 


```c
-
-
-
-
-
-
--
---
-----
--------
------------------

void swapPointers (int** p_pA, int** p_pB) {
    int* temp; 
    temp  = *p_pA;  // put the address of pointer a in temp
    *p_pA = *p_pB;  // put the address of pointer b in pA 
    *p_pB = *temp;  // put the address of temp (a) in pB 
}
```
 
### Assignment quiz
Define an integer pointer pointing to an array of 10 integers. Read the integer
values from the keyboard. Find the sum, average, minimum and maximum of these 10 integers.

```c
	a = 10;
	b = 20;
	swap(a,b);
	printf(“%d%d”,a,b);
	swapref(&a,&b);
	printf(“%d%d”,a,b);
	
	void swap(int a, int b) {
		int t;
		t = a;
		a = b;
		b = t;
		printf(“%d%d”,a,b);
	}
	
	void swapref(int *a, int *b) { 
		int *t;
		t = a;
		a = b;
		b = t;
		printf(“%d%d”,*a,*b); 
	}

```




### Swapping structures using Pointers 
http://ideone.com/q350eb


```c
#include <stdio.h>

struct date { 
	int day; 
	int month; 
	int year;
};
struct student { 
	char name[30];
	char role[15]; 
	int  marks[3]; 
	struct date doj;   //--------- nested structure
};

//----------function using struct pointers
void print_student (struct student* s) { 
	puts("---------");
	printf ("Name: %s\n", s->name); 
	printf ("Role: %s\n", s->role); 
	printf ("Marks(1): %d\n", s->marks[0]); 
	printf ("Marks(2): %d\n", s->marks[1]); 
	printf ("Marks(3): %d\n", s->marks[2]); 
	printf ("DOJ: %d/%d/%d\n", s->doj.day, s->doj.month, s->doj.year); 
}

void swap_students (struct student*, struct student*);

int main(void) {
	struct student advik, gautam; 
	
	// Read Gautam details using structure notation
	scanf ("%s %s", gautam.name, gautam.role);
	scanf ("%d %d %d", &gautam.marks[0], &gautam.marks[1], &gautam.marks[2]); 
	scanf ("%d %d %d", &gautam.doj.day, &gautam.doj.month, &gautam.doj.year);

	// Read Advik details using pointer to structure notation 
	struct student* ap = &advik; 
	scanf ("%s %s", ap->name, ap->role);
	scanf ("%d %d %d", &ap->marks[0], &ap->marks[1], &ap->marks[2]); 
	scanf ("%d %d %d", &ap->doj.day, &ap->doj.month, &ap->doj.year);
	
	print_student (ap); 
	print_student (&gautam); 

	swap_students (&advik, &gautam); 	

	print_student(&advik); 
	print_student(&gautam); 
	
	return 0;
}

#include <string.h>
void swap_students (struct student* s1, struct student* s2) {
	
	struct student temp;   // int temp;
	
	strcpy (temp.name, s1->name);  // temp = a
	strcpy (temp.role, s1->role); 
	
	strcpy(s1->name, s2->name);  // a = b
	strcpy(s1->role, s2->role); 
	
	strcpy(s2->name, temp.name); // b = temp;
	strcpy(s2->role, temp.role);

}

```

#### No input (output: garbage values)
```
	Name: 
	Role: 47
	Marks(1): 134519060
	Marks(2): 134514194
	Marks(3): 1
	Name: -417372/-417364/1432526413
```

#### With input 
```
Input 
	Gautam 16Z125 90 99 99 7 7 97
	Advik 16Z102 100 99 99 17 1 98
```
Output 

```c 
	
	Name: Advik
	Role: 16Z102
	Marks(1): 100
	Marks(2): 99
	Marks(3): 99
	DOJ: 17/1/98
	---------
	Name: Gautam
	Role: 16Z125
	Marks(1): 90
	Marks(2): 99
	Marks(3): 99
	DOJ: 7/7/97
	---------
	Name: Gautam  // name and role swapped! 
	Role: 16Z125
	Marks(1): 100
	Marks(2): 99
	Marks(3): 99
	DOJ: 17/1/98
	---------
	Name: Advik   //
	Role: 16Z102  //
	Marks(1): 90
	Marks(2): 99
	Marks(3): 99
	DOJ: 7/7/97

```

### Matrix manipulation using Pointers as Parameters in Functions 

Adapted from http://j.mp/dynamicMatrix from GeekforGeeks
Try out the code on http://j.mp/matrixPointer

```clang
#include <stdio.h>
 
void add_matrix(int* res, int*ma, int*mb, int rmax, int cmax) { 
	// Define a pointer to walk the rows of the 2D array.
	int (*rp)[rmax] = res;
	int (*ap)[rmax] = ma; 
	int (*bp)[rmax] = mb; 
 
	// Define a pointer to walk the columns of each row of the 2D array.
	int *rcp, *acp, *bcp;
 
	// There are three rows in the 2D array.
	// p1 has been initialized to point to the first row of the 2D array.
	// Make sure the iteration stops after the third row of the 2D array.
	for (;rp < res + rmax;rp++, ap++, bp++) { // increment by rmax
		// Iterate over each column of the arrays.
	    // rcp is initialized to rp, which points to the first column.
    	// Iteration must stop after four (cmax) columns. 
	    for (rcp = rp, acp = ap, bcp = bp; rcp < rp+cmax;rcp++, acp++, bcp++) { 
	    	// cp will increment by 1
	    	*rcp = *acp + *bcp;  
	    	printf ("%d ", *rcp);
	    }
	    puts(""); 
	}
}
 
void sub_matrix(int* res, int*ma, int*mb, int rmax, int cmax) { 
	int (*rp)[rmax][cmax] = res;
	int (*ap)[rmax] = ma; 
	int (*bp)[rmax] = mb; 
 
	for (int i=0; i < rmax; i++) { 
	    for (int j=0; j < cmax; j++) {
	    	*(rp[i][j]) = *(ap[i]+j) - *(bp[i]+j); 
	    	printf ("%d ", *(rp[i][j])); 
	    }
	    printf ("\n"); 
	}
}
 
int main(void) {
	int r = 3, c = 4;
	int matrixA[3][4], matrixB[r][c];
	//int res[3][4]; 
	int *res = (int *)malloc(r * c * sizeof(int));
 
	for (int i = 0; i < 3; i++) {
		for (int j=0; j < 4; j++) { 
			scanf("%d",&matrixA[i][j]); 
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j=0; j < 4; j++) { 
			scanf("%d",&matrixB[i][j]); 
		}
	}
 
	add_matrix(res, matrixA, matrixB, 3, 4); 
	sub_matrix(res, matrixA, matrixB, 3, 4); 
	return 0;
}


```
<!--stackedit_data:
eyJoaXN0b3J5IjpbMjAyNjU0Njg1MSw2MzAzNTI3ODNdfQ==
-->