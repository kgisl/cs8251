
## Write your own `strlen` function

http://en.cppreference.com/w/c/string/byte/strlen

Write your own C function that behaves like the built-in `C` function `strlen`.  

 - Returns the length of the given null-terminated byte string. That is, the number of characters in a character array whose first element is pointed to by `str` up to and not including the first null character (`'\0'`).
 - In addition,  your `mystrlen` function must return `-1` if the character array contains non alphanumeric characters. 

**Bonus Points** for 
  - Using a character pointer to traverse the character array as you did in   http://j.mp/pointerWalk . 
  - Not using a integer variable to count. Use pointer arithmetic to come up with the string length.
  - Not using any other variable other than a character pointer variable and the `arr` variable

## Example 

`mystrlen({'a', 'b', '\0'} == 2 `     
`mystrlen({'a', 'b', '@'} == -1 `    
`mystrlen({'a', 'b', 'c', '\0'} == 3 `    

### Spoiler Alert 

http://j.mp/mystrlenPNG

