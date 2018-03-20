## Subsequence

Given two strings `needle` and `haystack`, find if `needle` is a subsequence of `haystack`. A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements (source: [wiki](http://en.wikipedia.org/wiki/Subsequence)). Expected time complexity is **linear**.

Write the function logic using recursion; do not use for loops. 

**BONUS**: It is actually possible to  use just two pointer variables for the complete solution. Go for it! 


----------


### Example 

	("ab", "abcde") -> 1
	("ab", "addde") -> 0 
	("NEEDLE", "haNystEEaDcLkkkkkEe") -> 1
	("truck", "ruc") -> 0 
	("truck", "") -> 1 
	("", "truck2") -> 0 
	("TRUCKS", "ABCDEFHIKS") -> 0 

