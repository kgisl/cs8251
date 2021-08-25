#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc == 3)
    {
        char *file1 = argv[1];
        char *file2 = argv[2];
        char *temp = "tmpname";
        rename(file1, temp);
        rename(file2, file1); // file2 is named file1
        rename(temp, file2);  // temp (aka file1) is named file2
        perror("rename");
    }
    else
    {
        printf("Usage: swap <filename1> <filename2>\n");
    }
    return 0;
}

/*
    char temp[L_tmpnam] = "XXXXXX";
    mkstemp(temp);
    printf ("unique filename generated: %s\n", temp);
    // remove(temp);
*/