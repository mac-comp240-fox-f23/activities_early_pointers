# Activity 3: Program Memory, Pointers, Malloc

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


## A library of functions

The files called `string_funcs.h` and `string_funcs.c` comprise a small
*library* of functions. This is a common way of organizing a C program; related
functions are separated into their own file. Similar to standard C libraries
provided by the language, the functions in this file can be used in other code
files. The header file (with the extension `.h`) declares the "interface" to the
library: what functions and constants are provided by the library. The code 
file (with the extension `.c`) defines the functions and constants.

**Open `string_funcs.h` and `string_funcs.c` to see what they contain.**


### To use a user-defined libraryr

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
- Add your name in a comment at the top of each file you edit! (Good practice
for homework where you will lose points if it is not there) 


### Task 1: A simple "sales tax" example

- Look for the definition of the `sales_example` function in `activity2.c`. 
- Note how the function takes in 3 inputs: the cost per item, the number of 
items, and the sales tax rate.
- In the function, do the following:
    - Declare and define a variable to hold the total pre-tax amount to be paid 
    (cost times number)
    - Declare and define a variable to hold the total cost after incorporating 
    sales tax
    - Add an `if` statement to check if the sales tax rate is 0.0; it should 
    print a message that no sales tax applies if this is the case
    - Regardless of the outcome of the `if` statement, return the total cost 
    calculated
- Examine the call to `sales_example` in `main`; compile and run the program, 
checking that the output is correct
- Try a range of other values to ensure the correct result is returned each time
- Incorporate the `assert` statement to automatically check for correct results,
testing at least 4 different scenarios

### Task 2: Experimenting with loops

- Near the top of the file, add a declaration of a function called 
`loop_example` that returns nothing and that has no input parameters
- In the main function, add a call to your new function
- In the space provided below the main function, put in your definition of 
`loop_example`
    - First, write a simple `for` loop that loops over the integers from 10 to 
    25, going up by 5 each time, and it prints the integer and the square of the 
    integer each time
    - Next, add a `while` loop that does the same thing
    - Finally, add a `do-while` loop that does the same thing


### Task 3: Exploring sizes and ranges for unsigned integer types

- Read the starter code for the `utype_sizes` function: it prints a constant 
from the `limits.h` library for the maximum value of 
the `unsigned char` integer type, and it prints the number of bytes used by an 
`unsigned char`
- Using the resources listed in the References section below, research how to 
display a value of each of the three additional types we are examining: 
`unsigned short`, `unsigned int`, and `unsigned long`
- Also research the min/max constants provided by the `limist.h` library
- Add print statements for the three additional types, printing the
maximum value for that type, and its number of bytes

**Edit the table below to record the values you found!**

| Type              | Max value  | Number Bytes |
| :-------------:   | :-------:  | :----------: |
| `unsigned char`   |            |              |
| `unsigned short`  |            |              |
| `unsigned int`    |            |              |
| `unsigned long`   |            |              |


### Task 4: Exploring sizes and ranges for signed integer types
- Near the top of the file, add a declaration for `stype_sizes`
- In the `main` function, add a call to `stype_sizes`
- In the space below `main`, add a definition of `stype_sizes`
    - Base this on `utype_sizes`: four print statements
    - Include the minimum as well as the maximum in each print statement
    - Research the different codes needed for signed integers

**Edit the table below to record the values you found!**

| Type     | Min value  | Max value  | Number Bytes |
| :----:   | :--------: | :--------: | :----------: |
| `char`   |            |            |              |
| `short`  |            |            |              |
| `int`    |            |            |              |
| `long`   |            |            |              |


### Notes 

- The macro `sizeof(TYPE)` returns the number of bytes used for a particular
  data type by the compiler on the particular hardware where the program is
  compiled and run. The `%zu` code is used to print the result of `sizeof`!

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
- Printf formatting codes
  - [printf format specifier reference from cplusplus.com](http://www.cplusplus.com/reference/cstdio/printf/).
  [_Format Specifiers in C_](https://www.thecrazyprogrammer.com/2016/10/format-specifiers-c.html) by The Crazy Programmer
  - [_C Programming/limits.h](https://en.wikibooks.org/wiki/C_Programming/limits.h)
  - [limits.h reference in tutorialspoint](https://www.tutorialspoint.com/c_standard_library/limits_h.htm)
