/******************************************************
   KnR 7-6
   --------
   Write a program to compare two files and print the
   first line where they differ.

   Author: Rick Dearman
   email: rick@ricken.demon.co.uk

   Note: This program prints ALL the lines that are
         different using the <> indicators used by
         the unix diff command. However this program
         will not cope with something as simple as a
         line being removed.

         In reality the program would be more useful
         if it searched forward for matching lines.
         This would be a better indicator of the simple
         removal of some lines.

         This has lead Richard Heathfield to track down a version of the
         "diff" command available on GNU/Linux systems.
         for more information go to the web site at:
         www.gnu.org

******************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000

void diff_line(char *lineone, char *linetwo, int linenumber) {
  if (strcmp(lineone, linetwo))
    printf("%d<%s%d>%s\n", linenumber, lineone, linenumber, linetwo);
}

int main(int argc, char *argv[]) {
  FILE *fp1, *fp2;
  char fp1_line[MAXLINE], fp2_line[MAXLINE];
  int i;

  if (argc != 3) {
    printf("differ fileone filetwo\n");
    exit(0);
  }

  fp1 = fopen(argv[1], "r");
  if (!fp1) {
    printf("Error opening file %s\n", argv[1]);
  }

  fp2 = fopen(argv[2], "r");
  if (!fp2) {
    printf("Error opening file %s\n", argv[2]);
  }
  i = 0;
  while ((fgets(fp1_line, MAXLINE, fp1) != NULL) &&
         (fgets(fp2_line, MAXLINE, fp2) != NULL)) {
    diff_line(fp1_line, fp2_line, i);
    i++;
  }

  return 0;
}
