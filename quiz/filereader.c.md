

# File Read Mystery

# Printing `sample.txt` 

A text file is provided and it has characters `A` and `B`. The contents are **printed** using the UNIX command `more`. The output is as follows:  
```bash 

~/workspace $ more sample.txt 
AAAABA
```
5 `A`s and 1 `B` is echo'ed to the console / output. 

# Program Listing 

Find below a C program `fileReader.c` attempts to count and validate the number of `B` characters that are available in the given file. 
```c
#include <stdio.h>
#include <stdlib.h>

int main() {

  FILE *fp = fopen ("write.file", "r"); 
  char buf; 
  int count = 0;

  while ((buf = fgetc(fp)) != '\0') {
    if (buf == 'B') 
        count++;
  }
  printf ("Number of B's counted %d\n", count); 
  return 0;
}

```

# Program Execution 

On compiling and executing the program `fileReader`, we get the following output. Although there is only 1 `B`, the program reports that there are 5

	~/workspace $ ./fileReader
	Number of B's counted 1

# Challenge 

1. Is the logic of the program correct? If the logic is wrong, change the program and report what is the output you get.  

2. If the logic is correct, then explain why the size of the file `sample.txt` is shown as `12` when we use the UNIX `ls -al` command or the Windows `dir` command? 

	```bash 
	~/workspace $ ls -al sample.txt
	
	-rw-rw-rw- 1 ubuntu ubuntu 12 Jan 27 04:41 sample.txt
	
	~/workspace $ 
	
	```