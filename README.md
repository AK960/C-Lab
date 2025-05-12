# C-Lab 
This repository contains notes and exercise code to learn c. The readme serves as a cheat sheet for theory and language specifications. 

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
```c++
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


## Notes
### C Fundamentals
#### 1. Intro
Language consists of two parts:
- Language core (=Sprachkern): contains instructions, key words, builtin data types, i.e., brackets, control structures, etc.
- Standard libraries: can be added when needed to implement functions like input and output, memory management, etc. 
Structure of standard libraries is often abstracted for the user/developer:
- Header files (.h): declares functions and datatypes. Naming is usually normed by a standard. Popular ones are i.e., <stdio.h> for input/output (like printf()), or <stdlib.h> for fundamental standard functions. 
- Program library: defines the declared functions and datatypes. Their implementation can vary.  
To create an executable file from a c-sourcecode file, one must compile the sourcecode with a compiler to create an object file .o and consequently link the object files with a linker to create an executable program.

#### 2. First Steps
- The # is a sign for the preprocessor, which is part of the compiler (program that runs before the compiler does), that it must include to following standard libraries. 
- The main() function is the entry point for every executable program. The void states that is an empty data type which states that the function does not have parameters. 
- Identifiers (=Bezeichner) can only start with _ or characters.
- Literals (=Literale/Werte) can be decimal, hexadecimal, octal, characters, strings (arraay of characters) etc.

#### 3. Data Types
- A variable is an address in main memory, where the data is stored and can be accessed.
- To only declare a variable use the term "extern"
    - extern int myVar; declares a variable in one file and does not reserve memory for it yet
    - The definition can be performed in another module, where the compiler will reserve memory
- A variable that is only declared contains a random value (undefined)
- The term "unsigned" moves the value space to the right (no more negative values for int i.e.)
- Elementary datatypes, see [here](https://www.servervoice.de/c-6-elementare-datentypen/)

#### 4. Calculating with Operators
- Function scanf expects the address to a variable, thus use scanf("%d", &myVar)

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

