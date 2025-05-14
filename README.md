# C-Lab 
This repository contains notes and exercise code to learn c. The readme serves as a cheat sheet for theory and language 
specifications. 

## Basic Syntax
### Control Structures
```c
// In C, condition is integer (not boolean)
if (condition) { ... } else { ... }
while (condition) { ... }
do { ... } while (condition);
for (...; condition; ...) { ... }
continue; // starts the loop again at the beginning
break; // terminates the loop
```
### Structures (structs)
There are no classes in C; however, there are complex data typed called structs. Struct parameters are also passed by
value.
```c
struct student {
  int student_id;
  int age;
  char name[64];
};

void rejuvenate (struct student s) {
    s.age = 0;
}

void foo() {
  struct student s1;
  s1.age = 20;
  rejuvenate(s1); // Will not change the age
}  
```
## Linux Commands
```sh
# rename file
mv <old_name> <new_name>

```

## C Crash Course
- [ ] (Part 1)[https://www.youtube.com/watch?v=zUAKckUxm2Q&ab_channel=TDT4186_21]
- [ ] (Part 2)[https://www.youtube.com/watch?v=rKv-SYBHubM&ab_channel=TDT4186_21]
### From Source Code to binary

### Programming paradigms
- C is an imperative programming language
  - Program consists of a sequence of commands / conditions / loops.
  - special case of imperative: procedural programming
    - Split codes into smaller chunks which are easier to manage and write
    - Program is split into smaller parts, called functions / procedures
- C++ is an object-oriented programming language that abstracts code and data such that they are encapsulated. A 
program is a set of objects interacting via interfaces.
- Focus: Imperative & procedural programming
- A language is not necessarily fixed to a paradigm but rather supports different styles

### Functions vs. Methods
- Functions (imperative) 
  - Are declared and defined in a global scope (no nesting of local functions in global functions)
  - Are not part of a class
  - Do not provide "this"-operator
  - By forward declaration, the compiler can be told that the definition of a function is following its call from
  another location
- Methods (object-oriented) 

## Sources
- [ ] Compiling C files with gcc, step by step: [click here](https://medium.com/@laura.derohan/compiling-c-files-with-gcc-step-by-step-8e78318052)

## Notes
### C Fundamentals
#### 1. Intro
Language consists of two parts:
- Language core (=Sprachkern): contains instructions, key words, builtin data types, i.e., brackets, control structures, 
etc.
- Standard libraries: can be added when needed to implement functions like input and output, memory management, etc. 
Structure of standard libraries is often abstracted for the user/developer:
- Header files (.h): declares functions and datatypes. Naming is usually normed by a standard. Popular ones are i.e., 
<stdio.h> for input/output (like printf()), or <stdlib.h> for fundamental standard functions. 
- Program library: defines the declared functions and datatypes. Their implementation can vary.  
To create an executable file from a c-sourcecode file, one must compile the sourcecode with a compiler to create an 
object file .o and consequently link the object files with a linker to create an executable program.

#### 2. First Steps
- The # is a sign for the preprocessor, which is part of the compiler (program that runs before the compiler does), 
that it must include to following standard libraries. 
- The main() function is the entry point for every executable program. The void states that is an empty data type which 
states that the function does not have parameters. 
- Identifiers (=Bezeichner) can only start with _ or characters.
- Literals (=Literale/Werte) can be decimal, hexadecimal, octal, characters, strings (arraay of characters) etc.

#### 3. Data Types
- A variable is an address in main memory, where the data is stored and can be accessed.
- To only declare a variable use the term "extern"
    - extern int myVar; declares a variable in one file and does not reserve memory for it yet
    - The definition can be performed in another module, where the compiler will reserve memory
- A variable that is only declared contains a random value (undefined)
- The term "unsigned" moves the value space to the right (no more negative values for int i.e.)
- Sizeof different datatypes:
  - Special case: sizeof returns unsigned long and has format sign %lu

| Data Type   | Sizeof (Bytes) | Range (numeric)                 | Format Sign         |
|-------------|----------------|---------------------------------|---------------------|
| signed char | 1              | [-128; 127]                     | %c resp. %s         |
| short       | 2              | [-32768; 32767]                 | %hd / %hi           |
| int         | 4              | [-32768; 32767]                 | %i / $d             |
| long        | 8              | [-2.147.483.648; 2.147.483.647] | %ld / %li           |
| float       | 4              | [-3,4*10⁻³⁸; 3,4-10³⁸]          | both: %f, %e, %E,   |
| double      | 8              | [-1,7*10⁻³⁰⁸; 1,7*10³⁰⁸]        | %g, %G, %.2f, %8.2f |

- Elementary datatypes, see [here](https://www.servervoice.de/c-6-elementare-datentypen/)

#### 4. Calculating with Operators
- Function scanf expects the address to a variable, thus use scanf("%d", &myVar)

#### 5. Conditionals
- Conditional operator ? can be used instead of if else statement: 
  - (Condition) ? Expression (condition is true) : Expression (else)
- Conditions can be concatenated with || (logical or) or && (logical and)
  - when including <iso646.h> can use "and" and "or" instead
- Multiple branches with switch case statement:
```c
switch (expression) {
  case expression_1: 
    instruction_1;
    break;
  case expression_n:
    instruction_n;
    break;
  default:
    default_expression;
}
```
  - if i.e. case 1 does not contain a break, all conditions until the first break are executed
  - if i.e. condition 3 is empty and 4 contains a break, both execute the same instruction

#### 6. Loops
- Controlled exit from loops with following keywords:
  - break; terminates the loop, can i.e. end an endless loop when a condition is met
  - continue; skip the rest of the loop iteration and jump to the next one, can sometimes be simplified by i.e.
  using other operators such as != in conditions

#### 7. Functions
- Syntax:
  - [specifier] <dataType> <functionName> ([parameter(s)]) { ... instructions ... }
    - specifier: optional storage class specifier
    - parameters can also be empty or void
- The compiler reads a file sequentially from top to bottom. To make sure the pre-processor finds all functions it
is good practice to declare them in the beginning so the compiler knows that there will be a definition somewhere in
the file. This is called pre-declaration (=Vorausdeklaration).
- Functions return either values created during the process or exit codes indicating errors or success
- When a function is called, memory is reserved for it on the stack where variables and data will be safed, but also
the return address to the caller. When a function is being terminated with return, the data on the stack is released
again. When the function returns a pointer, this will point to a memory area that is not defined anymore because it
was released.
- A recursive function calls itself within its instruction block:
```c
long fakul (long n) {
  if (n != 0) {
    return n * (fakul (n - 1));
  }
} // Calculates 4 * 3 * 2 * 1 and returns that value

int main (void) {
  fakul(4); 
  return 0;
}
```
- Functions can be exited with exit(); using i.e. the EXIT_FAILURE from <stdlib.h> as a parameter
- Variables can be declared static, it receives a fixed memory address in the stack and stays alive during runtime
  - Locally: when returning function, variable stays but can only be called from the function it was defined in
  - Globally: Behaves like a global variable (see 7_functions.c)
  - Functions can also be static and consequently only be called from within the file, not from other program files

#### 8. Pre-processor
For including header files there are two conventions:
- #include <headerFile.h> // searches in the implementation-defined path where other compiler headerfiles are
- #include "headerFile.h" // searches in working directory and defaults to the implementation-defined path

#### 9. Arrays
- Syntax:
  - <dataType> <functionName> [noElements] // only elements of the same type possible
- When declaring the array, memory of length * sizeof(dataType) is reserved
##### Passing Arrays to functions
- Arrays are stored sequentially in memory
- To pass an array to a function, we need the address (pointer) of the first element and the length
##### Numeric
- Initialization 
```c
int arrayEmp[3]; // not defined, random values
int arrayFix[3] = { 1, 2, 4 }; // Array with 3 values
int arrayVar[] = { 0, 2, 4, 8 }; // Array with 4 values
int arrayMan[2];
arrayMan[0] = 1;
arrayMan[1] = 2;
```
##### Char
A char array that safes a string needs another space for the "\0" sign, which is crucial for string processing
operations! 
- Initialization
```c
char string[] = "String!";
char string[] = {'S', 't', 'r', 'i', 'n', 'g', '!', '\0}
// Important - not the same!
char ch = 'X'; // Num constant with one sign, can be interpreted as numeric
char ch[] = "X"; // String constant with two signs, X and \0
```
- Reading strings with scanf or fgets
  - When using scanf to read char arrays there is no need for the &someVar convention as with integer or char values,
  as a char array already is a pointer to the beginning of the string!
  - char *fgets (char *str, int n_chars, FILE *stream)
```c
char myVar[30];
scanf("%25s", myVar); // Option 1
fgets(myVar, sizeof(myVar), stdin); // Option 2

```
- Functions to work with strings are inherent in the <string.h> library (see documentation)