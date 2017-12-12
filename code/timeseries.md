# Calculate sine series


![sine0](https://codingconnect.net/wp-content/uploads/2016/01/sine-series1.png)

First, calculating the radian value of `x` as : 

![sine01](https://codingconnect.net/wp-content/uploads/2016/01/radian.png) 

translates to 

![sine](https://codingconnect.net/wp-content/uploads/2016/01/sine.png)

Write a program to calculate the sine series of a number. Accept two values on the standard in. The first value is that of value of `x` in degrees and second is `n`, the number of components that need to be calculated for the time series summation. 


## Example 

`sine_series(30, 5) -> .5000`

`sine_series(60, 5) -> .8660`



### Code for calculation 
Credits: https://www.codingconnect.net/c-program-sine-series/

```c
#include <stdio.h>
#include <math.h> 

int main()
{
    int i, n;
    float x, sum, t;

    printf(" Enter the value for x : ");
    scanf("%f",&x);
    
    printf(" Enter the value for n : ");
    scanf("%d",&n);
    
    x   = x * M_PI/180;  // radian value
    t   = x;             // first component
    sum = x;             // initialize the sum
    
    /* Loop to calculate the value of sine */
    for(i=1; i<=n; i++)
    {
        t=(t*(-1)*x*x)/(2*i*(2*i+1));
        sum=sum+t;
    }
    
    printf(" The value of sin(%f) = %.4f",x,sum);
}

```