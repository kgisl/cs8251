# Sort names like UNIX sort 

- Listen to http://j.mp/unixSortDemo for a demo of `sort` in Linux. 
- Try out Unix `sort` on CyberDojo - http://j.mp/unixSortingCD 
-  For `selectsort`, see this [video](http://j.mp/selectionSortVideo)

Write a program that will sort a set of text tokens into alphabetic order, a stripped-down version of the UNIX program [sort](https://linuxcontainers.org/lxd/try-it/?id=c3c04935-ecdb-44a1-8085-778882616421#introduction) and handle only one single input line. 

![image](http://j.mp/pointerArrays)

The program will need to deal with text tokens, which are of different lengths, and which, unlike integers, can't be compared or moved in a single operation. We need a data representation that will cope efficiently and conveniently with variable-length text tokens. 

This is where the array of pointers enters. Since pointers are variables themselves, they can be stored in arrays just as other variables can. 

If the tokens to be sorted are stored in character arrays, then each line can be accessed by a pointer to its first character. The pointers themselves can be stored in an array. Two tokens can be compared by passing their pointers to `strcmp`. When two out-of-order tokens have to be exchanged, the pointers in the pointer array are exchanged, not the token strings themselves. 

This eliminates the twin problems of complicated storage management and high overhead that would go with moving the tokens themselves. 

The sorting process has three steps: 

>>read all the tokens of input 
>>sort them 
>>print them in order 

As usual, it's best to divide the program into functions that match this natural division, with the main routine controlling the other functions. Let us defer the sorting step for a moment, and concentrate on the data structure and the input and output. 

The input routine has to collect and save the characters of each token, and build an array of pointers to the tokens. It will also have to count the number of token strings, since that information is needed for sorting and printing. Since the input function can only cope with a finite number of input tokens, it can return some illegal count like `-1` if too much input is presented. 

The output routine only has to print the tokens in the order in which they appear in the array of pointers. 