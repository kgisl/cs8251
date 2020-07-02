# Pointer Camp

**tl;dr**   Pointers are _nothing more than memory addresses_, or that they allow you to point to _arbitrary locations_.

Send your feedback using [![Say Thanks!](https://img.shields.io/badge/Say%20Thanks-!-1EAEDB.svg)](https://saythanks.io/to/lifebalance@gmail.com)

http://j.mp/pointKITE  - the problem set that can be used for a 20-hour workshop for Quick, Deep, Immersive and Perceptual Learning of **Indirection** (aka Pointers) - the most important **Threshold Concept** in programming. Arguably, this is the largest and progressively challenging problem set (PC-P) that is relevant for learning, teaching and assessment of knowledge/competency in pointers. 

  - Totally new to Pointers? First go update yourself at http://j.mp/pointerGlossary


## _...but why?_ 
_"...and flight software itself... is written in C/C++" - take a look at [j.mp/linuxFalcon](http://j.mp/linuxFalcon)!_


- Know ***what*** to practice
	- to get better at execution, practice the same problems repeatedly over time.

- _For some reason most people seem to be born without the part of the brain that understands pointers. This is an aptitude thing, not a skill thing – it requires a complex form of doubly-indirected **thinking** that some people just can't do._ - **Joel Spolsky** (Founder, Stackoverflow.com)

- Hot and trending languages (since 2018) like Golang and Rust are becoming popular for various reasons. Both use and implement pointer concepts. 
	- “For beginners, this may slightly be difficult to learn because Go relies heavily on pointers which may not be easy to grasp as a new programmer.” — @timcodestoo https://medium.com/p/3-programming-languages-to-learn-in-2019-2eb035936f65

- One of the most practical use cases for pointers 
    - Three concepts - Functions from Unit_3(`fread`, `fwrite`, etc), structures from Unit_4 ([opaque][opaque] `FILE` typedef for`struct _iobuf`) and pointers from Unit_3 (FILE *)  come together to accomplish file processing ([Unit_5](http://j.mp/unit5Easy))
	- Review http://j.mp/fileChallenge - can you quickly write up a C code for the challenge? 


[opaque]: http://j.mp/opaqueC 

# - String based (44)
A null-terminated byte string (NTBS) is a sequence of nonzero bytes followed by a byte with value **`zero`** (the terminating null character). Each byte in a byte string encodes one character of some character set. For example, the character array `{'\x63','\x61','\x74','\0'}` is an **NTBS** holding the string **"cat"** in ASCII encoding.

## String examination  (29)
_What is inside the string? Is the needle present in the haystack?_
- [strchar](http://j.mp/stringCharCC) and [strrchar](http://j.mp/stringrcharCC),  [strichr](http://j.mp/stringicharCC) and [strrichar](http://j.mp/stringiRcharCC),
- [strlen](http://j.mp/stringLenCC), [mystrlen](http://j.mp/strlenCC) and [vowel counting](https://j.mp/vowelsCC)
- [have_no_fives](http://j.mp/haveNoFive)  and 
- [count_occurrences](http://j.mp/countCC), [unique_chars](http://j.mp/uniqueCC) and
- [find_earliest](https://bit.ly/findEarlyCC),  [has_duplicates](http://j.mp/countDuplicates) 

--- BREAK  _here_ (try **strlower**)  
- [subset](http://j.mp/subSetCC),  
- [subsequence](http://j.mp/subSeqCC),  
- [vowels in order](http://j.mp/vowelsOrderCC)  
- [strstr](http://j.mp/stringStrCC) and [strstrw](http://j.mp/strstrwrapCC), 
- [strend](http://j.mp/stringEndCC), 
- [strcmp](http://j.mp/strcmpCC) and [strncmp](http://j.mp/stringncompareCC)
- strend (_take  2_)

--- BREAK  _here_

- [strpbrk](http://j.mp/strpbrkCC), 
- [strcspn](http://j.mp/stringcspnCC), 
- [strspn](http://j.mp/stringspnCC), 
- [strtok](http://j.mp/strTokenizeCC)

--- *BREAK here*
- [pangram](http://j.mp/panGramCC) and [partial](http://j.mp/pangramCC), 
 - [isogram](http://j.mp/isogramCC) and [higher](http://j.mp/multipleIsogramCC)
- [anagram](http://j.mp/anagramCC)
- [word count](http://j.mp/wordcountCC)


## String manipulation (9)
_How can I change the contents inside a string?_ 
- [strlower](http://j.mp/strToLowerCC) and [strupper](http://j.mp/strToUpperCC)
- [strflipcase](http://j.mp/stringflipcaseCC)
-- BREAK _here_ 
- [strcpy](http://j.mp/stringcopyCC) and [strncpy](http://j.mp/stringNcopyCC),
- [strcat](http://j.mp/stringCatCC) and [strncat](http://j.mp/strncatCC),
- [strrev](http://j.mp/reverseCC)
- [memorymove](http://j.mp/memmoveCC)

## String allocation (dynamic memory) (6)
_How do I generate new strings from existing ones?_
- [subString](http://j.mp/substringCC), 
- [indexOf](http://j.mp/indexCC),
- [abbreviate](http://j.mp/acronymCC) (exercism and CapGemini), 
- [replaceString](http://j.mp/replaceCC),
- [binaryAdd](http://j.mp/binaryaddCC) (CapGemini), 
  
# - Array Manipulation  (3)
- [alphabets](https://cloudcoder.kgkite.ac.in/cloudcoder/#exercise?c=33,p=1208) 
- [day_of_year](http://j.mp/dayYearCC)  - multidimensional array 1
- [matrixUpdate](http://j.mp/arrayPointer) - multidimensional array 2

# - Function Parameters (5)
- [pointerWalk](http://j.mp/pointerWalk)
- [add_one](http://cloudcoder.kgkite.ac.in/cloudcoder/#exercise?c=33,p=967) 
- [swap](http://j.mp/swapNumbers) 
- [doubleSwap](http://j.mp/doubleSwap)
- [palindrome](http://j.mp/dPalindromeKG) using double pointers

# - Function Pointer (2)
  - [string sorter](https://j.mp/stringSortCC)
  - [case selector](http://j.mp/funcPointerCC)


# - PDS-1 Practice (8)
  - cs8251 - C Programming 
	  - [insert_after](https://j.mp/singleLL)
	  - [selection_sort](https://j.mp/selectSortLL)
	  
  - Lab 3
	 - [connect](http://bit.ly/connectDLL), [traverse](http://j.mp/traverseDLL), [getnode](http://j.mp/tailCC) and 
[insertBefore](https://bit.ly/insertLinkCC)
     - [Rotate List](http://j.mp/airbnbCC)
	 - [Doubly-Linked List](http://j.mp/doublyLinkedCC)
       - Processing strings as linked lists [TBD]
  - Lab 6 
    - [Fixed Array based Stack](https://bit.ly/arrayStack)
      - [PostFix Eval](bit.ly/postfixCC),  [PostFix to Infix](http://j.mp/infixPostfix)
      - [Bracket Matching](http://j.mp/bracketKG)
    - [Linked List based Stack](http://bit.ly/linkedStack)
    - [Linked List based Queue](https://bit.ly/linkedQueue)





<!---
## Another Pointer Problem Set 

http://clc-wiki.net/wiki/C_standard_library:string.h

![clibrary]( http://j.mp/pointerProblems)

--->
