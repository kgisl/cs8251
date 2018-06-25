# Pointer Camp
http://j.mp/pointKITE  - the problem set that is used for a 20-hour workshop for Immersive Perceptual Learning of Indirection (aka Pointers) - the most important **Threshold Concept** in programming. Arguably, this is the largest and progressively challenging problem set (PC-P) that is relevant for learning, teaching and assessment of knowledge/competency in pointers. 

  - Totally new to Pointers? First go update yourself at http://j.mp/pointerGlossary

  - Review http://j.mp/fileChallenge - can you quickly write up a C code for the challenge? 
    - Three concepts - Functions from Unit_3(`fread`, `fwrite`, etc), structures from Unit_4 ([opaque][opaque] `FILE` typedef for`struct iobuf`) and pointers from Unit_3 (FILE *)  come together to accomplish file processing ([Unit_5](http://j.mp/unit5Easy))
    - One of the most practical use cases for pointers 

[opaque]: j.mp/opaqueC 

# - String based (38 -> 41)
A null-terminated byte string (NTBS) is a sequence of nonzero bytes followed by a byte with value **`zero`** (the terminating null character). Each byte in a byte string encodes one character of some character set. For example, the character array `{'\x63','\x61','\x74','\0'}` is an **NTBS** holding the string **"cat"** in ASCII encoding.

## String examination  (24 -> 27)
_What is inside the string? Is the needle present in the haystack?_
- [strchar](http://j.mp/stringCharCC) and [strrchar](http://j.mp/stringrcharCC),  
- [strichr](http://j.mp/stringicharCC) and [strrichar](http://j.mp/stringiRcharCC)
- [strlen](http://j.mp/stringLenCC) and [mystrlen](http://j.mp/strlenCC),
- [vowel counting](https://j.mp/vowelCC),
- -- BREAK  _here_
- [strstr](http://j.mp/stringStrCC) and [strstrw](http://j.mp/strstrwrapCC), 
- [strend](http://j.mp/stringEndCC), 
- [strcmp](http://j.mp/stringCompareCC) and [strncmp](http://j.mp/stringncompareCC)
- strend (_take  2_)
- [strpbrk](http://j.mp/strpbrkCC), 
- [strcspn](http://j.mp/stringcspnCC), 
- [strspn](http://j.mp/stringspnCC), 
- [strtok](http://j.mp/strTokenizeCC),
- [subset](http://j.mp/subSetCC), 
- [subsequence](http://j.mp/subSeqCC)
- --- *BREAK here*
- [have_no_fives](http://j.mp/haveNoFive) 
- [has_duplicates]() TBD
- [count_occurrences]() TBD
- [pangram](http://j.mp/panGramCC) and [partial](http://j.mp/pangramCC), 
- [isogram](http://j.mp/isogramCC) and [higher](http://j.mp/multipleIsogramCC),
- [anagram](http://j.mp/anagramCC)
- [word count](http://j.mp/wordcountCC)
- [vowels in order](http://j.mp/vowelsinorderCC) TBD 


## String manipulation (8)
_How can I change the contents inside a string?_ 
- [strcpy](http://j.mp/stringCopyCC) and [strncpy](http://j.mp/stringNcopyCC),
- [strcat](http://j.mp/stringCatCC) and [strncat](http://j.mp/stringNcatCC),
- [strupper](http://j.mp/toUpperCC),
- [strlower](http://j.mp/toLowerCC),
- [strflipcase](http://j.mp/stringflipcaseCC), 
- [strrev](http://j.mp/reverseUsingPointers),

## String allocation (dynamic memory) (6)
_How do I generate new strings from existing ones?_
- [subString](http://j.mp/subStringCC), 
- [indexOf](http://j.mp/indexCC),
- [abbreviate](http://j.mp/acronymCC) (exercism and CapGemini), 
- [replaceString](http://j.mp/replaceCC),
- [binaryAdd](http://j.mp/binaryAddCC) (CapGemini), 
  
# - Array Manipulation  (3)
- [alphabets](https://cloudcoder.kgkite.ac.in/cloudcoder/#exercise?c=33,p=1208) 
- [day_of_year](http://j.mp/dayYearCC)  - multidimensional array 1
- [matrixUpdate](http://j.mp/arrayPointer) - multidimensional array 2

# - Function Parameters (5)
- [pointerWalk](http://j.mp/pointerWalk)
- [add_one](https://cloudcoder.kgkite.ac.in/cloudcoder/#exercise?c=33,p=967) 
- [swap](http://j.mp/swapUsingPointers) 
- [doubleSwap](http://j.mp/doubleSwap)
- [palindrome](http://j.mp/dPalindromeKG) using double pointers


# - PDS-1 Practice (4)
  - Lab 3
	 - [connect](http://cloudcoder.kgkite.ac.in/cloudcoder/#exercise?c=7,p=1191), [traverse](http://cloudcoder.kgkite.ac.in/cloudcoder/#exercise?c=7,p=1190) and 
[insertBefore](http://cloudcoder.kgkite.ac.in/cloudcoder/#exercise?c=7,p=1193)
	 - [Doubly-Linked List](http://cloudcoder.kgkite.ac.in/cloudcoder/#exercise?c=7,p=1189)
       - Processing strings as linked lists [TBD]
  - Lab 6 
    - [Fixed Array based Stack](http://cloudcoder.kgkite.ac.in/cloudcoder/#exercise?c=7,p=1115)
      - [PostFix Eval](http://cloudcoder.kgkite.ac.in/cloudcoder/#exercise?c=7,p=1120),  [PostFix to Infix](http://j.mp/infixPostfix)
      - [Bracket Matching](http://cloudcoder.kgkite.ac.in/cloudcoder/#exercise?c=7,p=1126)
    - [Linked List based Stack](http://cloudcoder.kgkite.ac.in/cloudcoder/#exercise?c=7,p=1162)
    - [Linked List based Queue](http://cloudcoder.kgkite.ac.in/cloudcoder/#exercise?c=7,p=1188)

<!---
## Another Pointer Problem Set 

http://clc-wiki.net/wiki/C_standard_library:string.h

![clibrary]( http://j.mp/pointerProblems)

--->
