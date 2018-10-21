


# Data Types 
There are four data types in C language. They are,

|Types| Data Types| 
|-----|------|
|Basic data types	|`int, char, float, double`|
|Derived data type | `pointer`_*_`, array `_[]_`, struct, union` |
|Void data type	| `void`|
|Enumeration data type|	`enum` |


## Types, Specifiers and Qualifiers
|Data Type |Storage Class Specifier|Modifier/Specifier| Type Qualifier | Composite | 
|----|-----|-------|-----|-----|
|int | extern (*global*)| short |  volatile | array *`[]`* | 
|char | static | signed, unsigned | const | struct |
|float | auto | long | | union |
|double | register | long long |
|*pointer*`*`|*typedef* * 
|*void*| 

## Valid combinations 

    char, signed char, unsigned char
    int, signed int, unsigned int
    short int, signed short int, unsigned short int
    long int, signed long int, unsigned long int
    float, double, long double

## Minimum Type Limits

Any compiler conforming to the Standard must also respect the following limits with respect to the range of values any particular type may accept. Note that these are _**lower limits**_: an implementation is free *to exceed* any or all of these. Note also that the minimum range for a char is dependent on whether or not a char is considered to be signed or unsigned.

#### Minimum Range Table
|Type|	Minimum Range|
|-----|:-------|
|signed char	|	-127 to +127 |
|unsigned char	|	0 to 255|
|short int		| -32767 to +32767 |
|int			|-32767 to +32767 |
|unsigned short int	|	0 to 65535 |
|unsigned int	|0 to 65535 |
|long int	|	-2147483647 to +2147483647 |
|unsigned long int	|	0 to 4294967295|

#### Minimum Precision Table 
|Type|	Minimum Precision| Remarks
|-----|:-------| ------|
|float	|	6 digits | _observed at 8 digits_
|double	|	10 digits| _observed at 17 digits_
|long double | 10 digits | _observed at 20 digits_

The Standard also specifies that these limits should be present as preprocessor macros in the header file `<limits.h>`

## Size and Range of Variable Types in C
For a **16-bit** operating system, here's a parital tabulation borrowed from [this](http://fresh2refresh.com/c-programming/c-data-types/) : 

|Modifier	| Variable Type | sizeof | Range | Precision |
|-----------|-----------|-----------------|:-----------|:-------|
|unsigned | char	| 1	| 0 to 256
|	| char 	| 1 | -127 to 127
|short		|int	| 2 | `–32,767` to `32,767` |
|			|int	| 2 | |
|unsigned 	|int	| 2	| 0 to `65,535`
|long 		|int	| 4 |`–2,147,483,647` to `2,147,483,647`|
|unsigned long 		|int	| 4 |0 to `4,294,967,295`|
|long long	|int	| 8 | `-(2^63 –1)` to `(2^63 –1)`
|unsigned long long | int | 8 | 0 to 2^(8bits*8bytes -1) = `2^64 - 1`
| | float | 4 | 1E-37 to 1E+37 | upto 6-9 significant digits e.g. `3.141592` or `3.14159`?|
| | double | 8 | | upto 15-17 significant digits  
| long  | double | 10 | 1E-37 to 1E+37 | precision to 10 decimal digits, e.g. `3.1415926535` or `3.141592653`? 


## Quiz 

1. A bank opened a banking account for Rangarajan who immediately deposited Rs 40,000. When Rangarajan tried to withdraw the entire amount (Rs 40,000) from the bank's ATM, the ATM terminal refused to issue any money. The reason is: 
	- No money in the ATM 
	- Erroneous banking software
	- Demonetization (2016) rules until December 31 
	- Anyone or all of the above
 
2. Next morning, the demonetization rules had been relaxed to withdraw up to Rs 50,000. Hearing about this, Rangarajan quickly located another ATM which had cash. Surprisingly, the ATM indicates that the customer had a negative bank balance of Rs `-25,536`. The reason is: 
	- Someone else withdrew all of the money from Rangarajan's account during the previous night 
	- The banking software had a bug 
	- The computer that powers the **ATM** has a virus 


3. Rangarajan is finally convinced that the bank is using a faulty software. What do you think is the main reason as to why the software is not working properly?
   - The bank software is designed to allow to dispense only small amounts
   - The bank software design adopted the wrong data type for storing customer balances. 
   - None of the above 

4. Meanwhile, Rangarajan found out that the bank was using a server powered by a 32-bit operating system to run its banking software (built using the **C** language). A software engineer himself, he got hold off of the source code of the banking software and started reviewing it. Immediately, he found out that the problem (*aka software bug*) was because of the data type that was used to store the customer bank balance. Which one was it?
	- `unsigned int` 
	- `int` 
	- `signed short int` 
	- `float` 

## Programming exercises 

#### Swap nibbles
Write a C program to swap value held by two nibble variables 
    - https://bytes.com/topic/c/answers/650530-nibble-variable

#### Pointer Snippet
6. Is the following code snippet valid? ***If*** yes, explain what the following code snippet is trying to do.

    ```c
    int *ip;
    ip = (int *)6;
    *ip = 0xFF;
    ``` 

#### Check Odd or Even

Write a program to check whether a number is odd or even without using the modulo  division or multiplication operators? 


## Sizeof Information 

    int ≥ 16 bits ≥ size of short
    long ≥ 32 bits ≥ size of int    
    long long ≥ 64 bits ≥ size of long

No, the standard defines the minimums which for `long` is `4 bytes` and `int` is `2 bytes`. As per the [C99 draft standard](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf) section `5.2.4.2.1` *Sizes of integer types limits.h* paragraph *1* says:

>[...]Their implementation-defined values shall be equal or greater in magnitude[...]

and for `long` we have:

     LONG_MIN -2147483647 // -(2^31 - 1)
     LONG_MAX +2147483647 // 2^31 - 1     
     
which is `4 bytes`. For completeness sake, we have the following for `int`:

     INT_MIN -32767 // -(2^15 - 1)
     INT_MAX +32767 // 2^15 - 1

which is `2 bytes`.

#### `sizeof` Program for various data types

To run / modify the below program, fork it at http://bit.ly/sizeofC

    #include <stdio.h>
    #include <limits.h>
    int main()
    {
       int a;
       char b;
       float c  = 12.34567890123456789;
       double d = 12.34567890123456789;
       printf("Storage size for int data type:     %d \n",sizeof(a));
       printf("Storage size for char data type:    %d \n",sizeof(b));
       printf("Storage size for float data type:   %d \n",sizeof(c));
       printf("Storage size for double data type:  %d \n",sizeof(d));
     
       int* aPointer; 
       void* vPointer; 
       printf("Storage size for int pointer type:  %d\n",sizeof(aPointer));
       printf("Storage size for void pointer type: %d\n",sizeof(vPointer));
     
       short int si; 
       long li;          // same as long int 
       long long lli;    // same as long long int
       long double ld = 12.34567890123456789;
       printf("Storage size for short int type:    %d\n",sizeof(si));
       printf("Storage size for long int type:     %d\n",sizeof(li));
       printf("Storage size for long long int type:%d\n",sizeof(lli));
       printf("Storage size for long double type:  %d\n",sizeof(ld));
     
       float       x  = .12345678901234567891234*10;
       double      z  = .12345678901234567891234*10;
       long double lz = .12345678901234567891234*10;
       printf("x=%f\n", x);
       printf("z=%f\n", z);
       printf("x=  %20.18f\n", x);    // precision to 7-8 significant digits
       // x=  1.234567880630493164
       printf("z=  %20.18f\n", z);    // precision to 14-17 significant digits
       // z=  1.234567890123456690
       printf("lz= %20.18Lf\n", lz);  // precision to 18-20 significant digits
       // lz= 1.234567890123456789
       return 0;
    }

##### Output 

    Storage size for int data type:     4  // when is it 2? 
    Storage size for char data type:    1 
    Storage size for float data type:   4 
    Storage size for double data type:  8 
    Storage size for int pointer type:  4
    Storage size for void pointer type: 4
    Storage size for short int type:    2
    Storage size for long int type:     4
    Storage size for long long int type:8
    Storage size for long double type:  12
    x=1.234568
    z=1.234568
    x=  1.234567880630493164
    z=  1.234567890123456690
    lz= 1.234567890123456789



## Useful References 

http://publications.gbdirect.co.uk/c_book/chapter8/const_and_volatile.html
http://www.ericgiguere.com/articles/ansi-c-summary.html
http://www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know/

