
![cloud](http://bit.ly/unit5Words)

# UNIT V FILE PROCESSING  
*Files – Types of file processing: Sequential access, Random access – Sequential access file - Example Program: Finding average of numbers stored in sequential access file - Random access file - Example Program: Transaction processing using random access files – Command line arguments*

http://j.mp/memUnit5  -50 flashcards to review the contents of this unit.
http://j.mp/replUnit5 - list of illustrative C programs provided in this unit.

**Table of Contents**

* [UNIT V FILE PROCESSING](#unit-v-file-processing)  
	* [Key Terms](#key-terms)  
	* [File Handling in C Language - Quick Reference](#file-handling-in-c-language---quick-reference)  
	* [Files](#files)  
		* [File Extensions](#file-extensions)  
		* [Text File Characteristics](#text-file-characteristics)  
		* [Binary File Characteristics](#binary-file-characteristics)  
		* [Files and Streams](#files-and-streams)  
		* [Types of file processing](#types-of-file-processing)  
	* [Creating a Sequential Access file](#creating-a-sequential-access-file)  
		* [File Access Modes](#file-access-modes)  
		* [Reading Sequential Access file](#reading-sequential-access-file)  
		* [Read numbers from file and calculate Average](#read-numbers-from-file-and-calculate-average)  
	* [Random access file](#random-access-file)  
		* [Creating Random Access File](#creating-random-access-file)  
		* [Writing Random Access Data](#writing-random-access-data)  
			* [Return values](#return-values)  
		* [Reading Random Access Data](#reading-random-access-data)  
		* [Transaction processing using random access files](#transaction-processing-using-random-access-files)  
	* [Command line arguments](#command-line-arguments)  
		* [Simple example](#simple-example)  
		* [Program 5.3](#program-53)  
	* [FAQ](#faq)  
	* [Bonus Material](#bonus-material)  

### Online References attribution

- Understand [file functions][1] 
- Quick reference on [file handling][2]
- All about [EOF](https://latedev.wordpress.com/2012/12/04/all-about-eof/) 

[1]: https://www.go4expert.com/articles/understanding-c-file-handling-functions-t29966/
[2]: http://iiti.ac.in/people/~tanimad/FileHandlinginCLanguage.pdf 


## Pre-Unit exercise - a "Show and Tell" exercise

1. Create your own paper document by writing a few numbers 
and words in 3-4 lines. Do not use cursive writing, instead 
use capital letters and write as neatly as possible. Here's 
an [example](http://j.mp/numberWords). 
2. Create a digital copy of the same (what will you use to 
create a scanned copy?)
3. Look inside the digital copy and examine it using a hex 
editor 
5. Do an **OCR** of your digital copy and download a text 
version of your digital essay. Write down and share what 
you used to do an OCR on your own handwritten document.
6. Send the digital copy and the text file (created using 
your OCR effort) to your faculty's email; 
7. Create a github repository containing a digital scan of 
your document and an OCR'ed text file of your document 
8. Bring the written document to class;  Bring a print out 
of the OCR'ed text file to class
9. If you do everything as per the steps above, you should 
end up with a snapshot of a cloned repo directory similar 
to the image below: 

![ocr](https://cdn.rawgit.com/kgashok/filesOCR/1d2f5c87/directoryImage.png)

## Post-Unit exercise
<!---
- Review http://j.mp/unitMCQ1 and http://j.mp/unitMCQ2
<-->
- Ask for the MCQ1 and MCQ2 sheets 
- Read and resolve [this](https://github.com/kgisl/cs8251/blob/master/quiz/filereader.c.md) mystery.
- Try and understand Kilo project - https://github.com/kgisl/kilo
   - [writing](https://github.com/kgisl/kilo/blob/7a34f41ab091a74fe7ccc3b6fea35f1ab6fb3c5f/kilo.c#L705) to file 
   - [reading](https://github.com/kgisl/kilo/blob/7a34f41ab091a74fe7ccc3b6fea35f1ab6fb3c5f/kilo.c#L674) to file
   - Implement a `<Ctrl-O>` option that loads in a new file into the editor

# Key Terms

- **Binary file** : Binary file is a collection of bytes or a character stream. The data that is written into and read from binary file remain unchanged, with no separation between lines and no use of end-of-line characters and the interpretation of the file is left to the programmer.
- **Text file** :  A text file is a stream of characters that can be processed sequentially and logically in the forward direction. The maximum number of characters in each line is limited to 255 characters. 
- **Sequential file access**: In case of sequential file access, data is read from or written to a file in a sequential manner while the `position indicator` automatically gets adjusted by the stream I/O functions. 
- **Random file access**:  Random access means reading from or writing to any position in a file without reading or writing all the preceding data by controlling the `position indicator`
- **Record**:  A record consist of a collection of data fields that conforms  to a previously defined structure that can be stored on or retrieved from a file.
- **Stream**:  The stream is a common, logical interface to the various devices that comprise the computer and is a logical interface to a file. Although files differ in form and capabilities, all streams are the same.
- **File management**:  It basically means all operations related to creating, renaming, deleting, merging, reading, writing, etc. of any type of files.
- **Path**: The path specifies the drive and/or directory (or folder) where the file is located. On PCs, the backslash character is used to separate directory names in a path. Some systems like Unix use the forward slash (/) as the directory separator. 


# File Handling in C Language - Quick Reference

A **file** represents a sequence of bytes on the disk where a group of related data is stored. File is created for permanent storage of data. It is a readymade structure.

In C language, we use a structure **pointer of file type** to declare a file.

		FILE *fp;

C provides a number of functions that helps to perform basic file operations. Following are the functions,

|Function 	 |description    | Prototype |
|:-----------|:--------------|:--------|
| fopen()	| create a new file or open a existing file | FILE *fp =**fopen** (“filename”, ”‘mode”); |
| fclose() 	| closes a file	| int **fclose**(FILE *fp); |
| fgets()   | get a string from file | char  *fgets(  char  *str, int count, [FILE](http://en.cppreference.com/w/c/io)  *stream ); |
| getc() 	| reads a character from a file| int  getc(  [FILE](http://en.cppreference.com/w/c/io)  *stream  ); |
| putc()	| writes a character to a file| int  putc(  int  ch,  [FILE](http://en.cppreference.com/w/c/io)  *stream  ); |
| fscanf()  | reads a set of data from a file| int fscanf(  [FILE](http://en.cppreference.com/w/c/io)  *stream, const  char  *format, ... ); |
| fprintf() | writes a set of data to a file | int **fprintf**(FILE *fp, const char *format, …) |
| getw() 	| reads a integer from a file| int **getw**(FILE *fp);|
| putw() 	| writes a integer to a file| int **putw**(int w, FILE *stream);  (*deprecated, legacy*)|
| fseek() 	| set the position to desire point | int  fseek(  [FILE](http://en.cppreference.com/w/c/io)  *stream,  long  offset,  int  origin  );| 
| ftell()	| gives current position in the file | long  ftell(  [FILE](http://en.cppreference.com/w/c/io)  *stream  );|
| rewind()	| set the position to the beginning point | void  rewind(  [FILE](http://en.cppreference.com/w/c/io)  *stream  );
| fread()   | reads specific number of bytes from binary file | [size_t](http://en.cppreference.com/w/c/types/size_t) fread(  void  *buffer, [size_t](http://en.cppreference.com/w/c/types/size_t) size, [size_t](http://en.cppreference.com/w/c/types/size_t) count,  [FILE](http://en.cppreference.com/w/c/io)  *stream); |
| fwrite()	| writes specific number of bytes to binary files | [size_t](http://en.cppreference.com/w/c/types/size_t) fwrite(  const  void  *buffer, [size_t](http://en.cppreference.com/w/c/types/size_t) size, [size_t](http://en.cppreference.com/w/c/types/size_t) count,  [FILE](http://en.cppreference.com/w/c/io)  *stream);

  
   **Opening a File or Creating a File**

The `fopen()` function is used to create a new file or to open an existing file.

**General Syntax :**

FILE *fp = fopen(const char _*filename_ , const char _*mode_ );

Here **filename** is the name of the file to be opened and **mode** specifies the purpose of opening the file. Mode can be of following types,

**\*fp** is the FILE pointer (**FILE *fp** ), which will hold the reference to the opened (or created) file.

**Closing a File**

The fclose() function is used to close an already opened file.

**General Syntax :**

int **fclose** ( FILE _*fp_ );
Here fclose() function closes the file and returns **zero** on success, or **EOF** if there is an error in closing the file. This **EOF** is a constant defined in the header file **stdio.h**.

**Input/Output operation on File**

In the above table we have discussed about various file I/O functions to perform reading and writing on file. **getc**() and **putc**() are simplest functions used to read and write individual characters to a file.

```c
#include <stdio.h>
#include <conio.h>
main() {
	FILE *fp;
	char ch;
	// open a text file for writing into it
	fp = fopen ("one.txt", "w");
	printf("Enter data");
	while( (ch = getchar()) != EOF) {
		putc(ch, fp);
	}
	fclose(fp);
	// open a text file for reading from it 
	fp = fopen("one.txt", "r");
	while( (ch = getc(fp)) != EOF)
		printf("%c", ch);
	fclose(fp);
}
```

### Demo 
Run `prog11` in the http://bit.ly/replUnit5

### Sample Output 
![prog11](https://i.imgur.com/XNZ75Nr.jpg)



**Reading and Writing from File using fprintf() and fscanf()**

```c
#include<stdio.h>
#include<conio.h>
struct employee
{
	char name[10];
	int age;
};

void main(){
	struct employee e;
	FILE *p, *q;
	p = fopen("one.txt", "a");
	q = fopen("one.txt", "r");
	printf("Enter Name and Age");
	scanf("%s %d", e.name, &e.age);
	fprintf(p,"%s %d", e.name, e.age);
	fclose(p);
	do
	{
	    fscanf(q,"%s %d", e.name, &e.age);
	    printf("%s %d", e.name, e.age);
	} while(!feof(q));
	getch();
}

```

### Demo 
Run `prog12` in the http://bit.ly/replUnit5

### Sample Output 
![prog12](https://i.imgur.com/gTvEpdY.jpg)

In this program, we have create two FILE pointers and both are referring to the same file but in different modes. **fprintf()** function directly writes into the file, while **fscanf()** reads from the file, which can then be printed on console using standard **printf()** function.


**Difference between Append and Write Mode**

Write (w) mode and Append (a) mode, while opening a file are almost the same. Both are used to write in a file. In both the modes, new file is created if it doesn't exists already.

The only difference they have is, when you open a file in the write mode, the file is reset, resulting in deletion of any data already present in the file. While in append mode this will not happen. Append mode is used to append or add data to the existing data of file (if any). Hence, when you open a file in Append(a) mode, the cursor is positioned at the end of the present data in the file.

**Reading and Writing in a Binary File**

A Binary file is similar to the text file, but it contains only large numerical data. The Opening modes are mentioned in the table for opening modes above.

**fread()** and **fwrite()** functions are used to read and write is a binary file.

```c
fwrite(data_element_to_be_written, size_of_element,number_of_elements, pointer_to_file);
```

**fread()** is also used in the same way, with the same arguments like fwrite() function. Below mentioned is a simple example of writing into a binary file

```c
const char mytext = "The quick brown fox jumps over the lazy dog";
FILE *bfp = fopen("test.txt", "wb");
if (bfp) {
	fwrite(mytext , sizeof(char) , strlen(mytext) , bfp);
	fclose(bfp) ;
}
```

**fseek(), ftell() and rewind() functions**

- **fseek()** - It is used to move the reading control to different positions in file.
- **ftell()** - It tells the byte location of current position of cursor in file pointer.
- **rewind()** - It moves the control to beginning of the file.


----------

# Files

**What are files?**  A file is sequential stream of bytes ending with an end-of-file marker.

As we know, at the time of execution, every program is executed in the main memory. Main memory is volatile and the data would be lost once the program is terminated. If we need the same data again, we have to store the data in a file on the disk. A file is sequential stream of bytes ending with an end-of-file marker.

Storage of data in variables and arrays is temporary—such data is lost when a program terminates. Files are used for permanent retention of data. Computers store files on secondary storage devices, such as hard drives, CDs, DVDs and flash drives. In this chapter, we explain how data files are created, updated and processed by C programs. We consider both sequential-access and random-access file processing.

### File Extensions
File extensions
We can usually tell if a file is binary or text based on its file extension. This is because by convention the extension reflects the file format, and it is ultimately the file format that dictates whether the file data is binary or text.

Common extensions that are binary file formats:

	Images: jpg, png, gif, bmp, tiff, psd, ...
	Videos: mp4, mkv, avi, mov, mpg, vob, ...
	Audio: mp3, aac, wav, flac, ogg, mka, wma, ...
	Documents: pdf, doc, xls, ppt, docx, odt, ...
	Archive: zip, rar, 7z, tar, iso, ...
	Database: mdb, accde, frm, sqlite, ...
	Executable: exe, dll, so, class, ...

Common extensions that are text file formats:

	Web standards: html, xml, css, svg, json, ...
	Source code: c, cpp, h, cs, js, py, java, rb, pl, php, sh, ...
	Documents: txt, tex, markdown, asciidoc, rtf, ps, ...
	Configuration: ini, cfg, rc, reg, ...
	Tabular data: csv, tsv, ...


### Text File Characteristics

By convention, the data in every text file obeys a number of rules:

- The text looks readable to a human or at least moderately sane. Even if it contains a heavy proportion of punctuation symbols (like HTML, RTF, and other markup formats), there is some visible structure and it’s not seemingly random garbage.
- The data format is usually line-oriented. Each line could be a separate command, or a list of values could put each item on a different line, etc. The maximum number of characters in each line is usually a reasonable value like 100, not like 1000.
- The text looks readable to a human or at least moderately sane. Even if it contains a heavy proportion of punctuation symbols (like HTML, RTF, and other markup formats), there is some visible structure and it’s not seemingly random garbage.


## Binary File Characteristics

- For most software that people use in their daily lives, the software consumes and produces binary files. Examples of such software include Microsoft Office, Adobe Photoshop, and various audio/video/media players. A typical computer user works with mostly binary files and very few text files.
- A binary file always needs a matching software to read or write it. For example, an MP3 file can be produced by a sound recorder or audio editor, and it can be played in a music player or audio editor. But an MP3 file cannot be played in an image viewer or a database software.
- Some binary formats are popular enough that a wide variety of programs can produce or consume it. Image formats like JPEG are the best example – not only can they be used in image viewers and editors, they can be viewed in web browsers, audio players (for album art), and document software (such as adding a picture into a Word doc). 


## Files and Streams
C views each file simply as a sequential stream of bytes (Fig. 11.1). Each file ends either  with an `end-of-file (EOF)` marker or at a specific byte number recorded in a system-maintained, administrative data structure. When a file is opened, a stream is associated with it. 
- Three files and their associated streams are automatically opened when program execution begins — the standard input, the standard output and the standard error. Streams provide communication channels between files and programs. 
	- For example, the standard input stream enables a program to read data from the keyboard, and the standard output stream enables a program to print data on the screen. 
	- The standard input, standard output and standard error are manipulated using file pointers `stdin`, `stdout` and `stderr`. 
- Opening a file returns a pointer to a FILE structure (defined in `<stdio.h>`) that contains information used to process the file. 
	- In some operating systems, this structure includes a file descriptor, i.e., an index into an operating system array called the open file table. Each array element contains a file control block (**FCB**)—information that the operating system uses to administer a particular file. 

 - The standard library provides many functions for reading data from files and for writing data to files. Function `fgetc`, like `getchar`, reads one character from a file. Function `fgetc` receives as an argument a FILE pointer for the file from which a character will be read. The call `fgetc(stdin)` reads one character from `stdin`—the standard input. This call is equivalent to the call `getchar()`.
	- Function `fputc`, like `putchar`, writes one character to a file. Function `fputc` receives as arguments a character to be written and a pointer for the file to which the character will be written. The function call `fputc('a', stdout)` writes the character 'a' to `stdout`— the standard output. This call is equivalent to `putchar('a')`.
	- Several other functions used to read data from standard input and write data to standard output have similarly named file-processing functions. The fgets and fputs functions, for example, can be used to read a line from a file and write a line to a file, respectively. In the next several sections, we introduce the file-processing equivalents of functions `scanf` and `printf`— `fscanf` and `fprintf`. 


|Function	| Description |
|:-------	|:--------------|
|fopen | open a file for either sequential or random access | 
|fclose | close a file that has been opened for access | 
|fprintf	| Write to sequential (or text) file |
|fscanf | Read from sequential (or text) file | 
|fread | Read from random (or binary) file | 
|rwrite | Write to random (or binary) file |


## Types of file processing 

- There are two types of files - text and binary files 
- There are two techniques for processing files - sequential and random

Every open file has an associated `file position indicator`, which describes where read and write operations take place in the file. The position is always specified in bytes from the beginning of the file. When a new file is opened, the position indicator is always at the beginning of the file, i.e., at `position 0`.

- Writing and reading operations occur at the location of the position indicator and update the position indicator as well. Thus, if one wishes to read all the data in a file sequentially or write data to a file sequentially, it is not necessary to be concerned about the `position indicator` because the stream I/O functions take care of it automatically.

- When more control is required, the C library functions that help determine and change the value of the `file position indicator`, have to be used. By controlling the position indicator, random access of a file can be made possible. Here, random means that data can be read from, or written to, any position in a file without reading or writing all the preceding data.

# Creating a Sequential Access file

C imposes no structure on a file. Thus, notions such as a record of a file do not exist as part of the C language. The following example shows how you can impose your own record structure on a file.

![sequential](http://j.mp/seqFile)

Figure 11.2 creates a simple sequential-access file that might be used in an accounts
receivable system to keep track of the amounts owed by a company’s credit clients. 

- For each client, the program obtains an account number, the client’s name and the client’s balance (i.e., the amount the client owes the company for goods and services received in the past). The data obtained for each client constitutes a **“record”** for that client. 
- The **account number** is used as the record key in this application—the file will be created and maintained in account-number order. This program assumes the user enters the records in account number order. 

```c
// Fig. 11.2: fig11_02.c
// Creating a sequential file
#include <stdio.h>
#include <stdlib.h>

#define DATAFILE "clients.dat"

int main(void) {
  unsigned int account;  // account number
  char name[30];         // account name
  double balance;        // account balance

  FILE* cfPtr;  // cfPtr = clients.dat file pointer

  // fopen opens file. Exit program if unable to create file
  if ((cfPtr = fopen(DATAFILE, "w")) == NULL) {
    puts("File could not be opened");
    exit(0);
  }  // end if

  puts("Enter the account, name, and balance.");
  puts("Enter EOF to end input.");
  printf("%s", "? ");
  scanf("%d%29s%lf", &account, name, &balance);

  // write account, name and balance into file with fprintf
  while (!feof(stdin)) {
    fprintf(cfPtr, "%3d %-10s %.2f\n", account, name, balance);
    printf("%s", "? ");
    scanf("%d%29s%lf", &account, name, &balance);
  }  // end while
  puts("Done");
  fclose(cfPtr);  // fclose closes file
}  // end main
```


### Demo 
Run `prog13` in the http://bit.ly/replUnit5

**OUTPUT**

	Enter the account, name, and balance.
	Enter EOF to end input.
	? 100 Jones 24.98
	? 200 Doe 345.67
	? 300 White 0.00
	? 400 Stone -42.16
	? 500 Rich 224.62
	? ^D (or ^Z)

### Sample `clients.dat` file contents 

	100 Jones     24.98
	200 Doe       345.67
	300 White     0.00
	400 Stone     -42.16
	500 Rich      224.62


Now let’s examine this program. 
- `cfPtr` is a pointer to a FILE structure. A C program administers each file with a separate FILE structure. 
- Each open file must have a separately declared pointer of type FILE that’s used to refer to the file. The file name — **"clients.dat"** — will be used by the program and establishes a “line of communication” with the file. The file pointer **cfPtr** is assigned a pointer to the FILE structure for the file opened with **fopen**. 
- Function fopen takes two arguments: a **filename** (which can include path information leading to the file’s location) and a **file open mode**. 
	- The file open mode "w" indicates that the file is to be opened for writing. If a file does not exist and it’s opened for writing, **fopen** creates the file. 
	- If an existing file is opened for writing, the contents of the file are discarded without warning. 
	- In the program, the if statement is used to determine whether the file pointer cfPtr is NULL (i.e., the file is not opened). If it’s NULL, the program prints an error message and terminates. 
	- Otherwise, the program processes the input and writes it to the file. 
	- The program prompts the user to enter the various fields for each record or to enter end-of-file when data entry is complete. The tabulation below lists the key combinations for entering **end-of-file** (**`EOF`**) for various computer systems. 

| Operating system |   Key combination |
|:-----------------|:------------------|
|Linux/ Mac OS X   |   `<Ctrl> d`
|Windows           |   `<Ctrl> z`

- The function **feof** is used to determine whether the end-of-file indicator is set for the file to which stdin refers. The end-of-file indicator informs the program that there’s no more data to be processed. 
	- In Fig. 11.2, the end-of-file indicator is set for the standard input when the user enters the end-of-file key combination. The argument to function **feof** is a pointer to the file being tested for the end-of-file indicator (stdin in this case). 
	- The function returns a nonzero (true) value when the end-of-file indicator has been set; otherwise, the function returns zero. The while statement that includes the **feof** call in this program continues executing while the end-of-file indicator is not set.
- Now, data is written to the file `clients.dat`. The data may be retrieved later by a program designed to read the file (see Section 11.4). Function **fprintf** is equivalent to printf except that **fprintf** also receives as an argument a file pointer for the file to which the data will be written. Function **fprintf** can output data to the standard output by using **stdout** as the file pointer, as in:

    `fprintf( stdout, "%d %s %.2f\n", account, name, balance );`

- Finally, the program closes the **clients.dat** file with **fclose** and terminates. Function **fclose** also receives the file pointer (rather than the filename) as an argument. If function **fclose** is not called explicitly, the operating system normally will close the file when program execution terminates. This is an example of operating system “housekeeping.” 


## File Access Modes

Programs may process no files, one file or several files. Each file used in a program will have a different file pointer returned by fopen. All subsequent file-processing functions after the file is opened must refer to the file with the appropriate file pointer. Files may be opened in one of several modes (Fig. 11.5). **The binary modes are used when we have to manage random-access files.** 

If an error occurs while opening a file in any mode, fopen returns **NULL**. 

|Mode 	| Description |
|:-------	|:--------------|
|r			| Open an existing file for reading. |
|w		| Create a file for writing. If the file already exists, discard the current contents.
|a, a+ 	| Append: open or create a file for writing at the end of the file.
|r+		| Open an existing file for update (reading and writing).
|w+		| Create a file for update. If the file already exists, discard the current contents.

|Mode 	| Description |
|:-------	|:--------------|
|rb 		 | opens a binary file in reading mode |
|wb		 | opens or create a binary file in writing mode |
|ab, ab+ | opens a binary file in append mode |
|rb+		 | opens a binary file in both reading and writing mode |
|wb+	 | opens a binary file in both reading and writing mode |


## Reading Sequential Access file

Data is stored in files so that the data can be retrieved for processing when needed. The previous section demonstrated how to create a file for sequential access. This section shows how to read data sequentially from a file.

```c
// Fig. 11.6: fig11_06.c
// Reading and printing a sequential file
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned int account;  // account number
  char name[30];         // account name
  double balance;        // account balance

  FILE *cfPtr;  // cfPtr = clients.dat file pointer

  // fopen opens file; exits program if file cannot be opened
  if ((cfPtr = fopen("clients.dat", "r")) == NULL) {
    puts("File could not be opened");
		exit(0);
  }
  
  printf("%-10s%-13s%s\n", "Account", "Name", "Balance");
  fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);

  // while not end of file
  while (!feof(cfPtr)) {
    printf("%-10d%-13s%7.2f\n", account, name, balance);
    fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);
  }  // end while

  fclose(cfPtr);  // fclose closes the file
}  // end main

```
### Demo 
Run `prog14` in the http://bit.ly/replUnit5


### Sample Output 

	Account   Name         Balance
	100       Jones        9023.00
	200       Frank        234.00
	300       Mano         29023.00
	400       Bala         2344.00



Figure 11.6 reads records from the file "clients.dat" created by the program of Fig. 11.2 and prints their contents. 
- cfPtr is a pointer to a FILE. The file "clients.dat"  is opened for reading ("r"). We determine whether it has opened successfully (i.e., fopen does not return NULL). We then attempt to read a “record” from the file. 
- Function fscanf is equivalent to function scanf, except fscanf receives as an argument a file pointer for the file from which the data is read. After this statement executes the first time, account will have the value 100, name will have the value "Jones" and balance will have the value 24.98. 
- Each time the second **fscanf** statement executes, the program reads another record from the file and account, name and balance take on new values. 
- When the program reaches the end of the file, the file is closed and the program terminates. Function **feof** returns true only after the program attempts to read the nonexistent data following the last line. 



**Resetting the File Position Pointer**
To retrieve data sequentially from a file, a program normally starts reading from the beginning of the file and reads all data consecutively until the desired data is found. It may be desirable to process the data sequentially in a file several times (from the beginning of the file) during the execution of a program. The statement

	rewind( cfPtr );

causes a program’s file position pointer—which indicates the number of the next byte in the file to be read or written—to be repositioned to the beginning of the file (i.e., byte 0) pointed to by cfPtr. The file position pointer is not really a pointer. Rather it’s an integer value that specifies the byte in the file at which the next read or write is to occur. This is sometimes referred to as the file offset. The file position pointer is a member of the **FILE** structure associated with each file.


## Read numbers from file and calculate Average

The next program reads five (or more) integer values from the data file `num.dat`. In this program end-of-file marker `EOF` is used to exit the loop.

```c

/* Program to read from the num.dat file
 * and find the average of the numbers 
 */ 

#include <stdio.h>
#include <stdlib.h> 

#define DATAFILE "prog15.dat"

int main() {
  FILE* fp;
  int n[50], i = 0;
  float sum = 0;
  if ((fp = fopen(DATAFILE, "r")) == NULL) {
    printf("Unable to open %s...\n", DATAFILE);
    exit(0);
  }
  puts("Reading numbers from num.dat");
  while (!feof(fp)) {
    fscanf(fp, "%d ", &n[i]);
    printf("%d %d\n", i, n[i]);
    sum += n[i];
    i++;
  }
  fclose(fp);

  // if no data is available in the file
  if (i == 0)
    printf("No data available in %s", DATAFILE);
  
  float average = sum / i;
  printf("The average is %.3f for %d numbers\n", average, i);

  return 0;
}
```
### Demo 
Run `prog15` in the http://bit.ly/replUnit5 in conjunction with `prog15.txt`

### Sample Output 

![average](https://i.imgur.com/eY0HcUB.jpg)

# Random access file 

As we stated previously, records in a file created with the formatted output function
**fprintf** are not necessarily the same length. However, individual records of a random access file are normally fixed in length and may be accessed directly (and thus quickly)
without searching through other records. This makes random-access files appropriate for
airline reservation systems, banking systems, point-of-sale systems, and other kinds of
transaction-processing systems that require rapid access to specific data. There are other ways of implementing random-access files, but we’ll limit our discussion to this straightforward approach using fixed-length records.

  - Because every record in a random-access file normally has the same length, the exact
location of a record relative to the beginning of the file can be calculated as a function of the record key. We’ll soon see how this facilitates immediate access to specific records, even in large files.
  - Figure below illustrates one way to implement a random-access file. Such a file is like a freight train with many cars—some empty and some with cargo. Each car in the train has the same length.

![rand](http://j.mp/randFile)

Fixed-length records enable data to be inserted in a random-access file without
destroying other data in the file. Data stored previously can also be updated or deleted
without rewriting the entire file. In the following sections we explain how to create a
random-access file, enter data, read the data both sequentially and randomly, update the
data, and delete data no longer needed. 


## Creating Random Access File

Function **fwrite** transfers a specified number of bytes beginning at a specified location in memory to a file. The data is written beginning at the location in the file indicated by the file position pointer. Function **fread** transfers a specified number of bytes from the location in the file specified by the file position pointer to an area in memory beginning with a specified address. Now, when writing an integer, instead of using 

	fprintf(fPtr, "%d", number);

which could print a single digit or as many as 11 digits (10 digits plus a sign, each of which requires 1 byte of storage) for a four-byte integer, we can use 

	fwrite(&number, sizeof(int), 1, fPtr);

which always writes four bytes on a system with four-byte integers from a variable number to the file represented by `fPtr` (we’ll explain the `1` argument shortly). Later, **fread** can be used to read those four bytes into an integer variable number. Although fread and fwrite read and write data, such as integers, in fixed-size rather than variable-size format, the data they handle are processed in computer “raw data” format (i.e., bytes of data) rather than in **printf**’s and **scanf**’s human-readable text format. Because the “raw” representation of data is *system dependent*, “raw data” may not be readable on other systems, or by programs produced by other compilers or with other compiler options.

Functions **fwrite** and **fread** are capable of reading and writing arrays of data to and from disk. The third argument of both fread and fwrite is the number of elements in the array that should be read from or written to disk. The preceding fwrite function call writes a single integer to disk, so the third argument is 1 (as if one element of an array is being written). File-processing programs rarely write a single field to a file. Normally, they write one struct at a time, as we show in the following examples.

Consider the following problem statement:

> Create a credit-processing system capable of storing up to 100
> fixed-length records. Each record should consist of an account number
> that will be used as the record key, a last name, a first name and a
> balance. The resulting program should be able to update an account,
> insert a new account record, delete an account and list all the
> account records in a formatted text file for printing. Use a
> random-access file.

The next several sections introduce the techniques necessary to create the credit-processing program. Figure 11.10 shows how to open a random-access file, define a record format using a struct, write data to the disk and close the file. This program initializes all 100 records of the file "credit.dat" with empty structs using the function fwrite. Each empty struct contains `0` for the account number, `""` (the empty string) for the last name, `""` for the first name and 0.0 for the balance. The file is initialized in this manner to create space on disk in which the file will be stored and to make it possible to determine whether a record contains data.

```c

// Fig. 11.10: fig11_10.c
// Creating a random-access file sequentially
#include <stdio.h>

// clientData structure definition
struct clientData {
  unsigned int acctNum;  // account number
  char lastName[15];     // account last name
  char firstName[10];    // account first name
  double balance;        // account balance
};                       // end structure clientData

int main(void) {
  unsigned int i;  // counter used to count from 1-100
  // create clientData with default information
  struct clientData blankClient = {0, "", "", 0.0};
  FILE *cfPtr;  // credit.dat file pointer

  // fopen opens the file; exits if file cannot be opened
  if ((cfPtr = fopen("credit.dat", "wb")) == NULL) {
    puts("File could not be opened.");
  }  // end if
  else {
    // output 100 blank records to file
    for (i = 1; i <= 100; ++i) {
      fwrite(&blankClient, sizeof(struct clientData), 1, cfPtr);
    } 

    fclose(cfPtr);  // fclose closes the file
  } // end else
}  // end main

```

Function **fwrite** writes a block of bytes to a file. Line 29 causes the structure blankClient of size `sizeof(struct clientData)` to be written to the file pointed to by cfPtr. The operator sizeof returns the size in bytes of its operand in parentheses (in this case `struct clientData`). Function **fwrite** can actually be used to write several elements of an array of objects. To do so, supply in the call to **fwrite** a pointer to an array as the first argument and the number of elements to be written as the third argument. In the preceding statement, **fwrite** was used to write a single object that was not an array element. Writing a single object is equivalent to writing one element of an array, hence the 1 in the **fwrite** call. 

## Writing Random Access Data

Figure 11.11 writes data to the file **"credit.dat"**. It uses the combination of **fseek** and **fwrite** to store data at specific locations in the file. Function fseek sets the file position pointer to a specific position in the file, then fwrite writes the data. A sample execution is shown in Fig. 11.12.

```c
// Fig. 11.11: fig11_11.c
// Writing data randomly to a random-access file
#include <stdio.h>

// clientData structure definition
struct clientData {
  unsigned int acctNum;  // account number
  char lastName[15];     // account last name
  char firstName[10];    // account first name
  double balance;        // account balance
};                       // end structure clientData

int main(void) {
  FILE *cfPtr;  // credit.dat file pointer

  // create clientData with default information
  struct clientData client = {0, "", "", 0.0};

  // fopen opens the file; exits if file cannot be opened
  if ((cfPtr = fopen("credit.dat", "rb+")) == NULL) {
    puts("File could not be opened.");
  }  // end if
  else {
    // require user to specify account number
    printf("%s",
           "Enter account number"
           "(1 to 100, 0 to end input)\n?");
    scanf("%d", &client.acctNum);

    // user enters information, which is copied into file
    while (client.acctNum != 0) {
      // user enters last name, first name and balance
      printf("%s", "Enter lastname, firstname, balance\n? ");

      // set record lastName, firstName and balance value
      fscanf(stdin, "%14s%9s%lf", client.lastName, client.firstName,
             &client.balance);

      // seek position in file to user-specified record
      fseek(cfPtr, (client.acctNum - 1) * sizeof(struct clientData), SEEK_SET);

      // write user-specified information in file
      fwrite(&client, sizeof(struct clientData), 1, cfPtr);

      // enable user to input another account number
      printf("%s", "Enter account number\n? ");
      scanf("%d", &client.acctNum);
    }  // end while

    fclose(cfPtr);  // fclose closes the file
  }                 // end else
}  // end main

```
We position the file position pointer for the file referenced by cfPtr to the
byte location calculated by 

	`(client.accountNum - 1) * sizeof(struct clientData)`.

The value of this expression is called the offset or the displacement. Because the account number is between 1 and 100 but the byte positions in the file start with 0, 1 is subtracted from the account number when calculating the byte location of the record. Thus, for record 1, the file position pointer is set to byte 0 of the file. The symbolic constant `SEEK_SET` indicates that the file position pointer is positioned relative to the beginning of the file by the amount of the offset. As the above statement indicates, a seek for account number `1` in the file sets the file position pointer to the beginning of the file because the byte location calculated is 0. 

	int fseek( FILE *stream, long int offset, int whence );

The function prototype for **fseek** is where offset is the number of bytes to seek from whence in the file pointed to by stream—a positive offset seeks forward and a negative one seeks backward. Argument whence is one of the values `SEEK_SET`, `SEEK_CUR` or `SEEK_END` (all defined in `<stdio.h>`), which indicate the location from which the seek begins. 

	SEEK_SET - the seek starts at the beginning of the file 
	SEEK_CUR - the seek starts at the current location in the file and 
	SEEK_END - the seek starts at the end of the file 

#### Return values 
 - Function fscanf returns the number of data items successfully read or the value **EOF** if a problem occurs while reading data. 
 - Function **fseek** returns a nonzero value if the seek operation cannot be performed.
 - Function **fwrite** returns the number of items it successfully output. If this number is less than the third argument in the function call, then a write error occurred.


## Reading Random Access Data 

Function **fread** reads a specified number of bytes from a file into memory. For example,

	fread(&client, sizeof(struct clientData), 1, cfPtr);

reads the number of bytes determined by `sizeof(struct clientData)` from the file referenced by **cfPtr**, stores the data in client and returns the number of bytes read. The bytes are read from the location specified by the file position pointer. Function `fread` can read several fixed-size array elements by providing a pointer to the array in which the elements will be stored and by indicating the number of elements to be read. The preceding statement reads one element. 

To read more than one, specify the number of elements as **fread**’s third argument. Function fread returns the number of items it successfully input. If this number is less than the third argument in the function call, then a read error occurred.

Figure 11.14 reads sequentially every record in the "**credit.dat**" file, determines whether each record contains data and displays the formatted data for records containing data. Function **feof** determines when the end of the file is reached, and the **fread** function transfers data from the file to the `clientData` structure client. 

```c

// Fig. 11.14: fig11_14.c
// Reading a random-access file sequentially
#include <stdio.h>

// clientData structure definition
struct clientData {
  unsigned int acctNum;  // account number
  char lastName[15];     // account last name
  char firstName[10];    // account first name
  double balance;        // account balance
};                       // end structure clientData

int main(void) {
  FILE *cfPtr;  // credit.dat file pointer
  int result;   // used to test whether fread read any bytes

  // create clientData with default information
  struct clientData client = {0, "", "", 0.0};

  // fopen opens the file; exits if file cannot be opened
  if ((cfPtr = fopen("credit.dat", "rb")) == NULL) {
    puts("File could not be opened.");
  }  // end if
  else {
    printf("%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name",
           "Balance");

    // read all records from file (until eof)
    while (!feof(cfPtr)) {
      result = fread(&client, sizeof(struct clientData), 1, cfPtr);

      // display record
      if (result != 0 && client.acctNum != 0) {
        printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName,
               client.firstName, client.balance);
      }  // end if
    }    // end while

    fclose(cfPtr);  // fclose closes the file
  }                 // end else
}  // end main

```

**OUTPUT**

	Acct Last Name First Name Balance
	  29 Brown     Nancy      -24.54
	  33 Dunn      Stacey     314.33
	  37 Barker    Doug         0.00
	  88 Smith     Dave       258.34
	  96 Stone     Sam         34.98
	
**Fig. 11.14 | Reading a random-access file sequentially. (Part 2 of 2.)**


## Transaction processing using random access files 


We now present a substantial transaction-processing program using **random access** files. The program maintains a bank’s account information—updating existing accounts, adding new accounts, deleting accounts and storing a listing of all the current accounts in a text file for printing. We assume that the program of Fig. 11.10 (see program under ["Creating Random Access File"](#creating-random-access-file) heading) has been executed to create the file **credit.dat**.

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
  unsigned int acctNum;  // account number
  char lastName[15];     // account last name
  char firstName[10];    // account first name
  double balance;        // account balance
};                       // end structure clientData

// prototypes
unsigned int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);

int main(void) {
  FILE *cfPtr;          // credit.dat file pointer
  unsigned int choice;  // user's choice

  // fopen opens the file; exits if file cannot be opened
  if ((cfPtr = fopen("credit.dat", "rb+")) == NULL) {
    puts("File could not be opened.");
  }  // end if
  else {
    // enable user to specify action
    while ((choice = enterChoice()) != 5) {
      switch (choice) {
        // create text file from record file
        case 1:
          textFile(cfPtr);
          break;
        // update record
        case 2:
          updateRecord(cfPtr);
          break;
        // create record
        case 3:
          newRecord(cfPtr);
          break;
        // delete existing record
        case 4:
          deleteRecord(cfPtr);
          break;
        // display message if user does not select valid choice
        default:
          puts("Incorrect choice");
          break;
      }  // end switch
    }    // end while

    fclose(cfPtr);  // fclose closes the file
  }                 // end else
}  // end main

// create formatted text file for printing
void textFile(FILE *readPtr) {
  FILE *writePtr;  // accounts.txt file pointer
  int result;      // used to test whether fread read any bytes

  // create clientData with default information
  struct clientData client = {0, "", "", 0.0};

  // fopen opens the file; exits if file cannot be opened
  if ((writePtr = fopen("accounts.txt", "w")) == NULL) {
    puts("File could not be opened.");
  }  // end if
  else {
    rewind(readPtr);  // sets pointer to beginning of file
    fprintf(writePtr, "%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name",
            "Balance");

    // copy all records from random-access file into text file
    while (!feof(readPtr)) {
      result = fread(&client, sizeof(struct clientData), 1, readPtr);

      // write single record to text file
      if (result != 0 && client.acctNum != 0) {
        fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n", client.acctNum,
                client.lastName, client.firstName, client.balance);
      }  // end if
    }    // end while

    fclose(writePtr);  // fclose closes the file
  }                    // end else
}  // end function textFile

// update balance in record
void updateRecord(FILE *fPtr) {
  unsigned int account;  // account number
  double transaction;    // transaction amount

  // create clientData with no information
  struct clientData client = {0, "", "", 0.0};

  // obtain number of account to update
  printf("%s", "Enter account to update ( 1 - 100 ): ");
  scanf("%d", &account);

  // move file pointer to correct record in file
  fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);

  // read record from file
  fread(&client, sizeof(struct clientData), 1, fPtr);

  // display error if account does not exist
  if (client.acctNum == 0) {
    printf("Account #%d has no information.\n", account);
  }       // end if
  else {  // update record
    printf("%-6d%-16s%-11s%10.2f\n\n", client.acctNum, client.lastName,
           client.firstName, client.balance);

    // request transaction amount from user
    printf("%s", "Enter charge ( + ) or payment ( - ): ");
    scanf("%lf", &transaction);
    client.balance += transaction;  // update record balance

    printf("%-6d%-16s%-11s%10.2f\n", client.acctNum, client.lastName,
           client.firstName, client.balance);

    // move file pointer to correct record in file
    fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);

    // write updated record over old record in file
    fwrite(&client, sizeof(struct clientData), 1, fPtr);
  }  // end else
}  // end function updateRecord

// delete an existing record
void deleteRecord(FILE *fPtr) {
  struct clientData client;  // stores record read from file
  struct clientData blankClient = {0, "", "", 0};  // blank client

  unsigned int accountNum;  // account number

  // obtain number of account to delete
  printf("%s", "Enter account number to delete ( 1 - 100 ): ");
  scanf("%d", &accountNum);

  // move file pointer to correct record in file
  fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);

  // read record from file
  fread(&client, sizeof(struct clientData), 1, fPtr);

  // display error if record does not exist
  if (client.acctNum == 0) {
    printf("Account %d does not exist.\n", accountNum);
  }       // end if
  else {  // delete record
    // move file pointer to correct record in file
    fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);

    // replace existing record with blank record
    fwrite(&blankClient, sizeof(struct clientData), 1, fPtr);
  }  // end else
}  // end function deleteRecord

// create and insert record
void newRecord(FILE *fPtr) {
  // create clientData with default information
  struct clientData client = {0, "", "", 0.0};

  unsigned int accountNum;  // account number

  // obtain number of account to create
  printf("%s", "Enter new account number ( 1 - 100 ): ");
  scanf("%d", &accountNum);

  // move file pointer to correct record in file
  fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);

  // read record from file
  fread(&client, sizeof(struct clientData), 1, fPtr);

  // display error if account already exists
  if (client.acctNum != 0) {
    printf("Account #%d already contains information.\n", client.acctNum);
  }       // end if
  else {  // create record
    // user enters last name, first name and balance
    printf("%s", "Enter lastname, firstname, balance\n? ");
    scanf("%14s%9s%lf", &client.lastName, &client.firstName, &client.balance);

    client.acctNum = accountNum;

    // move file pointer to correct record in file
    fseek(fPtr, (client.acctNum - 1) * sizeof(struct clientData), SEEK_SET);

    // insert record in file
    fwrite(&client, sizeof(struct clientData), 1, fPtr);
  }  // end else
}  // end function newRecord

// enable user to input menu choice
unsigned int enterChoice(void) {
  unsigned int menuChoice;  // variable to store user's choice

  // display available options
  printf("%s",
         "\nEnter your choice\n"
         "1 - store a formatted text file of accounts called\n"
         "    \"accounts.txt\" for printing\n"
         "2 - update an account\n"
         "3 - add a new account\n"
         "4 - delete an account\n"
         "5 - end program\n? ");

  scanf("%u", &menuChoice);  // receive choice from user
  return menuChoice;
}  // end function enterChoice

```

# Command line arguments

**Command line arguments** are simply **arguments** that are specified after the name of the program in the system's **command line**, and these **argument** values are passed on to your program during program execution.

![command](https://files.gitter.im/kgashok/advik/jbXG/commandLineArgv.png)

On many UNIX systems, it is possible to pass arguments to **`main`** from the command line by including the parameters **`int argc`** and **`char *argv[]`** in the parameter list of **`main()`**. 

  - Parameter **`argc`** receives the number of command-line arguments
  - Parameter **`argv`** is an array of strings in which the actual command-line arguments are stored  

- Common uses of command-line arguments include passing options to a program and passing filenames to a program.  

It is possible to pass arguments to `C` programs when they are executed. The brackets which follow `main()` are used for this purpose. `argc` refers to the number of arguments passed, and `argv[]` is a pointer array which points to each argument which is passed to `main`. 

## Simple example 
A simple example follows, which checks to see if a single argument is supplied on the command line when the program is invoked. The program is called by the command line,

	 > myprog argument1

The actual `C` code for the program is presented below: 

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("%s: ", argv[0]);
  if(argc == 2)
    printf("The argument supplied is %s\n", argv[1]);
  else if(argc > 2)
    printf("Too many arguments supplied.\n");
  else
    printf("One argument expected.\n");
  
  printf("%s: '%s' is the last argument!\n", 
    argv[0], argv[argc-1]);
  return 0;
}

```

Note that `argv[0]` is the name of the program invoked, which means that `argv[1]` is a pointer to the first argument supplied, and `argv[argc-1]` is a pointer to the last argument. If no arguments are supplied, `argc` will be `1`. Thus for `n` arguments, `argc` will be equal to `n + 1`. 

### Sample Output
![cargs](https://i.imgur.com/FNss2oE.jpg)

### Demo 
Compile and run `prog31` in http://j.mp/replUnit5 


## Another example 

Review the [argument sorting program](https://github.com/kgisl/cs8251/blob/master/code/argsort.c) to see how `argc` and `argv[]` are used to pass as arguments for `qsort` which sorts the input command line arguments. 


## Program 5.3

**Program 5.3** below copies a file into another file one character at a time. We assume that the executable file for the program is called **mycopy**. A typical command line for the **mycopy** program on a Linux/UNIX system is  

	> `mycopy input output`  

- This command line indicates that file **input** is to be copied to file **output**. When the program is executed, if **argc** is not 3 (**mycopy** counts as one of the arguments), the program prints an error message and terminates. Otherwise, array **argv** contains the strings "mycopy", "input" and "output".   
- The second and third arguments on the command line are used as file names by the program. The files are opened using function **fopen**. If both files are opened successfully, characters are read from file **input** and written to file **output** until the **end-of-file indicator** for file input is set.   
- Then the program terminates. The result is an exact copy of file input (if no errors occur during processing).  

```
// Using command-line arguments
#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *inFilePtr;   // input file pointer
  FILE *outFilePtr;  // output file pointer
  int c;             // define c to hold characters read from the source file

  // check number of command-line arguments
  if (argc != 3) {
    puts("Usage: mycopy infile outfile");
  }  // end if
  else {
    // if input file can be opened
    if ((inFilePtr = fopen(argv[1], "r")) != NULL) {
      // if output file can be opened
      if ((outFilePtr = fopen(argv[2], "w")) != NULL) {
        // read and output characters
        while ((c = fgetc(inFilePtr)) != EOF) {
          fputc(c, outFilePtr);
        }  // end while

        fclose(outFilePtr);  // close the output file
      }                      // end if
      else {                 // output file could not be opened
        printf("File \"%s\" could not be opened\n", argv[2]);
      }  // end else

      fclose(inFilePtr);  // close the input file
    }                     // end if
    else {                // input file could not be opened
      printf("File \"%s\" could not be opened\n", argv[1]);
    }  // end else
  }    // end else
}  // end main
 
```

_Also refer to the test case `file_copy` in [solution.test.cpp](#solution.tests.cpp)_ 

### Count bytes in a file 

Version 1 (using command line args)
	 -  https://github.com/kgashok/filesOCR/blob/master/hand.c  

Version 2  
	 - test case `count_number_of_bytes_in_text_file` in [solution.test.cpp](#solution.tests.cpp)




# FAQ 

**1. What is file?**  
 A file is a collection of bytes stored on a secondary storage device, which
is generally a disk of some kind. It is identified by a name, which is given
at the time of its creation. It may be amended, moved from one storage
device to another or removed completely when desired. 

**2. What is a stream?**  
In C, the stream is a common, logical interface to the various devices
that form the computer. When the program executes, each stream is
tied together to a specific device that is source or destination of data.
The stream provides a consistent interface and to the programmer one
hardware device will look much like another. In its most common form,
a stream is a logical interface to a file. Stream I/O uses some temporary
storage area, called buffer, for reading from or writing data to a file.
A stream is linked to a file by using an open operation. A stream is
disassociated from a file using a close operation.
The C language provides three “standard” streams that are always
available to a C program. These are

		Name   Description      Example
		stdin  Standard Input   Keyboard
		stdout Standard Output  Screen
		stderr Standard Error   Screen


**3. What is buffer? What’s its purpose?**  
Buffer is a temporary storage area that holds data while they are being
transferred to and from memory. Buffering is a scheme that prevents
excessive access to a physical I/O device like a disk or a terminal. Its
purpose is to synchronize the physical devices that the program needs. 
The buffer collects output data until there are enough to write efficiently.
The buffering activities are taken care of by software called device
drivers or access methods provided by the operating system.  

**4. Why have buffers?**  
It speeds up input/output which can be a major bottleneck in execution
times. That is, it is less time-consuming to transmit several characters
as a block than to send them one by one.  

**5. What is **FILE**?**  
FILE is a structure declared in stdio.h. The members of the
FILE structure are used by the program in the various file access
operations. For each file that is to be opened, a pointer to type FILE
must be declared. When the function `fopen()` is called, that function
creates an instance of the FILE structure and returns a pointer to that
structure. This pointer is used in all subsequent operations on the file.
But programmers don’t need to be concerned about the members of the
structure FILE.

Because one may use a number of different files in the program,
he or she must specify when reading or writing which file one wishes
to use. This is accomplished by using a variable called a file pointer, a
pointer variable that points to a structure FILE.  

**6. How many files can I open at once?**  
 The number of files that can be opened at once will be determined by
the value of the constant FOPEN_MAX that is defined in `<stdio.h>`.
`FOPEN_MAX` is an integer that specifies the maximum number of streams
that can be open at one time. The C language standard requires that
the value of `FOPEN_MAX` be at least 8, including the standard streams 
`stdin`, `stdout` and `stderr`. Thus, as a minimum, it’s possible to
work with up to 5 files simultaneously.  

**7. What is the advantage of text files over binary files?**  
Due to differences in binary data representations across platforms, 
files written in binary format often are not portable. 
For more portable file representations, consider using text files.



# Bonus Material


### Modular Versions

Fork [this CD session][unit5] to get testable code!  

[unit5]: http://cyberdojo1.kgfsl.com/forker/fork/6EA156F740?avatar=hyena&tag=-1

#### read\_from_stream\_into\_array(const char*, FILE*, int[])

```c
// can also be easily extended and modified
// will come handy for next refactoring
//
int read_from_stream_into_array(
    const char* fname,  // to use in logging if there is an error
    FILE* fp,           // can also be assigned to stdin
    int array[],        // array to be filled with values
    int size            // will decide max num of entries to read
    ) {
  int counter = 0;
  if (fp != NULL) {
    printf("Reading numbers from %s\n", fname);
    while (!feof(fp) && counter < size) {
      fscanf(fp, "%d ", &array[counter]);
      printf("%d %d\n", counter, array[counter]);
      counter++;
    }
  } else
    printf("Invalid file pointer for file:%s!", fname);

  return counter;
}

```

#### calculate\_sum(int[] arr, int size)

```c
float calculate_sum(int arr[], int size) {
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum = sum + arr[i];
  }
  printf("Sum: %f\n", sum);
  return sum;
}

   
```

#### modular main()

```c

int main(int argc, char* argv[]) {
  int n[50];

  FILE* fp = fopen("num.dat", "r");
  int i = read_from_stream_into_array("num.dat", fp, n, 5);

  if (i > 0) {
    float sum = calculate_sum(n, i);
    float average = sum / i;
    printf("The average is %f for %d numbers\n", average, i);
  } else {
    puts("No data available in num.dat!");
  }
  fclose(fp);
}

```

## Averaging entries from stdin 

```c
int main() {
  int n[50];

  int i = read_from_stream_into_array("stdin", stdin, n, 6);

  if (i > 0) {
    float sum = calculate_sum(n, i);
    float average = sum / i;
    printf("The average is %f for %d numbers\n", average, i);
  } else {
    puts("No data available on stdin!");
  }
}
```


## Example Program: Average of numbers

Write a program to calculate the average of first n numbers. This is the simplest version of calculating averages of a bunch of numbers. 

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


## Using '9999' as EOF 

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
    fprintf(fp, "%d", 9999);
    fclose(fp);
  } else
    printf("Unable to open num.dat...\n");
}
```
 
**Output:**

	Enter 5 numbers, to be stored in num.dat ... 1 2 3 4 5


### solution.h

```c
#ifndef SOLUTION_INCLUDED
#define SOLUTION_INCLUDED

int   read_from_stream_into_array(const char*, FILE *f, int a[], int size); 
int   write_to_stream_from_array(const char*, FILE *f, int a[], int size);
float calculate_sum(int arr[], int size);

int   filesize(FILE* fp);
int   filecopy(FILE* source, FILE* dest);
int   fileappend(FILE* source, FILE* dest);
int   fileprint(FILE* fp);

void hello(void);
#endif
```

### solution.c 

```c

#include <stdio.h>
#include "solution.h"

int filesize(FILE* fp)
{
    fseek(fp, 0, SEEK_SET);

    int count = 0;
    if (fp) {
        while (fgetc(fp) && !feof(fp) && ++count)
            ;

        rewind(fp);
        return count;
    }
    return -1;
}

int filecopy(FILE* source, FILE* dest)
{
    int count = 0;
    char c;
    if (source != 0 && dest != 0) {
        while ((c = fgetc(source)) && !feof(source) && ++count)
            fputc(c, dest);

        rewind(source);
        rewind(dest);
        return count;
    }
    return -1;
}

int fileappend(FILE* source, FILE* dest)
{
    int res = fseek(dest, 0, SEEK_END);

    int count = 0;
    if (!res) {
        count = filecopy(source, dest);
        return count;
    }
    return -1;
}

int fileprint(FILE* fp)
{
    int res = fseek(fp, 0, SEEK_SET);

    int count = 0;
    char c;
    if (!res) {
        while ((c = fgetc(fp)) && !feof(fp) && ++count)
            putc(c, stdout);
        return count;
    }
    return -1;
}


// can also be easily extended and modified
// will come handy for next refactoring
//
int read_from_stream_into_array(
    const char* fname, // to use in logging if there is an error
    FILE* fp, // can also be assigned to stdin
    int array[], // array to be filled with values
    int size // will decide max num of entries to read
    )
{
    int counter = 0;
    if (fp != NULL) {
        printf("Reading numbers from %s\n", fname);
        while (!feof(fp) && counter < size) {
            fscanf(fp, "%d ", &array[counter]);
            printf("%d %d\n", counter, array[counter]);
            counter++;
        }
    }
    else
        printf("Invalid file pointer for file:%s!", fname);

    return counter;
}

int write_to_stream_from_array(
    const char* fname,
    FILE* fp,
    int array[],
    int size)
{
    int index = 0;
    if (fp != NULL) {
        while (index < size) {
            fprintf(fp, "%d\n", array[index]);
            index++;
        }
    }
    else
        printf("Invalid file pointer for file:%s!", fname);

    return index;
}


// Calculate the sum but pays attention to only
// the number of entries made into the array
//
float calculate_sum(int arr[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    printf("Sum: %f\n", sum);
    return sum;
}


```

### solution.tests.cpp 


```c

#include <gtest/gtest.h>

extern "C" {
#include "solution.h"
#include "_utils.h"
}

using namespace ::testing;


TEST(FileTest, read_from_two_files_and_merge_to_third_file)
{
    FILE *fp1, *fp2, *fp3;
    fp1 = fopen("first.txt", "r");
    fp2 = fopen("second.txt", "r");
    fp3 = fopen("file3.txt", "w+");

    filecopy(fp1, fp3);
    fileappend(fp2, fp3);

    // how do you know it worked?
    int size1, size2, size3;
    size1 = filesize(fp1);
    size2 = filesize(fp2);
    size3 = filesize(fp3);
    ASSERT_EQ(size1 + size2, size3); // validation count-wise

    // validate it visually as well!
    fileprint(fp3);
}

TEST(FileTest, read_from_stdin_and_append_to_existing_file)
{
    // normally not required
    redirect("num.txt", stdin, "r");

    FILE* fp1 = fopen("file2.txt", "w+");
    int before = filesize(fp1);
    fileappend(stdin, fp1); // contents from stdin >> file2
    int after = filesize(fp1);
    fclose(fp1);

    printf("before %d , after %d\n", before, after);
}

TEST(FileTest, file_append)
{
    FILE *fp1, *fp2;
    fp1 = fopen("file1.txt", "r");
    fp2 = fopen("file2.txt", "w+");

    int count = filesize(fp1);
    int count2 = 0;
    if (fp1 != 0 && fp2 != 0) {
        filecopy(fp1, fp2);
        fileappend(fp1, fp2);
        count2 = filesize(fp2);
        ASSERT_EQ(count * 2, count2);
    }
    else
        ASSERT_FALSE(false);
}

TEST(FileTest, file_copy)
{
    FILE *fp1, *fp2;
    fp1 = fopen("file1.txt", "r");
    fp2 = fopen("file2.txt", "w+");

    int count = filesize(fp1);
    int count2 = 0;
    if (fp1 != 0 && fp2 != 0) {
        filecopy(fp1, fp2);
        count2 = filesize(fp2);
        ASSERT_EQ(count, count2);
        fclose(fp1);
        fclose(fp2);
    }
    else {
        ASSERT_FALSE(false);
    }

    fp1 = fopen("num.txt", "r");
    count = filesize(fp1);
    fclose(fp1);

    redirect("num.txt", stdin, "r");
    fp2 = fopen("file2.txt", "w+");
    filecopy(stdin, fp2);
    count2 = filesize(fp2);

    ASSERT_EQ(count, count2);
    fclose(fp2);
}



TEST(FileTest, get_from_stdin_and_calculate_average)
{
    redirect("num.txt", stdin, "r");
    int n[50];

    int i = read_from_stream_into_array("stdin", stdin, n, 6);

    if (i > 0) {
        float sum = calculate_sum(n, i);
        float average = sum / i;
        printf("The average is %f for %d numbers\n",
            average, i);
        ASSERT_FLOAT_EQ(average, 667.333313);
    }
    else {
        puts("No data available in num.txt!");
    }
}


TEST(FileTest, read_from_two_files_and_sum_into_third_file)
{
    FILE *fp1, *fp2, *fp3;
    fp1 = fopen("stat1.txt", "r");
    fp2 = fopen("stat2.txt", "r");
    fp3 = fopen("star3.txt", "w+");

    int arr1[5], arr2[5], arr3[5];
    read_from_stream_into_array("stat1.txt", fp1, arr1, 5);
    read_from_stream_into_array("stat2.txt", fp2, arr2, 5);
    for (int i = 0; i < 5; i++) {
        arr3[i] = arr1[i] + arr2[i];
    }

    fputs("array 1\n", fp3);
    write_to_stream_from_array("stat3.txt", fp3, arr1, 5);
    fputs("array 2\n", fp3);
    write_to_stream_from_array("stat3.txt", fp3, arr2, 5);
    fputs("The Sum!\n", fp3);
    write_to_stream_from_array("stat3.txt", fp3, arr3, 5);
    fileprint(fp3); // should print '6 6 6 6 6'

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}


TEST(FileTest, count_number_of_bytes_in_text_file)
{

    FILE* fp = fopen("podcast.txt", "r");
    if (fp == NULL)
        printf("File is not available!\n");

    int count = 0;
    while (fgetc(fp) && !feof(fp) && ++count)
        ;
    printf("Number of bytes: %d\n", count);
    fclose(fp);
    ASSERT_EQ(count, 3667);
}


TEST(FileTest, DISABLED_get_from_stdin_and_store_values_in_file)
{
    redirect("num.txt", stdin, "r");

    FILE* fp;
    int n[5], i = 0;
    if ((fp = fopen("num.dat", "w")) != NULL) {
        puts("Enter 5 numbers, to be stored in num.dat...");
        for (i = 0; i < 5; i++) {
            scanf("%d", &n[i]);
            fprintf(fp, "%d\n", n[i]);
        }
        //fprintf(fp,"%d", 9999);
        fclose(fp);
    }
    else
        printf("Unable to open num.dat...\n");
}


TEST(FileTest, calculate_average_of_numbers_in_file_using_functions)
{
    int n[50];

    FILE* fp = fopen("num.dat", "r");
    int i = read_from_stream_into_array("num.dat", fp, n, 5);

    if (i > 0) {
        float sum = calculate_sum(n, i);
        float average = sum / i;
        printf("The average is %f for %d numbers\n",
            average, i);
        ASSERT_EQ(average, 3);
    }
    else {
        puts("No data available in num.dat!");
    }
    fclose(fp);
}

// verbose yet simple, non-functional version
TEST(FileTest, calculate_average_of_numbers_stored_in_file)
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
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTUwOTU1MzQwNywtMTc4NTQ4NjY0OCwtMT
I2OTYyMTg1MiwtMTcyMjQ5NjY4MCwtMTA5MDU2MDU2OCwxNjAz
NzIxMTI0LDE5MDE2ODI2NDMsMzAzMTMxMjcsLTE0ODgzNzkyMj
UsOTM0MDE1MzYzLC03MjAwODcyNzYsLTE2MjA4MDk2NDMsODAw
Mjc3MjEwLDE0NDcyNTE2MTgsLTE1OTY2NzY2MzgsLTY5OTAxNj
E2MCw5MzM1NDcyNjUsODEzNTg2NjIxLC02MzEwMDE3NzcsODQ5
MzU4MTc3XX0=
-->