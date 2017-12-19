**Table of Contents**

* [UNIT V FILE PROCESSING](#unit-v-file-processing)  
	* [Files](#files)  
		* [Files and Streams](#files-and-streams)  
		* [Types of file processing](#types-of-file-processing)  
	* [Creating a Sequential Access file](#creating-a-sequential-access-file)  
		* [Reading Sequential Access file](#reading-sequential-access-file)  
* [include <stdio.h>](#include-stdioh)  
* [include <stdio.h>](#include-stdioh)  
		* [Read numbers from file and calculate Average](#read-numbers-from-file-and-calculate-average)  
			* [Example Program: Average of numbers](#example-program-average-of-numbers)  
* [include <stdio.h>](#include-stdioh)  
			* [Example Program: Average of numbers read from a file](#example-program-average-of-numbers-read-from-a-file)  
	* [Random access file](#random-access-file)  
		* [Creating Random Access File](#creating-random-access-file)  
* [include <stdio.h>](#include-stdioh)  
		* [Writing Data](#writing-data)  
		* [Reading Data](#reading-data)  
* [include <stdio.h>](#include-stdioh)  
		* [Transaction processing using random access files](#transaction-processing-using-random-access-files)  
* [include <stdio.h>](#include-stdioh)  
	* [Command line arguments](#command-line-arguments)  
		* [Program 5.3](#program-53)  
		* [Modular Versions](#modular-versions)  



# UNIT V FILE PROCESSING  

*Files – Types of file processing: Sequential access, Random access – Sequential access file - Example Program: Finding average of numbers stored in sequential access file - Random access file - Example Program: Transaction processing using random access files – Command line arguments*


## Files

Storage of data in variables and arrays is temporary—such data is lost when a program terminates. Files are used for permanent retention of data. Computers store files on secondary storage devices, such as hard drives, CDs, DVDs and flash drives. In this chapter, we explain how data files are created, updated and processed by C programs. We consider both sequential-access and random-access file processing.

### Files and Streams
C views each file simply as a sequential stream of bytes (Fig. 11.1). Each file ends either
with an end-of-file marker or at a specific byte number recorded in a system-maintained,
administrative data structure. When a file is opened, a stream is associated with it. Three
files and their associated streams are automatically opened when program execution begins—the standard input, the standard output and the standard error. Streams provide
communication channels between files and programs. For example, the standard input
stream enables a program to read data from the keyboard, and the standard output stream enables a program to print data on the screen. Opening a file returns a pointer to a FILE structure (defined in `<stdio.h>`) that contains information used to process the file. In some operating systems, this structure includes a file descriptor, i.e., an index into an operating system array called the open file table. Each array element contains a file control block (FCB)—information that the operating system uses to administer a particular file. 

The standard input, standard output and standard error are manipulated using file pointers stdin, stdout and stderr. 


The standard library provides many functions for reading data from files and for

writing data to files. Function fgetc, like getchar, reads one character from a file. Function fgetc receives as an argument a FILE pointer for the file from which a character will be read. The call fgetc( stdin ) reads one character from stdin—the standard input.
This call is equivalent to the call getchar().

Function fputc, like putchar, writes one character to a file. Function fputc receives
as arguments a character to be written and a pointer for the file to which the character will be written. The function call fputc( 'a', stdout ) writes the character 'a' to stdout—
the standard output. This call is equivalent to putchar( 'a' ).

Several other functions used to read data from standard input and write data to standard
output have similarly named file-processing functions. The fgets and fputs functions,
for example, can be used to read a line from a file and write a line to a file, respectively.
In the next several sections, we introduce the file-processing equivalents of functions scanf and printf— fscanf and fprintf. Later in the chapter we discuss functions fread and
fwrite.

### Types of file processing 

Every open fi le has an associated fi le position indicator,
which describes where read and write operations take
place in the fi le. The position is always specifi ed in bytes
from the beginning of the fi le. When a new fi le is opened,
the position indicator is always at the beginning of the
fi le, i.e., at position 0. Because the fi le is new and has a
length of 0, there is no other location to indicate. When
an existing fi le is opened, the position indicator is at the
end of the fi le if the fi le was opened in the append mode,
or at the beginning of the fi le if the fi le was opened in any
other mode.
 The fi le input/output functions covered earlier in this
chapter make use of the position indicator, although the
manipulations go on behind the scenes. Writing and
reading operations occur at the location of the position
indicator and update the position indicator as well. Thus,
if one wishes to read all the data in a fi le sequentially or
write data to a fi le sequentially, it is not necessary to be
concerned about the position indicator because the stream
I/O functions take care of it automatically.
 When more control is required, the C library functions
that help determine and change the value of the fi le position
indicator, have to be used. By controlling the position
indicator, random access of a fi le can be made possible.
Here, random means that data can be read from, or written
to, any position in a fi le without reading or writing all the
preceding data. 

## Creating a Sequential Access file

C imposes no structure on a file. Thus, notions such as a record of a file do not exist as part of the C language. The following example shows how you can impose your own record structure on a file.

Figure 11.2 creates a simple sequential-access file that might be used in an accounts
receivable system to keep track of the amounts owed by a company’s credit clients. For
each client, the program obtains an account number, the client’s name and the client’s balance (i.e., the amount the client owes the company for goods and services received in the past). The data obtained for each client constitutes a “record” for that client. The account number is used as the record key in this application—the file will be created and maintained in account-number order. This program assumes the user enters the records in accountnumber order. In a comprehensive accounts receivable system, a sorting capability would be provided so the user could enter the records in any order. The records would then be sorted and written to the file. [Note: Figures 11.6–11.7 use the data file created in 

Fig. 11.2, so you must run Fig. 11.2 before Figs. 11.6–11.7.] 

	Enter the account, name, and balance.
	Enter EOF to end input.
	? 100 Jones 24.98
	? 200 Doe 345.67
	? 300 White 0.00
	? 400 Stone -42.16
	? 500 Rich 224.62
	? ^Z

Now let’s examine this program. Line 11 states that `cfPtr` is a pointer to a FILE structure. A C program administers each file with a separate FILE structure. You need not know the specifics of the FILE structure to use files, but you can study the declaration in **stdio.h** if you like. We’ll soon see precisely how the FILE structure leads indirectly to the operating system’s file control block (FCB) for a file.

Each open file must have a separately declared pointer of type FILE that’s used to refer
to the file. Line 14 names the file—"clients.dat"—to be used by the program and establishes a “line of communication” with the file. The file pointer cfPtr is assigned a pointer to the FILE structure for the file opened with fopen. Function fopen takes two arguments: a **filename** (which can include path information leading to the file’s location) and a **file open mode**. 

The file open mode "w" indicates that the file is to be opened for writing. If a file does not exist and it’s opened for writing, fopen creates the file. If an existing file is opened for writing, the contents of the file are discarded without warning. In the program, the if statement is used to determine whether the file pointer cfPtr is NULL (i.e., the file is not opened). If it’s NULL, the program prints an error message and terminates. Otherwise, the program processes the input and writes it to the file. 

The program prompts the user to enter the various fields for each record or to enter
end-of-file when data entry is complete. Figure 11.3 lists the key combinations for entering end-of-file for various computer systems. 

	Operating system       Key combination
	Linux/Mac OS X/UNIX    <Ctrl> d
	Windows                <Ctrl> z

Line 24 uses function feof to determine whether the end-of-file indicator is set for
the file to which stdin refers. The end-of-file indicator informs the program that there’s no
more data to be processed. In Fig. 11.2, the end-of-file indicator is set for the standard
input when the user enters the end-of-file key combination. The argument to function feof
is a pointer to the file being tested for the end-of-file indicator (stdin in this case). The
function returns a nonzero (true) value when the end-of-file indicator has been set; otherwise, the function returns zero. The while statement that includes the feof call in this program continues executing while the end-of-file indicator is not set.
Line 25 writes data to the file clients.dat. The data may be retrieved later by a program
designed to read the file (see Section 11.4). Function fprintf is equivalent to
printf except that fprintf also receives as an argument a file pointer for the file to which
the data will be written. Function fprintf can output data to the standard output by
using stdout as the file pointer, as in:

	`fprintf( stdout, "%d %s %.2f\n", account, name, balance );`

After the user enters end-of-file, the program closes the clients.dat file with fclose
and terminates. Function fclose also receives the file pointer (rather than the filename)
as an argument. If function fclose is not called explicitly, the operating system normally will close the file when program execution terminates. This is an example of operating system “housekeeping.” 

In the sample execution for the program of Fig. 11.2, the user enters information for
five accounts, then enters end-of-file to signal that data entry is complete. The sample execution does not show how the data records actually appear in the file. To verify that the file has been created successfully, in the next section we present a program that reads the file and prints its contents.

Figure 11.4 illustrates the relationship between FILE pointers, FILE structures and
FCBs. When the file "clients.dat" is opened, an FCB for the file is copied into memory.
The figure shows the connection between the file pointer returned by fopen and the FCB
used by the operating system to administer the file.

Programs may process no files, one file or several files. Each file used in a program will
have a different file pointer returned by fopen. All subsequent file-processing functions after the file is opened must refer to the file with the appropriate file pointer. Files may be opened in one of several modes (Fig. 11.5). To create a file, or to discard the contents of a file before writing data, open the file for writing ("w"). To read an existing file, open it for reading ("r"). To add records to the end of an existing file, open the file for appending ("a"). To open a file so that it may be written to and read from, open the file for updating in one of the three update modes—"r+", "w+" or "a+". Mode "r+" opens an existing file for reading and writing. Mode "w+" creates a file for reading and writing. If the file already exists, it’s opened and its current contents are discarded. Mode "a+" opens a file for reading and writing—all writing is done at the end of the file. If the file does not exist, it’s created. Each file open mode has a corresponding binary mode (containing the letter b) for manipulating binary files. The binary modes are used in Sections 11.5–11.9 when we introduce random-access files. In addition, C11 provides exclusive write mode, which you indicate by adding an x to the end of the w, w+, wb or wb+ modes. In exclusive write mode, fopen will fail if the file already exists or cannot be created. If opening a file in exclusive write mode is successful and the underlying system supports exclusive file access, then only your program can access the file while it’s open. (Some compilers and platforms do not support exclusive write mode.) If an error occurs while opening a file in any mode, fopen returns NULL. 


|Mode 	| Description |
|:-------	|:--------------|
|r			| Open an existing file for reading. |
|w		| Create a file for writing. If the file already exists, discard the current contents.
|a 		| Append: open or create a file for writing at the end of the file.
|r+		| Open an existing file for update (reading and writing).
|w+		| Create a file for update. If the file already exists, discard the current contents.
|a+		| Append: open or create a file for update; writing is done at the end of the file.

|Mode 	| Description |
|:-------	|:--------------|
|rb		| Open an existing file for reading in binary mode.
|wb		| Create a file for writing in binary mode. If the file already exists, discard the current contents.
|ab		| Append: open or create a file for writing at the end of the file in binary mode.
|rb+ 		| Open an existing file for update (reading and writing) in binary mode.
|wb+	| Create a file for update in binary mode. If the file already exists, discard the current contents.
|ab+		| Append: open or create a file for update in binary mode; writing is done at the end of the file

### Reading Sequential Access file

Data is stored in files so that the data can be retrieved for processing when needed. The
previous section demonstrated how to create a file for sequential access. This section shows
how to read data sequentially from a file.
Figure 11.6 reads records from the file "clients.dat" created by the program of
Fig. 11.2 and prints their contents. Line 11 indicates that cfPtr is a pointer to a FILE. Line
14 attempts to open the file "clients.dat" for reading ("r") and determines whether it
opened successfully (i.e., fopen does not return NULL). Line 19 reads a “record” from the
file. Function fscanf is equivalent to function scanf, except fscanf receives as an argument
a file pointer for the file from which the data is read. After this statement executes
the first time, account will have the value 100, name will have the value "Jones" and balance
will have the value 24.98. Each time the second fscanf statement (line 24) executes,
the program reads another record from the file and account, name and balance take on
new values. When the program reaches the end of the file, the file is closed (line 27) and
the program terminates. Function feof returns true only after the program attempts to
read the nonexistent data following the last line. 

Resetting the File Position Pointer
To retrieve data sequentially from a file, a program normally starts reading from the beginning
of the file and reads all data consecutively until the desired data is found. It may
be desirable to process the data sequentially in a file several times (from the beginning of
the file) during the execution of a program. The statement
causes a program’s file position pointer—which indicates the number of the next byte in
the file to be read or written—to be repositioned to the beginning of the file (i.e., byte 0)
pointed to by cfPtr. The file position pointer is not really a pointer. Rather it’s an integer
value that specifies the byte in the file at which the next read or write is to occur. This is
sometimes referred to as the file offset. The file position pointer is a member of the FILE
structure associated with each file.
Credit Inquiry Program
The program of Fig. 11.7 allows a credit manager to obtain lists of customers with zero
balances (i.e., customers who do not owe any money), customers with credit balances (i.e.,
customers to whom the company owes money) and customers with debit balances (i.e.,
customers who owe the company money for goods and services received). A credit balance
is a negative amount; a debit balance is a positive amount

The program displays a menu and allows the credit manager to enter one of three
options to obtain credit information. Option 1 produces a list of accounts with zero balances.
Option 2 produces a list of accounts with credit balances. Option 3 produces a list
of accounts with debit balances. Option 4 terminates program execution. A sample output
is shown in Fig. 11.8.

	Enter request
	 1 - List accounts with zero balances
	 2 - List accounts with credit balances
	 3 - List accounts with debit balances
	 4 - End of run
	? 1

	Accounts with zero balances:
	300 White 0.00
	? 2
	Accounts with credit balances:
	400 Stone -42.16
	? 3
	Accounts with debit balances:
	100 Jones 24.98
	200 Doe 345.67
	500 Rich 224.62
	? 4
	End of run.

Data in this type of sequential file cannot be modified without the risk of destroying
other data. For example, if the name “White” needs to be changed to “Worthington,” the
old name cannot simply be overwritten. The record for White was written to the file as
If the record is rewritten beginning at the same location in the file using the new name,
the record will be
The new record is larger (has more characters) than the original record. The characters beyond
the second “o” in “Worthington” will overwrite the beginning of the next sequential
record in the file. The problem here is that in the formatted input/output model using
fprintf and fscanf, fields—and hence records—can vary in size. For example, the values
7, 14, –117, 2074 and 27383 are all ints stored in the same number of bytes internally,
but they’re different-sized fields when displayed on the screen or written to a file as text.
Therefore, sequential access with fprintf and fscanf is not usually used to update
records in place. Instead, the entire file is usually rewritten. To make the preceding name
change, the records before 300 White 0.00 in such a sequential-access file would be copied
to a new file, the new record would be written and the records after 300 White 0.00 would
be copied to the new file. This requires processing every record in the file to update one
record. 

The next program reads five integer values from the keyboard and stores them in the data file `num.dat`. In this program the user-defined character is used, as end-of-file marker instead of standard `EOF`.

```c
#include <stdio.h>
int main() {
	FILE* fp;
    int n[5], i;
    if ((fp = fopen("num.dat", "w")) != NULL) {
        puts("Enter 5 numbers, to be stored in num.dat...");
        for (i = 0; i < 5; i++) {
            scanf("%d", &n[i]);
            fprintf(fp, "%d\n", n[i]);
        }
        fprintf(fp,"%d", 9999);
        fclose(fp);
    }
    else
        printf("Unable to open num.dat...\n"); }
```
 
**Output:**

	Enter 5 numbers, to be stored in num.dat ... 1 2 3 4 5

The file num.dat now contains the numbers arranged in the following format.

	1
	2
	3
	4
	5
	9999
 
Here 9999 is used as end-of-file marker. It is not a member of the data set. While reading data from ‘num.dat’, the data is read until 9999 is found. The following program describes the usage where the numbers stored in the file ‘num.dat’ are summed up and displayed. Here fscanf() has to be used to read data from the file.

```c
#include <stdio.h>
int main(){
	FILE *fp;
	int n,s=0;
	if((fp = fopen(“num.dat”, “r”)) != NULL){
		fscanf(fp, “%d\n”, &n);
		while(n!=9999){ 
			s+=n;
			fscanf(fp, “%d\n”, &n);
		}
		printf(“Sum is %d”,s);
		fclose(fp);
	} 
	else
		printf(“Unable to open num.dat ... \n”);
	 return 0;
 }

```

**Output:**

	Sum is 15

fscanf() is a fi eld-oriented function and is inappropriate for use in a robust, general-purpose text fi le reader. It has two major drawbacks.

  - The programmer must know the exact data layout of the input fi le in advance and rewrite the function call for every different layout
  - It is difficult to read text strings that contain spaces because fscanf() sees space characters as field delimiters.

Now one might think that calls to fprinf() and fscanf() differ signifi cantly from calls to printf() and scanf(), and that these latter functions do not seem to require file pointers. 


```c
 #include <stdlib.h>
 #include <stdio.h>
 #define SIZE 100
 
int main() {
	char temp[SIZE];
	char fname[60];
	FILE *fp;
	printf(“Enter name of fi lename:”);
	fflush(stdin);
	scanf(“%s”, fname);
	if((fp = fopen(fname, “r”)) == NULL){
		 fprintf(stderr, “Error in opening fi le”);
		 exit(1);
	}
	while(!feof(fp)){
		 fgets(temp, SIZE, fp);
		 printf(“%s”,temp);
	}
	fclose(fp);
	return 0;
}
```

### Read numbers from file and calculate Average


#### Example Program: Average of numbers

Write a program to calculate the average of first n numbers.

This is the simplest version of calculating averages of a bunch of numbers. 

```c

#include <stdio.h>
int main(){
	int n, i = 0, sum =0;
	float avg = 0.0;
	printf("\n Enter the value of n : ");
	scanf("%d", &n);
	do{
		sum = sum + i;
		i = i + 1;
	} while(i<=n);
	avg = (float)sum/n;
	printf("\n The sum of first %d numbers = %d",n, sum);
	printf("\n The average of first %d numbers = %.2f", n, avg);
	return 0;
}
```

**Output**
	
	Enter the value of n : 20
	The sum of first 20 numbers = 210
	The average of first 20 numbers = 10.05


#### Example Program: Average of numbers read from a file

The next program reads five (or more) integer values from the data file `num.dat`. In this program end-of-file marker `EOF` is used to exit the loop.

```c

int main()
{
	FILE* fp;
	int n[50], i = 0;
	float sum = 0;
	if ((fp = fopen("num.dat", "r")) != NULL) {
	    puts("Reading numbers from num.dat");
	    while (!feof(fp)) {
	        fscanf(fp, "%d ", &n[i]);
	        printf("%d %d\n", i, n[i]);
	        sum += n[i];
	        i++;
	    }
	    fclose(fp);
	
	    if (i > 0) {
	        float average = sum / i;
	        printf("The average is %f for %d numbers\n",
	            average, i);
	    }
	    else {
	        puts("No data available in num.dat!");
	    }
	}
	else
	    printf("Unable to open num.dat...\n");
}

```

## Random access file 

As we stated previously, records in a file created with the formatted output function
fprintf are not necessarily the same length. However, individual records of a randomaccess
file are normally fixed in length and may be accessed directly (and thus quickly)
without searching through other records. This makes random-access files appropriate for
airline reservation systems, banking systems, point-of-sale systems, and other kinds of
transaction-processing systems that require rapid access to specific data. There are other ways of implementing random-access files, but we’ll limit our discussion to this straightforward approach using fixed-length records.

  - Because every record in a random-access file normally has the same length, the exact
location of a record relative to the beginning of the file can be calculated as a function of the record key. We’ll soon see how this facilitates immediate access to specific records, even in large files.
  - Figure below illustrates one way to implement a random-access file. Such a file is like a freight train with many cars—some empty and some with cargo. Each car in the train has the same length.

< FIGURE REQUIRED FROM BOOK>


Fixed-length records enable data to be inserted in a random-access file without
destroying other data in the file. Data stored previously can also be updated or deleted
without rewriting the entire file. In the following sections we explain how to create a
random-access file, enter data, read the data both sequentially and randomly, update the
data, and delete data no longer needed. 


### Creating Random Access File

Function fwrite transfers a specified number of bytes beginning at a specified location in
memory to a file. The data is written beginning at the location in the file indicated by the
file position pointer. Function fread transfers a specified number of bytes from the location
in the file specified by the file position pointer to an area in memory beginning with
a specified address. Now, when writing an integer, instead of using
which could print a single digit or as many as 11 digits (10 digits plus a sign, each of which
requires 1 byte of storage) for a four-byte integer, we can use
which always writes four bytes on a system with four-byte integers from a variable number
to the file represented by fPtr (we’ll explain the 1 argument shortly). Later, fread can be
used to read those four bytes into an integer variable number. Although fread and fwrite
read and write data, such as integers, in fixed-size rather than variable-size format, the data
they handle are processed in computer “raw data” format (i.e., bytes of data) rather than
in printf’s and scanf’s human-readable text format. Because the “raw” representation of

data is system dependent, “raw data” may not be readable on other systems, or by programs
produced by other compilers or with other compiler options.
Functions fwrite and fread are capable of reading and writing arrays of data to and
from disk. The third argument of both fread and fwrite is the number of elements in the
array that should be read from or written to disk. The preceding fwrite function call
writes a single integer to disk, so the third argument is 1 (as if one element of an array is
being written).
File-processing programs rarely write a single field to a file. Normally, they write one
struct at a time, as we show in the following examples.
Consider the following problem statement:

	Create a credit-processing system capable of storing up to 100 fixed-length records. Each record should consist of an account number that will be used as the record key, a last name, a first name and a balance. The resulting program should be able to update an account, insert a new account record, delete an account and list all the account	records in a formatted text file for printing. Use a random-access file.

The next several sections introduce the techniques necessary to create the credit-processing program. Figure 11.10 shows how to open a random-access file, define a record format using a struct, write data to the disk and close the file. This program initializes all 100 records of the file "credit.dat" with empty structs using the function fwrite. Each empty struct contains 0 for the account number, "" (the empty string) for the last name, "" for the first name and 0.0 for the balance. The file is initialized in this manner to create space on disk in which the file will be stored and to make it possible to determine whether a record contains data.

```c

// Fig. 11.10: fig11_10.c
// Creating a random-access file sequentially
#include <stdio.h>

// clientData structure definition            
struct clientData {                              
   unsigned int acctNum; // account number
   char lastName[ 15 ]; // account last name    
   char firstName[ 10 ]; // account first name   
   double balance; // account balance      
}; // end structure clientData                

int main( void )
{ 
   unsigned int i; // counter used to count from 1-100

   // create clientData with default information       
   struct clientData blankClient = { 0, "", "", 0.0 }; 
   
   FILE *cfPtr; // credit.dat file pointer

   // fopen opens the file; exits if file cannot be opened
   if ( ( cfPtr = fopen( "credit.dat", "wb" ) ) == NULL ) {
      puts( "File could not be opened." );
   } // end if
   else { 
      // output 100 blank records to file                              
      for ( i = 1; i <= 100; ++i ) {                                   
         fwrite( &blankClient, sizeof( struct clientData ), 1, cfPtr );
      } // end for                                                     

      fclose ( cfPtr ); // fclose closes the file
   } // end else
} // end main

```

Function fwrite writes a block of bytes to a file. Line 29 causes the structure blankClient
of size sizeof(struct clientData) to be written to the file pointed to by cfPtr.
The operator sizeof returns the size in bytes of its operand in parentheses (in this case
struct clientData). Function fwrite can actually be used to write several elements of an array of objects. To do so, supply in the call to fwrite a pointer to an array as the first argument and the number of elements to be written as the third argument. In the preceding statement, fwrite was used to write a single object that was not an array element. Writing a single object is equivalent to writing one element of an array, hence the 1 in the fwrite call. [Note: Figures 11.11, 11.14 and 11.15 use the data file created in Fig. 11.10, so you must run Fig. 11.10 before Figs. 11.11, 11.14 and 11.15]. 

### Writing Data

Figure 11.11 writes data to the file "credit.dat". It uses the combination of fseek and
fwrite to store data at specific locations in the file. Function fseek sets the file position
pointer to a specific position in the file, then fwrite writes the data. A sample execution
is shown in Fig. 11.12.

Lines 40–41 position the file position pointer for the file referenced by cfPtr to the
byte location calculated by `(client.accountNum - 1) * sizeof(struct clientData)`.

The value of this expression is called the offset or the displacement. Because the account number is between 1 and 100 but the byte positions in the file start with 0, 1 is subtracted from the account number when calculating the byte location of the record. Thus, for record 1, the file position pointer is set to byte 0 of the file. The symbolic constant SEEK_SET indicates that the file position pointer is positioned relative to the beginning of the file by the amount of the offset. As the above statement indicates, a seek for account number 1 in the file sets the file position pointer to the beginning of the file because the byte location calculated is 0. Figure 11.13 illustrates the file pointer referring to a FILE structure in memory. The file position pointer in this diagram indicates that the next byte to be read or written is 5 bytes from the beginning of the file.

The function prototype for fseek is
where offset is the number of bytes to seek from whence in the file pointed to by
stream—a positive offset seeks forward and a negative one seeks backward. Argument
whence is one of the values SEEK\_SET, SEEK\_CUR or SEEK\_END (all defined in <stdio.h>), which indicate the location from which the seek begins. SEEK\_SET *indicates that the seek starts at the beginning of the file*; SEEK\_CUR indicates that the seek starts at the current location in the file; and SEEK_END indicates that the seek starts at the end of the file. 

For simplicity, the programs in this chapter do not perform error checking. Industrial strength programs should determine whether functions such as fscanf (lines 36–37), fseek (lines 40–41) and fwrite (line 44) operate correctly by checking their return values. Function fscanf returns the number of data items successfully read or the value EOF if a problem occurs while reading data. Function fseek returns a nonzero value if the seek operation cannot be performed. Function fwrite returns the number of items it successfully output. If this number is less than the third argument in the function call, then a write error occurred.


### Reading Data 


Function fread reads a specified number of bytes from a file into memory. For example,

`fread( &client, sizeof( struct clientData ), 1, cfPtr );`

reads the number of bytes determined by sizeof(struct clientData) from the file referenced by **cfPtr**, stores the data in client and returns the number of bytes read. The bytes are read from the location specified by the file position pointer. Function fread can read several fixed-size array elements by providing a pointer to the array in which the elements will be stored and by indicating the number of elements to be read. The preceding statement reads one element. 

To read more than one, specify the number of elements as fread’s third argument. Function fread returns the number of items it successfully input. If this number is less than the third argument in the function call, then a read error occurred.

Figure 11.14 reads sequentially every record in the "credit.dat" file, determines
whether each record contains data and displays the formatted data for records containing data. Function feof determines when the end of the file is reached, and the fread function transfers data from the file to the clientData structure client. 

```c

// Fig. 11.14: fig11_14.c
// Reading a random-access file sequentially
#include <stdio.h>

// clientData structure definition               
struct clientData {                              
   unsigned int acctNum; // account number     
   char lastName[ 15 ]; // account last name     
   char firstName[ 10 ]; // account first name   
   double balance; // account balance            
}; // end structure clientData                   

int main( void )
{ 
   FILE *cfPtr; // credit.dat file pointer
   int result; // used to test whether fread read any bytes

   // create clientData with default information
   struct clientData client = { 0, "", "", 0.0 };

   // fopen opens the file; exits if file cannot be opened
   if ( ( cfPtr = fopen( "credit.dat", "rb" ) ) == NULL ) {
      puts( "File could not be opened." );
   } // end if
   else { 
      printf( "%-6s%-16s%-11s%10s\n", "Acct", "Last Name",
         "First Name", "Balance" );

      // read all records from file (until eof)
      while ( !feof( cfPtr ) ) { 
         result = fread( &client, sizeof( struct clientData ), 1, cfPtr );

         // display record
         if ( result != 0 && client.acctNum != 0 ) {
            printf( "%-6d%-16s%-11s%10.2f\n", 
               client.acctNum, client.lastName, 
               client.firstName, client.balance );
         } // end if
      } // end while

      fclose( cfPtr ); // fclose closes the file
   } // end else
} // end main

```

	Acct Last Name First Name Balance
	  29 Brown     Nancy      -24.54
	  33 Dunn      Stacey     314.33
	  37 Barker    Doug         0.00
	  88 Smith     Dave       258.34
	  96 Stone     Sam         34.98
	
**Fig. 11.14 | Reading a random-access file sequentially. (Part 2 of 2.)**


### Transaction processing using random access files 


We now present a substantial transaction-processing program using **random access** files. The program maintains a bank’s account information—updating existing accounts, adding new accounts, deleting accounts and storing a listing of all the current accounts in a text file for printing. We assume that the program of Fig. 11.10 has been executed to create the file **credit.dat**.

The program has five options. 
  
**Option 1** calls function textFile (lines 63–94) to store a formatted list of all the accounts (typically called a report) in a text file called accounts.txt that may be printed later. The function uses fread and the sequential file access techniques used in the program of Section below. 

After **option 1** is chosen, the file **accounts.txt** contains:

	Acct Last Name First Name Balance
		29   Brown     Nancy        -24.54
		33   Dunn      Stacey       314.33
		37   Barker    Doug           0.00
		88   Smith     Dave         258.34
		96   Stone     Sam           34.98

**Option 2** calls the function **updateRecord** (lines 97–141) to update an account. The function will update only a record that already exists, so the function first checks whether the record specified by the user is empty. The record is read into structure client with fread, then member acctNum is compared to 0. If it’s 0, the record contains no information, and a message is printed stating that the record is empty. Then the menu choices are displayed. If the record contains information, function updateRecord inputs the transaction amount, calculates the new balance and rewrites the record to the file. A typical output for option 2 is

	Enter account to update ( 1 - 100 ): 37
	37 Barker Doug 0.00
	Enter charge ( + ) or payment ( - ): +87.99
	37 Barker Do


**Option 3** calls the function newRecord to add a new account to the file. If the user enters an account number for an existing account, newRecord displays an error message indicating that the record already contains information, and the menu choices are printed again. This function uses the same process to add a new account as does the program in Fig. 11.11. A typical output for option 3 is

	Enter new account number ( 1 - 100 ): 22
	Enter lastname, firstname, balance
	? Johnston Sarah 247.45

**Option 4** calls function deleteRecord to delete a record from the file. Deletion is accomplished by asking the user for the account number and reinitializing the record. If the account contains no information, deleteRecord displays an error message indicating that the account does not exist. 

**Option 5** terminates program execution. The program is shown in Fig. 11.15. The file "credit.dat" is opened for update (reading and writing) using "rb+" mode.  

```c

// Bank-account program reads a random-access file sequentially, 
// updates data already written to the file, creates new data to 
// be placed in the file, and deletes data previously in the file.
#include <stdio.h>

// clientData structure definition               
struct clientData {                              
   unsigned int acctNum; // account number
   char lastName[ 15 ]; // account last name     
   char firstName[ 10 ]; // account first name   
   double balance; // account balance            
}; // end structure clientData                   

// prototypes
unsigned int enterChoice( void );
void textFile( FILE *readPtr );
void updateRecord( FILE *fPtr );
void newRecord( FILE *fPtr );
void deleteRecord( FILE *fPtr );

int main( void )
{ 
   FILE *cfPtr; // credit.dat file pointer
   unsigned int choice; // user's choice

   // fopen opens the file; exits if file cannot be opened
   if ( ( cfPtr = fopen( "credit.dat", "rb+" ) ) == NULL ) {
      puts( "File could not be opened." );
   } // end if
   else { 
      // enable user to specify action
      while ( ( choice = enterChoice() ) != 5 ) { 
         switch ( choice ) { 
            // create text file from record file
            case 1:
               textFile( cfPtr );
               break;
            // update record
            case 2:
               updateRecord( cfPtr );
               break;
            // create record
            case 3:
               newRecord( cfPtr );
               break;
            // delete existing record
            case 4:
               deleteRecord( cfPtr );
               break;
            // display message if user does not select valid choice
            default:
               puts( "Incorrect choice" );
               break;
         } // end switch
      } // end while

      fclose( cfPtr ); // fclose closes the file
   } // end else
} // end main

// create formatted text file for printing 
void textFile( FILE *readPtr )
{ 
   FILE *writePtr; // accounts.txt file pointer
   int result; // used to test whether fread read any bytes

   // create clientData with default information
   struct clientData client = { 0, "", "", 0.0 };

   // fopen opens the file; exits if file cannot be opened
   if ( ( writePtr = fopen( "accounts.txt", "w" ) ) == NULL ) {
      puts( "File could not be opened." );
   } // end if
   else { 
      rewind( readPtr ); // sets pointer to beginning of file
      fprintf( writePtr, "%-6s%-16s%-11s%10s\n", 
         "Acct", "Last Name", "First Name","Balance" );

      // copy all records from random-access file into text file
      while ( !feof( readPtr ) ) { 
         result = fread(&client, sizeof( struct clientData ), 1, readPtr);

         // write single record to text file
         if ( result != 0 && client.acctNum != 0 ) {
            fprintf( writePtr, "%-6d%-16s%-11s%10.2f\n",
               client.acctNum, client.lastName,         
               client.firstName, client.balance );      
         } // end if
      } // end while

      fclose( writePtr ); // fclose closes the file
   } // end else
} // end function textFile

// update balance in record
void updateRecord( FILE *fPtr )

{ 
   unsigned int account; // account number
   double transaction; // transaction amount

   // create clientData with no information
   struct clientData client = { 0, "", "", 0.0 };

   // obtain number of account to update
   printf( "%s", "Enter account to update ( 1 - 100 ): " );
   scanf( "%d", &account );

   // move file pointer to correct record in file              
   fseek( fPtr, ( account - 1 ) * sizeof( struct clientData ), 
      SEEK_SET );                                              

   // read record from file
   fread( &client, sizeof( struct clientData ), 1, fPtr );

   // display error if account does not exist
   if ( client.acctNum == 0 ) {
      printf( "Account #%d has no information.\n", account );
   } // end if
   else { // update record
      printf( "%-6d%-16s%-11s%10.2f\n\n", 
         client.acctNum, client.lastName, 
         client.firstName, client.balance );
      
      // request transaction amount from user 
      printf( "%s", "Enter charge ( + ) or payment ( - ): " );
      scanf( "%lf", &transaction );
      client.balance += transaction; // update record balance
      
      printf( "%-6d%-16s%-11s%10.2f\n", 
         client.acctNum, client.lastName, 
         client.firstName, client.balance );
      
      // move file pointer to correct record in file              
      fseek( fPtr, ( account - 1 ) * sizeof( struct clientData ), 
         SEEK_SET );                                              

      // write updated record over old record in file         
      fwrite( &client, sizeof( struct clientData ), 1, fPtr );
   } // end else
} // end function updateRecord

// delete an existing record
void deleteRecord( FILE *fPtr )
{ 
   struct clientData client; // stores record read from file
   struct clientData blankClient = { 0, "", "", 0 }; // blank client
   
   unsigned int accountNum; // account number

   // obtain number of account to delete
   printf( "%s", "Enter account number to delete ( 1 - 100 ): " );
   scanf( "%d", &accountNum );

   // move file pointer to correct record in file                 
   fseek( fPtr, ( accountNum - 1 ) * sizeof( struct clientData ), 
      SEEK_SET );                                                 

   // read record from file                               
   fread( &client, sizeof( struct clientData ), 1, fPtr );

   // display error if record does not exist
   if ( client.acctNum == 0 ) {
      printf( "Account %d does not exist.\n", accountNum );
   } // end if
   else { // delete record
      // move file pointer to correct record in file                 
      fseek( fPtr, ( accountNum - 1 ) * sizeof( struct clientData ), 
         SEEK_SET );                                                 

      // replace existing record with blank record   
      fwrite( &blankClient,                          
         sizeof( struct clientData ), 1, fPtr );     
   } // end else
} // end function deleteRecord

// create and insert record
void newRecord( FILE *fPtr )
{ 
   // create clientData with default information
   struct clientData client = { 0, "", "", 0.0 };

   unsigned int accountNum; // account number

   // obtain number of account to create
   printf( "%s", "Enter new account number ( 1 - 100 ): " );
   scanf( "%d", &accountNum );

   // move file pointer to correct record in file                 
   fseek( fPtr, ( accountNum - 1 ) * sizeof( struct clientData ), 
      SEEK_SET );                                                 

   // read record from file                               
   fread( &client, sizeof( struct clientData ), 1, fPtr );

   // display error if account already exists
   if ( client.acctNum != 0 ) {
      printf( "Account #%d already contains information.\n",
         client.acctNum );
   } // end if
   else { // create record
      // user enters last name, first name and balance
      printf( "%s", "Enter lastname, firstname, balance\n? " );
      scanf( "%14s%9s%lf", &client.lastName, &client.firstName, 
         &client.balance );

      client.acctNum = accountNum;
      
      // move file pointer to correct record in file   
      fseek( fPtr, ( client.acctNum - 1 ) *            
         sizeof( struct clientData ), SEEK_SET );      

      // insert record in file                       
      fwrite( &client,                               
         sizeof( struct clientData ), 1, fPtr );     
   } // end else
} // end function newRecord

// enable user to input menu choice
unsigned int enterChoice( void )
{ 
   unsigned int menuChoice; // variable to store user's choice

   // display available options
   printf( "%s", "\nEnter your choice\n"
      "1 - store a formatted text file of accounts called\n"
      "    \"accounts.txt\" for printing\n"
      "2 - update an account\n"
      "3 - add a new account\n"
      "4 - delete an account\n"
      "5 - end program\n? " );

   scanf( "%u", &menuChoice ); // receive choice from user
   return menuChoice;
} // end function enterChoice

```

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

### Program 5.3

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


### Modular Versions

Fork [this](http://cyberdojo1.kgfsl.com/forker/fork/6EA156F740?avatar=hyena&tag=-1)!


```c

int read_from_stream_into_array(
    const char* fname,  // to use in logging if there is an error
    FILE* fp,           // can also be assigned to stdin
    int array[])        // array to be filled with values
{
    int counter = 0;
    if (fp != NULL) {
        printf("Reading numbers from %s\n", fname);
        while (!feof(fp)) {
            fscanf(fp, "%d ", &array[counter]);
            printf("%d %d\n", counter, array[counter]);
            counter++;
        }
        fclose(fp);
    }
    else
        printf("Invalid file pointer for file:%s!", fname);

    return counter;
}

float calculate_sum(int *n, int i) {
    float sum = 0; 
    for (int counter = 0; counter < i; counter++){
        sum = sum  + n[i];
    }
    return sum; 
}


int main(int argc, char* argv[]) 
{
    int n[50];
    
    FILE *fp = fopen("num.dat", "r");
    int i    = read_from_stream_into_array("num.dat", fp, n);
    
    if (i > 0) {
        float sum     = calculate_sum(n, i); 
        float average = sum / i;
        printf("The average is %f for %d numbers\n",
               average, i);
    }
    else {
        puts("No data available in num.dat!");
    }
}
```
