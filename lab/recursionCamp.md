
## Table of Contents

[TOC]

[Understanding recursion](http://j.mp/recursionGrok)



* [Table of Contents](#table-of-contents)  
	* [Why Recursion? - Pros and Cons](#why-recursion---pros-and-cons)  
		* [Quiz 1](#quiz-1)  
		* [Quiz 2](#quiz-2)  
	* [Recursive Natural Number Summation](#recursive-natural-number-summation)  
		* [http://j.mp/naturalRecKG](#httpjmpnaturalreckg)  
		* [Output](#output)  
	* [Recursive Power Calculation](#recursive-power-calculation)  
		* [http://j.mp/powerRecKG](#httpjmppowerreckg)  
	* [Recursive Factorial](#recursive-factorial)  
		* [http://j.mp/factorialRecKG](#httpjmpfactorialreckg)  
	* [Recursive GCD of Two Numbers](#recursive-gcd-of-two-numbers)  
		* [http://j.mp/gcdRecKG](#httpjmpgcdreckg)  
	* [Recursive Fibonacci Series](#recursive-fibonacci-series)  
		* [http://j.mp/fiboRecKG](#httpjmpfiboreckg)  
		* [Output](#output)  
	* [Recursive Sum of Integer Array](#recursive-sum-of-integer-array)  
		* [http://j.mp/arraysumRecKG](#httpjmparraysumreckg)  
	* [Recursive Palindrome](#recursive-palindrome)  
		* [http://j.mp/palindromeRecKG](#httpjmppalindromereckg)  
		* [Output](#output)  
	* [Recursive Palindrome Number](#recursive-palindrome-number)  
	* [Recursive Linked List](#recursive-linked-list)  
		* [http://j.mp/linkedRecKG](#httpjmplinkedreckg)  
		* [Output](#output)  
	* [Alternative Fibonacci](#alternative-fibonacci)  
		* [Output](#output)  
	* [Recursive HalfOf](#recursive-halfof)  
		* [http://j.mp/halfOfRecKG](#httpjmphalfofreckg)  
	* [Tower of Hanoi](#tower-of-hanoi)  
		* [http://j.mp/towerOfHanoiCC](#httpjmptowerofhanoicc)  
	* [Right Numeric Triangle](#right-numeric-triangle)  
		* [http://j.mp/recRightTriangle](#httpjmprecrighttriangle)  
	* [Recursive Sorts](#recursive-sorts)  
		* [Selection Sort](#selection-sort)  
			* [http://j.mp/selectionSortCC](#httpjmpselectionsortcc)  
		* [Insertion Sort](#insertion-sort)  
			* [http://j.mp/insertionSortCC](#httpjmpinsertionsortcc)  
		* [Merge Sort](#merge-sort)  
		* [Quick Sort](#quick-sort)  


### Why Recursion? - Pros and Cons 

- Read this reddit [article!](https://www.reddit.com/r/learnprogramming/comments/8axanq/recursion_when_would_i_use_it_beyond_factorials/ )

_"Recursive functions are confusing, elegant and fascinating, all the same time!"_

Some programs and/or computer algorithms are more readable, concise and less error prone when implemented as recursive calls. The **downside:** low performance and high memory usage, especially when there are innumerable recursive calls, sometimes resulting in memory overflow conditions on the stack.

Almost any iterative code (containing loops) can be re-written as a smaller, simpler (*but not always intuitive*) recursive program. The general recipe for writing a recursive calls can be broadly categorized as three steps:

1. Determine the **TERMINAL CONDITIONS** under which the recursive calls will terminate and return. This is usually a combination of `if` statement and a`return` statement 
2. Do some computation as required by the problem (e.g. add, multiply or printing) including determining parameter(s) for the next recursive call
3. A `return` statement containing a recursive function call with new parameters

Also review - https://goo.gl/photos/z6LBsEh6NcZJ3AvN7  

#### Quiz 1
> ##### http://j.mp/halfOfRecKG
>Given an integer number, write a recursive function `halfOf` which will generate a sequence of numbers that will be progressively *half of* what the previous number was. The program must terminate when the value of the number in the sequence is zero. For e.g. `halfOf (21) = 21 10 5 2 1`.  
>To visualize the solution for this exercise, click http://j.mp/halfOfV

#### Quiz 2

```c
#include <stdio.h> 
int main () { 
    int x, num = 5; 
    x = call(num); 
    printf ("%d\n", x);    
    return 0;
}

int call(int num) {
    static int x = 1, y; 
    if (num >0) {
        x = x+num-1;      
        y = call(num-1)+2;
    }
    return x;
}
```
The output is 
`A) 10 	B) 8 C) 12 D) 11`


### Recursive Natural Number Summation
####http://j.mp/naturalRecKG
```c

#include <stdio.h> 

int naturalSum (int n) { 
	if (n == 1)  // TERMINAL CONDITION 
		return 1; 
	return n + naturalSum(n-1); 
}

int main () { 
	int n = 10; 
	int sum = naturalSum (n); 
	printf ("sum of %d natural numbers is %d\n", n, sum); 
	return 0;
}

```
#### Output 
```
sum of 10 natural numbers is 55
```

### Recursive Power Calculation
####http://j.mp/powerRecKG

```c
#include <stdio.h> 

int power (int x, int y) { 
    if (y == 0)     // TERMINAL CONDITION
        return 1; 
        
    return x * power (x, y-1); 
}

int main () {

    int x = 5; 
    int y = 3; 
    int result = power (x, y); 
    printf ("%d to the power of %d is = %d\n", x, y, result);
    return 0;

}
```



### Recursive Factorial 
####http://j.mp/factorialRecKG

```c
#include <stdio.h> 

int factorial (int n) { 
    if ( n == 0 || n == 1)  // TERMINAL CONDITION
        return 1;
    return n * factorial (n-1);
}

int main (int argc, char** argv) { 

    int number = atoi (argv[1]); // or do scanf()
    int fval   = factorial(number);
    printf ("The factorial of %d is %d\n", number, fval); 
    
    return 0;
}
```

### Recursive GCD of Two Numbers 
#### http://j.mp/gcdRecKG
```c

#include <stdio.h> 

int gcd (int a, int b) { 
    if (b==0)     // TERMINAL CONDITION
        return a; 
        
    return gcd(b, a%b); 
}

int main () {

    int x = 366; 
    int y = 60;
    
    int result = gcd (x, y); 
    printf ("GCD of %d and %d is %d\n", x, y, result); 
    return 0;
}

```


### Recursive Fibonacci Series
####http://j.mp/fiboRecKG

Here's a video recording from Khan Academy - worth understanding how it unfolds - http://j.mp/fiboKG

```c
#include<stdio.h>
 
int fibonacci_rec(int n) {
   if ( n == 0 )    // TERMINAL CONDITION_1
      return 0;
   else if ( n == 1 ) // TERMINAL CONDITION_2
      return 1;
   else
      return fibonacci_rec(n-1) + fibonacci_rec(n-2);
} 
 
int main() {
   int n, i = 0, c;
   scanf("%d",&n);
   printf("Fibonacci series\n");
   for ( c = 1 ; c <= n ; c++ ) {
      printf("%d ", fibonacci_rec(i));
      i++; 
   }
   return 0;
}
```

####Output 
```
13
Fibonacci series
0 1 1 2 3 5 8 13 21 34 55 89 144
```

### Recursive Sum of Integer Array
####http://j.mp/arraysumRecKG

```
#include <stdio.h> 

int rec_sum (int* s, int size) { 
    if (size == 0)  // TERMINAL CONDITION
        return 0; 

    int sumval = *s; // get element
    return sumval + rec_sum(++s, size-1); 
}

int main () {
    int s[7] = {1, 2, 3, 4, 5, 6, 7};
    int sum  = rec_sum (s, 7); 
    
    printf ("The sum is %d\n", sum); 
    return 0;
}
```

### Recursive Palindrome 
#### http://j.mp/palindromeRecKG

```c
#include <stdio.h> 
#include <string.h> 

int palin_rec (char *s) { 
    static int i   = 0; 
    
    int front      = i;
    int back       = strlen(s)-i-1;
    
    if (front >= back)   // TERMINAL CONDITION_1
        return 1; 

    printf ("%c == %c? // ", s[front], s[back]);
    
    if (s[front] != s[back]) {  // TERMINAL CONDITION_2
        return 0;
    }

    i++;
    return palin_rec (s); 
    
}

int main () { 

    char input[30]; 
    scanf ("%s", input); 
    
    char* front = input;
    char* back  = input + strlen(input)-1; 
    
    int res = palin_rec (input); 
    
    printf ("%s is a palindrome: %s\n ", input, 
        (res==1? "True" : "False")); 

    return 0; 
}
```

#### Output
```
m == m? // a == a? // l == l? // a == a? // 
malayalam is a palindrome: True

a == a? // b == b? // c == c? // d == f? // 
abcdefcba is a palindrome: False
```

### Recursive Palindrome Number
For checking whether a number is a **palindrome number**, along with the same recursive function above, use the following main() function: 

```c
#include <string.h>  // for sprintf () function call
int main () {

	int i = 23044032; 
	char input[30];
	sprintf (input, "%d", i); // buf ==  "23044032"; 

	int res = palin_rec (input); 
	printf ("%s is a palindrome: %s\n ", input, 
        (res==1? "True" : "False")); 

    return 0; 
}
```

### Recursive Linked List
#### http://j.mp/linkedRecKG
```c
#include <stdio.h> 
#include <stdlib.h> 

struct node { 
    int data; 
    struct node* next;
};

typedef struct node Node; 

Node *head = NULL;

Node* traverseTail (Node* np) {
    if (np == NULL)        // TERMINAL CONDITION_1
        return 0; 
    if (np->next == NULL)  // TERMINAL CONDITION_2
        return np;
    
    return traverseTail (np->next); 
}

int traverseSum (Node* np, int i) {
    
    if (np == NULL)    // TERMINAL CONDITION
        return 0; 

    printf ("node %d: %d\n", i++, np->data);
    return np->data + traverseSum(np->next, i); 
}

Node* createNode (int val) { 
    Node* n = (Node*) malloc (sizeof (struct node));
    n->data = val;
    n->next = NULL; 
    
    return n;
}

int main () { 

    int numbers[8] = {1, 2, 3, 4, 5, 6, 7, 8}; 

    // forming the linked list
    Node* head = (Node*)malloc (sizeof(struct node));
    Node* np = head; 
    
    int i;
    for (i = 0; i< 8;i++, np = np->next) {
        np->next = createNode(numbers[i]); 
    }

    int res = traverseSum (head->next, 0);
    printf ("Sum of the elements in list %d\n", res);
    
    res = traverseTail(head)->data;
    printf ("Tail data is %d\n", res); 
    
    return 0;

}
```

####Output 

```
node 0: 1
node 1: 2
node 2: 3
node 3: 4
node 4: 5
node 5: 6
node 6: 7
node 7: 8
Sum of the elements in list 36
Tail data is 8
```

### Alternative Fibonacci

```c
#include <stdio.h> 

int generate_fibo (int fibopp, int fibop, int count, int slen) { 

    int fibo = fibopp + fibop;
    printf ("%d ", fibo);

    if (count == slen) {   // TERMINAL CONDITION
        return fibo;       // for the nth Fibonacci number
    }

    // prepare to generate the next in sequence
    fibopp   = fibop; 
    fibop    = fibo;
    return generate_fibo (fibopp, fibop, count+1, slen); 
}

main (int argc, char** argv) { 

    int seq_length = atoi (argv[1]);
    if (seq_length <= 2) return 1; 
    
    printf ("The fibonacci sequence (%d) is ", seq_length); 

    int fibo1 = 0, fibo2 = 1;
    printf ("%d %d ", fibo1, fibo2);
    int fibFinal = generate_fibo (fibo1, fibo2, 3, seq_length);

    printf ("\nThe %d in fibonacci sequence is %d\n", seq_length, fibFinal); 
    
    return 0;
}

```

#### Output 
```
The fibonacci sequence (13) is 0 1 1 2 3 5 8 13 21 34 55 89 144 
The 13 in fibonacci sequence is 144

```

### Recursive HalfOf
#### http://j.mp/halfOfRecKG

```
#include <stdio.h> 

void halfOf (int val) { 

    if (val == 0)          // #1 TERMINAL CONDITION
        return; 
        
    printf ("%d ", val);   // #2 Do something 
    halfOf (val/2); // #3 Make the recursive call    
}

int main () 
{
    int start = 21;
    halfOf (21); 
    return 0;
}
```

To visualize this code, click http://j.mp/halfOfV

<iframe width="800" height="500" frameborder="0" src="http://pythontutor.com/iframe-embed.html#code=%23include%20%3Cstdio.h%3E%20%0A%0Avoid%20halfOf%20(int%20val%29%20%7B%20%0A%0A%20%20%20%20if%20(val%20%3D%3D%200%29%20%0A%20%20%20%20%20%20%20%20return%3B%20%0A%20%20%20%20%20%20%20%20%0A%20%20%20%20printf%20(%22%25d%20%22,%20val%29%3B%20%0A%20%20%20%20return%20halfOf%20(val/2%29%3B%0A%20%20%20%20%0A%7D%0A%0Aint%20main%20(%29%20%0A%7B%0A%20%20%20%20int%20start%20%3D%2021%3B%0A%20%20%20%20%0A%20%20%20%20halfOf%20(21%29%3B%20%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%0A%7D&codeDivHeight=400&codeDivWidth=350&curInstr=10&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D"> </iframe>


### Tower of Hanoi

#### http://j.mp/towerOfHanoiCC 

### Right Numeric Triangle

#### http://j.mp/recRightTriangle 

### Subsequence

#### http://j.mp/subseqCC 

### Recursive Sorts

#### Selection Sort 

##### http://j.mp/selectionSortCC 


```python
# https://code.activestate.com/recipes/576917-functional-selection-sort/#c1 

def selectsortr(l):
    if not l: return []
    idx, v = min(enumerate(l), key=operator.itemgetter(1))
    print(v, l[:idx], l[idx+1:])
    return [v] + selectsortr(l[:idx] + l[idx + 1:])

or 

def selectsortr(L):
    if not L: return []
    smallest = min(L)
    L.remove(smallest)
    return [smallest] + selectsortr(L)
    
```

#### Insertion Sort 

##### http://j.mp/insertionSortCC 

```python 

import bisect

def insertion_sort(L, nsorted=1):
    if nsorted >= len(L):
        return L
    bisect.insort(L, L.pop(), hi=nsorted)
    return insertion_sort(L, nsorted + 1)
```

#### Merge Sort
```python
from heapq import merge
def mergesort(w):
    if len(w) < 2:
        return w
    else:
        mid = len(w) // 2
        return merge(mergesort(w[:mid]),
                     mergesort(w[mid:]))
                     
```

#### Quick Sort 

```python 
def quicksort(s):
    len_s = len(s)
    if len_s < 2:
        return s

  pivot = s[random.randrange(0, len_s)]

  L = [x for x in s if x < pivot]
  E = [x for x in s if x == pivot]
  G = [x for x in s if x > pivot]

  return quicksort(L) + E + quicksort(G)

```



**Javascript alternative for selectsort**

```javascript 
// helper function that returns the index of the
// minimum value in the array 
function indexOfMinValue(arr){
    return arr.reduce((iMin, x, i) => x > arr[iMin]? iMin : i, -1);
}
function selectSortR(a){
  if (!a.length) return [];                     // #1
  let minVal = a.splice(indexOfMinValue(a), 1); // #2 and #3 
  return [minVal].concat(selectSortR(a));       // #4 and #5
}
```

