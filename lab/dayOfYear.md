
## Day of Year 

Credits: 
_The C Programming Language, 2nd Edition, by Kernighan and Ritchie_, **Exercise 5.09 on page 114**

Consider the problem of date conversion, from day of the month to day of the year and vice versa. For example, March 1 is the 60th day of a non-leap year, and the 61st day of a leap year. Define the function to do the conversion: 

**day\_of\_year** converts the month and day into the day of the year, and 

**month_day** converts the day of the year into the month and day


### Example 

`day_of_year(2012, 3, 1)` == 61
`day_of_year(2011, 3, 1)` == 60


### Pointer practice

Modify / Refactor the existing code to use pointers to come up with the appropriate solution. 

Rewrite the routines  `day_of_year`  and  `month_day`  with pointers instead of indexing.


### Solution


```c

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
 };
 
 /* day_of_year: set day of year from month & day */
 int day_of_year(int year, int month, int day)
{
	int i, leap;
	char *p;
	
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

	/* Set `p' to point at first month in the correct row. */
	p = &daytab[leap][1];

	/* Move `p' along the row, to each successive month. */
	for (i = 1; i < month; i++) {
		day += *p;
		++p;
	}
	return day;
}

```

### Alternative 

```c 
int day_of_year(int year, int month, int day)
{
	int i, leap;
	char *p;
	
	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

	/* Set `p' to point at first month in the correct row. */
	//p = &daytab[leap][1];
	p = daytab[leap]; 
	
	/* Move `p' along the row, to each successive month. */
	for (i = 1; i < month; i++) {
		//day += *p;
		//++p;
		day += *++p;
	}
	return day;
}
```

<!--stackedit_data:
eyJoaXN0b3J5IjpbMTI2NzgyNTMzMl19
-->