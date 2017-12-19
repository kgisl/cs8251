# UNIT V FILE PROCESSING  

[TOC]


Files – Types of file processing: Sequential access, Random access – Sequential access file - *Example* *Program: Finding average of numbers stored in sequential access file* -
Random access file - *Example Program: Transaction processing using* *random access files* – [Command line arguments](#command-line-arguments)


## Command line arguments

On many UNIX systems it’s possible to pass arguments to **`main`** from the command line by including the parameters **`int argc`** and **`char *argv[]`** in the parameter list of **`main()`**. 

  - Parameter **`argc`** receives the number of command-line arguments
  - Parameter **`argv`** is an array of strings in which the actual command-line arguments are stored  

- Common uses of command-line arguments include passing options to a program and passing filenames to a program.  
- **Program 5.3** below copies a file into another file one character at a time. We assume that the executable file for the program is called **mycopy**. A typical command line for the **mycopy** program on a Linux/UNIX system is  
	> `mycopy input output`  

- This command line indicates that file **input** is to be copied to file **output**. When the program is executed, if **argc** is not 3 (**mycopy** counts as one of the arguments), the program prints an error message and terminates. Otherwise, array **argv** contains the strings "mycopy", "input" and "output".   
- The second and third arguments on the command line are used as file names by the program. The files are opened using function **fopen**. If both files are opened successfully, characters are read from file **input** and written to file **output** until the end-of-file indicator for file input is set.   
- Then the program terminates. The result is an exact copy of file input (if no errors occur during processing).  

## Program 5.3

```
// Using command-line arguments
#include <stdio.h>

int main( int argc, char *argv[] )
{ 
   FILE *inFilePtr; // input file pointer
   FILE *outFilePtr; // output file pointer
   int c; // define c to hold characters read from the source file

   // check number of command-line arguments
   if ( argc != 3 ) {
      puts( "Usage: mycopy infile outfile" );
   } // end if
   else {
      // if input file can be opened
      if ( ( inFilePtr = fopen( argv[ 1 ], "r" ) ) != NULL ) {
         // if output file can be opened
         if ( ( outFilePtr = fopen( argv[ 2 ], "w" ) ) != NULL ) {
            // read and output characters
            while ( ( c = fgetc( inFilePtr ) ) != EOF ) {
               fputc( c, outFilePtr );
            } // end while

            fclose( outFilePtr ); // close the output file
         } // end if 
         else { // output file could not be opened
            printf( "File \"%s\" could not be opened\n", argv[ 2 ] ); 
         } // end else

         fclose( inFilePtr ); // close the input file
      } // end if
      else { // input file could not be opened
         printf( "File \"%s\" could not be opened\n", argv[ 1 ] );
      } // end else
   } // end else
} // end main

 
```