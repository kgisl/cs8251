
# Parameter Passing

Credits: http://j.mp/callByValueC 

# Call by Value vs Call by Reference

What is the difference between **call by value** and **call by reference** in C language?

There are two ways to pass arguments/parameters to function calls -- call by value and call by reference. The major difference between call by value and call by reference is that in call by value a copy of actual arguments is passed to respective formal arguments. While, in call by reference the location (address) of actual arguments is passed to formal arguments (aka *parameters*), hence any change made to formal arguments will also reflect in actual arguments.

In C, all function arguments are passed "by value" because C does not support references like C++ and Java do. In C, the calling and called functions do not share any memory -- they have their own copy and the called function cannot directly alter a variable in the calling function; it can only alter its private, temporary copy.

The call by value scheme is an asset, however, not a liability. It usually leads to more compact programs with fewer extraneous variables, because parameters can be treated as conveniently initialized local variables in the called routine. Yet, there are some cases where we need call by reference:
 
1. The called function communicates to the calling function only through return statement and return statement can only send only one value back to the calling function. If there are more than one value we want to alter, call by reference is required. 
2. If the size of data is large , copying actual arguments to formal arguments could be a time consuming operation and occupies more memory.

The **call by value** does not address above cases, hence we need **call by reference**. To achieve call by reference functionality in C language the calling function provides the address of the variable to be set (technically a pointer to the variable), and the called function declares the parameter to be a pointer and access the variable indirectly through it. Since the address of the argument is passed to the function, code within the called function can change the value of the actual arguments.

While **studying call by value** and **call by reference** in C it is important to note that the story is different for arrays. When the name of an array is used as an argument, the value passed to the function is the location or address of the beginning of the array --there is no copying of array elements. By sub-scripting this value, the function can access and alter any element of the actual array.

| call by value     | call by reference|
|:------------------|:-----------------|
|In call by value, a copy of actual arguments is passed to formal arguments of the called function and any change made to the formal arguments in the called function have no effect on the values of actual arguments in the calling function.|                            In call by reference, the location (address) of actual arguments is passed to formal arguments of the called function. This means by accessing the addresses of actual arguments we can alter them within from the called function.|
|In call by value, actual arguments will remain safe, they cannot be modified accidentally.|                                               In call by reference, alteration to actual arguments is possible within from called function; therefore the code must handle arguments carefully else you get unexpected results.|

 
## Example using Call by Value  
The classic example of wanting to modify the caller's memory is a `swap_by_value()` function which exchanges two values. Since C language uses call by value, the following version of swap **`swap_by_value()`** will not work...

```c
#include <stdio.h>
 
void swap_by_value(int, int); /* Prototype */
 
int main() /* Main function */
{
  int n1 = 10, n2 = 20;
 
  /* actual arguments will be as it is */
  swap_by_value(n1, n2);
  printf("n1: %d, n2: %d\n", n1, n2);
}
 
void swap_by_value(int a, int b)
{
  int t;
  t = a; a = b; b = t;
}
```

### Output   
```
n1: 10, n2: 20
```
The **`swap_by_value()`** does not affect the arguments `n1` and `n2` in the calling function it only operates on `a` and `b` local to **`swap_by_value()`** itself. This is a good example of how local variables behave.

## Example using Call by Reference
In call by reference, to pass a variable n as a reference parameter, the programmer must pass a pointer to n instead of n itself. The formal parameter will be a pointer to the value of interest. The calling function will need to use `&` to compute the pointer of actual parameter. The called function will need to dereference the pointer with `*` where appropriate to access the value of interest. Here is an example of a correct swap **`swap_by_reference()`** function. So, now you got the difference between call by value and call by reference!

```c

#include <stdio.h>
 
void swap_by_reference(int*, int*); /* Prototype */
 
int main() /* Main function */
{
  int n1 = 10, n2 = 20;
 
  /* actual arguments will be altered */
  swap_by_reference(&n1, &n2);
  printf("n1: %d, n2: %d\n", n1, n2);
}
 
void swap_by_reference(int *a, int *b)
{
  int t;
  t = *a; *a = *b; *b = t;
}
 
```

**Output**  
```
n1: 20, n2: 10
```