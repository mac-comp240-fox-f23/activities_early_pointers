# Activity 3: Program Memory, Pointers, Malloc

## Put name here

Folder: `activities_early_pointers`

This is an introduction to:
* C pointers: what they are and how they are used
* Dynamic allocation of memory, stored in the program heap

You will explore different kinds of pointers, and their uses in functions,
and to represent arrays and strings:
- You will draw diagrams to show the program stack and heap when regular data
and pointers are passed to functions
- You will experiment with functions that use "pass-by-pointer" to change
data passed to them
- You will create functions to modify strings using the "pass-by-pointer" 
approach
	
**Hint:** At the bottom of this README is a section called References that 
contains references to resources that can help you with these questions

## Provided Code

There are two code files, one header file, and a Makefile for this activity:

- `activity3.c`
    - the main source file with three tasks defined in it
- `string_funcs.c`
    - a library file containing string manipulation functions
- `string_funcs.h`
    - a header file used to include declarations of the library functions into
the other code file
- `Makefile`
    - a short makefile to automate the compilation process


### A library of functions

The files called `string_funcs.h` and `string_funcs.c` comprise a small
*library* of functions. This is a common way of organizing a C program; related
functions are separated into their own file. Similar to standard C libraries
provided by the language, the functions in this file can be used in other code
files. The header file (with the extension `.h`) declares the "interface" to the
library: what functions and constants are provided by the library. The code 
file (with the extension `.c`) defines the functions and constants.

**Open `string_funcs.h` and `string_funcs.c` to see what they contain.**


### To use a user-defined library

**Open at `activity3.c` and note this line near the beginning of the file:**

	#include "string_funcs.h"

This enables the code file to use the functions declared in `string_funcs.h`.

Notice that it has declarations of functions at the top of the file, followed 
by the main program, and then the function definitions 
themseles. There are "TODO" comments in the file to help guide you in this 
activity.

**Open the file `Makefile` and read it carefully.**

Recall that the Makefile defines how we compile our source code into an 
executable program, automating the process for us.

- New this time: multiple code files!
    - Notice that both code files are listed as dependencies; if either file
is changed then the code will be recompiled
    - The compile line includes both `.c` files: this combines them into one
program
    - We could include the header file as a dependency, it is sometimes done


## Your tasks

### First Steps
- Add your name(s) in a comment at the top of each file you edit! (Good practice
for homework where you will lose points if it is not there)
- Also, add your name(s) to this README document: Some of you have Github usernames that
are very different from your actual names. This makes it easier to know quickly who is who!


### Task 1: Passing data by value versus passing data by pointer

This task is based on an exercise in _Dive into Systems_. Here you will read,
understand, and experiment with code that passes integers to a function directly,
and through a pointer.

- Look for the `task1`  and `arg_modifier` definitions and read them carefully
- Uncomment the call in `main` to `task1`
- Compile the program using `make` in the terminal, and run it
- Examine the outputs: do they make sense to you?
- Using the diagram in Figure 1 of Section 2.3 in _Dive into Systems_ as a model,
draw a diagram that shows the program stack (including the call to `main`, 
`task1`, and `arg_modifier`) 
    - Show the parameter and local variables for each
function, and their values. 
    - Show the state of the program stack at the point in `arg_modifier` right 
before the `return` statement

**Take a picture of your diagram, and include it here in the README**

(In the references below is a link to a document that can help you to include
images in Github README files)

### Task 2: Pointers for arrays and dynamic allocation

For this task you will explore an example that creates a statically-declared
array of integers, and a dynamically-created array of integers. You will see
two methods we can use to access or update an array: typical array-indexing
notation, and pointer arithmetic notation.

- Look for the `task2`, and `init_array` definitions and read
them carefully
    - Note that `init_array` includes three different approaches to working
    with an array where we have a pointer to the start
    - Try each of these in turn: discuss how each works until you understand
- Change `main` to run `task2`, and compile and run the program
- Draw a diagram similar to Figure 3 in Section 2.4, showing the state of
the stack and heap at a point just before `init_array` ends.

**Take a picture of your second diagram, and include it here in the README**

**Optional experiments:** What happens if you violate the boundaries of the 
arrays and try to read or write to positions beyond what is allocated? 

### Task 3: Manipulating strings as pointers

Here you will move beyond reading and understanding code to writing your own! 
This task also introduces the "library" style of programming, which we will use
in the future. The file `string_funcs.c` contains a set of function definitions
that operate on strings (these are all similar to built-in string operations C
provides). We separate them into their own file, and use a header file to 
declare them within the main code file.

The library contains the following functions:
- `array_strcpy(s, t)`: A function that concatenates the string t to the end of s
(using string indexing operators)
- `ptr_strcpy(s, t)`: A function that concatenates the string t to the end of s
(using pointer arithmetic)
- `my_strncpy(s, t, n)`: A function that copies at most the first n characters 
of t to s 
- `my_strcat(s, t)`: A function that adds the contents of t to the end of s

The starter code in `string_funcs.c` contains full definitions for `array_strcat`
and `ptr_strcpy` to illustrate two possible approaches to these problems. 

**Your tasks:**
- Implement `my_strncpy` 
- Implement `my_strcat`
- Add test calls to `task3` to test your new functions carefully

**Important notes:** 
- All of these functions are real string manipulation functions in C, in the `string.h` library. 
   - Don't use those definitions in implementing these functions, the point is for
you to practice the underlying basic operations
   - Even in the `string.h` library itself, many of these operations are 
incredibly insecure! Don't use them carelessly!
- Remember, a character array have more capacity allocated than it currenty uses
- The end of the current contents is a zero (`'\0'`), and you must allocate room
for that extra character when allocating the string
- The strcpy implementations both rely on a C "trick:" assignment statements
in C are _expressions_ whose value is the value stored in the left hand variable
   - `(x = 10)` is an expression whose value is `10`
   - `x = (y = 3)` is perfectly valid: both `x` and `y` will be set to 3
   - `(x = y - 3) > 0` is a boolean expression that sets `x` to be `y - 3` and
   then evaluates to true (`1` in C) if the value of `x` is greater than 0

The `ptr_strcpy` function has two versions: the explicit version 
(uncommented) and simplified version (commented out). 
**For an optional challenge, write simplified solutions for each of your functions!**


### Feeling stuck or confused?

Ask for help right away from neighbors, preceptors, or instructor!


### Commenting as documentation

You should comment each function you write like you would for Java:

	/** Describe inputs and return values and 
	 * what the function does -- this comment
	 * must start with /**, just like 
	 * javadoc comments
	 */

## References

- Help with Markdown in Github
  - [Basic writing and formatting syntax](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
- Makefile guides
  - [An Introduction to Makefiles](https://www.gnu.org/software/make/manual/html_node/Introduction.html), by GNU
  - [Makefile Tutorials and Examples to Build From](https://earthly.dev/blog/make-tutorial/), by Aniket Bhattacharyea
  - [makefile basics - anthony explains](https://www.youtube.com/watch?v=20GC9mYoFGs)
- General C syntax help
  - [Chapter 1 of _Dive into Systems_](https://diveintosystems.org/book/C1-C_intro/index.html)
  - _The C Programming Language_, often just known as K&R for Kernighan and Ritchie
  - _C: A Reference Manual_, by Harbitson and Steele
- The `assert` statement
  - [assert reference from cplusplus.com](https://cplusplus.com/reference/cassert/assert/?kw=assert)
