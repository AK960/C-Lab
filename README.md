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
- [ ] [Part 1](https://www.youtube.com/watch?v=zUAKckUxm2Q&ab_channel=TDT4186_21)
- [ ] [Part 2](https://www.youtube.com/watch?v=rKv-SYBHubM&ab_channel=TDT4186_21)
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
  - <dataType xmlns=""> <functionName> [noElements] // only elements of the same type possible
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
  - When using scanf to read char arrays, there is no need for the &someVar convention as with integer or char values,
  as a char array already is a pointer to the beginning of the string!
  - char *fgets (char *str, int n_chars, FILE *stream)
```c
char myVar[30];
scanf("%25s", myVar); // Option 1
fgets(myVar, sizeof(myVar), stdin); // Option 2
```
- Functions to work with strings are inherent in the <string.h> library (see documentation)
#### 10. Pointer
##### Basics
A pointer represents the address and the type of a storage object 
- Use case:
  - Dynamic memory allocation, administration, releasing during runtime 
  - Passing objects, functions, arrays, etc. to functions by referencing their memory address
  - Implementing lists / trees / other complex data structures
  - Typeless pointer void* to process data objects of arbitrary type
- Declaration:
  - <data_type> *name; 
  - // The name is the identifier and is declared as the pointer on an object of type "data_type"
  - When declaring a pointer, remember visibility in blocks / funcitons - if not declared properly when
    being called, it refers to a random address in memory
  - Pointes within a block have a random address without initialisatioin whereas global and static pointers
    are initialized implicitly as NULL-pointers without prior manual initialisation
    - To avoid segmentation fault, always initialize pointers as NULL when not used immediately 
```c
int *iptr; // int pointer
int ival = 255; // int variable
iptr = &ival; // passing address of variable to pointer with address operator "&"
```
- To print pointer-addresses in hex format, use %p
- Type transformation:
  - manipulating the type of a pointer, i.e.:
```c
char *bytePtr;
float fval = 255.255;
bytePtr = (char *)&fval;
```
  - Now, a char-pointer points on the first byte of the storage object fval, which could now be manipulated bytewise
- Accessing pointer content:
  - With * we can access the value that a pointer stores -> "dereferencing"
    - Values of a pointer can be accessd or manipulated by dereferencing
##### Pointers as Parameters
When calling conventional functions, parameters would be copied such that they where available to functions as local
variables. Alternatively, we could pass addresses to objects instead of a copy:
```c
void reset (int *val) {
    *val = 0;
}

int main (void) {
  int ival = 128;
  int *iptr = &ival;
  reset(iptr); // same as reset(&ival)
  
  return 0;
}
```
##### Pointers as Return Values
A pointer can also be declared as a return value of a function, however: when calling a function, 
parameters are copied to the stack frame and every operation a function performs happend here, once
finished, the storage is released. Thus, when operations are performed and a pointer / an address is
returned, this points to an undefined memory area. Thus, when we want to return a valid memory area,
there are three options: We can use
- Static or global storage
- A memory or addresse passed as an argument when calling the function
- A memory reserved at runtime using malloc() // more later
```c
// Static example, malloc() usually better => more later
int* ifget (void) {
static int buffer[5] = { 1, 2, 3, 4, 5};
```
##### Pointer Arithmetics
Means the access of pointers without indirectionoperator * and thus the usage of operations for 
pointers and not their values / objects they dereference (often used with c-arrays)
- Comparisons with usual operators (true i.e., when one address is larger than the other). Often used
to determine whether a pointer is a null pointer
- Subtraction returns the number of elements between two pointers (use %ld)
- Addition / subtraction of a pointer with an integer to in-/decrement them, i.e., to point on different
array elements
  - Can be used to access different array elements. For this, array and pointer must be of same type,
    such that a increment operation adds the correct number of bytes to the pointer 
##### Arrays and pointer as parameters
- Arrays are passed to functions as addresses (address of first element) + their length
```c
void modArr (int arr[], size i);
void modArr (int *arr, size i);
void modArr (const int *arr, size i); // array cannot be manipulated
```
- By passing address, function gets access to original element (no copy) and can manipulate it
  - with the const parameter, the manipulation of an array can be mitigated --> best practice
##### Char-Arrays and Pointers
- Work the same as numeric arrays with the exception that when initializing an array in with the
pointer notation, the array that this pointer represents, can be altered and be assigned a different
array:
```c
char str[] = "hallo";
char *ptr = "welt";
ptr = str; // pointer now points on &str[0]
```
##### Pointer Arrays
- Can be used as substitude for 2D-arrays, especially for 2D-char-arrays, to mitigate flexibility
and memory waste limitations (dynamically adding/removing elements, reserving too much space)
- Such an array does not store the values itself but rather the pointers to these elements/objects
```c
char *words[] = {"ich", "bin", "ein", "pointer", "array"};
printf("Wort: %s", words[0]); 
// in words[0] steht die Addresse zu array {"ich"} bzw. zum "i"
```
##### Void Pointer
- Void pointer can be used to assign addresses, where the use case / datatype is not yet known 
  - I.e., instead of writing a function for every datatype, we can just write a universal one with
    a void pointer
```c
void *malloc (size t);
float *fval = malloc(100 * sizeof(float))
int *ival = malloc(34 * sizeof(int))
```
##### Type Qualifiers for Pointers
- Const pointer: When declaring a pointer as const, the address cannot be changed anymore. Yet, the object 
it dereferences can be manipulated (int* const pointer = &iarr[0])
- Pointer for const data: Const data cannot be manipulated using the pointer, pointer is for reading
only (int const *pointer = &iarr[0]) 
- Const pointer for const data: not possible to manipulate either pointer nor data, it's read only
(int const * const pointer = &iarr[0])
- Const parameters for functions: Not possible to perform write operation on the passed parameter
during function execution
- Restrict pointer: Operation on an element/object is exclusively restricet to this declared pointer.
Accessing it with other pointers is not possible. 
```c
int * const pointer = &iarr[0] // const pointer
int const *pointer = &iarr[1] // data that pointer dereferences is constant
int const * const pointer = &iarr[2] // both constant, can only be used for reading
int printf (const char* restrict word, ...); // not possible to manipulate "word" during execution
int* restrict pointer = malloc(10 * sizeof(int)); // allocated memory can only be accessed with this pointer
```
##### Pointer on Functions
- Pointers to functions dereference the start address of the code of a function. This pointer can be adjusted throughout
execution and point to diffenent functions and is thus specifically useful for event-driven systems, callback-based
APIs, etc. - it is useful when we want to exchange different functions without changing the remaining code. It is
like an universal adapter that can use different tools but operates them in the same way.
- Declaration:
  - returnType (*functionPointer)(formalParams)
    - This declaration is a pointer to a function type with >= 1 parameter(s) and a return type
    - *functionPointer must be in ()!
    - Name of the function is transformed implicitly into a pointer to that function
    - The function can be called by 
      - (*functionPointer)(formalParams)
      - functionPointer(formalParams)
```c
void verarbeiteArray(int arr[], int groesse, void (*verarbeitung)(int)) {
  for(int i = 0; i < groesse; i++) {
    verarbeitung(arr[i]);
  }
}

void verdoppeln(int x) {
  printf("%d ", x * 2);
}

void quadrieren(int x) {
  printf("%d ", x * x);
}

int main() {
  int zahlen[] = {1, 2, 3, 4};

  printf("Verdoppelte Werte: ");
  verarbeiteArray(zahlen, 4, verdoppeln);  // Ausgabe: 2 4 6 8
    
  printf("\nQuadrierte Werte: ");
  verarbeiteArray(zahlen, 4, quadrieren);  // Ausgabe: 1 4 9 16
    
  return 0;
}
```

#### 11. Dynamic Memory Management
- The dynamic memory management in c is realized with pointers and functions from <stdlib.h>
- This has pitfalls: 
  - Could access undefined addresses in memory
  - Memory must be reserved and released or memory leaks can occur
- The dynamic memory that we can access during runtime is called Heap
  - When requesting storage, it is always contiguous memory
##### Requesting Memory
- malloc() requests memory of size "size" in bytes. A typeless void pointer with the first address of the memory
block is returned. I no contiguous memory block of size "size" could be reserved, function returns NULL
  - void* malloc(size_t size);
- calloc() requests contiguous memory of size "size" in bytes and initialises the allocated memory with 0.
  - void* calloc(size_t count, size_t size);
    - We reserve count * size bytes of memory
    - A typeless pointer to starting address is returned
- realloc() can adjust (increase/decrease) the memory that was requested earlier with malloc/calloc. The content
of the previous memory block stays consistent and the new memory is attached to the end - if this is not possible, 
the function copies everything to a new memory block. We always pass the target size to realloc, if it is smaller, 
the memory will be decreased. To decrease, we must include the actual size. 
  - void* realloc(void* ptr, size_t size);
##### Releasing Memory
- When we requested memory from heap, we must release it manually after execution to avoid memory overflow
  - void free(void* ptr); 
  - A memory leak emerges when the address of an allocated memory gets lost and the allocated storage can neither
    be used nor released

#### 12. Complex Data Types
In C we can create specially defined data types from a Structure (struct), a Union (union), and an Enumeration (enum).
With typedef we can create aliases for existing data types or names of an aggregated data type.
##### Structures
With structures, we can define our own types by combining properties of objects and single values - called records.
Each record consists of properties and values. The properties are the structural elements of a record / struct.
- Declaration: 
  - struct [identifier1] {list_of_components} [identifier2]; // functions not allowed as members (components)
- Definition: 
  - struct [identifier] component1, component2, ... ;
- Declaration & Definition:
```c
struct myPerson {
  char firstname[20];
  char lastname[20];
} myPerson1, myPerson2; // Instances of myStruct (Strukturvariablen), e.g., two persons
```
- Synonyms for struct types:
```c
typedef struct myPerson Person; // alias for myStruct to avoid writing struct keyword everytime
struct myPerson akl; 
Person akl; // same as above 

typedef struct Example {
  char title[20];
  char artist[10];
} Artist; // also declares an alias
```
- Access of components: either by point (.) or arrow (->) operator
```c
Person akl; // definition of instance "akl" of type struct myPerson resp. Person
akl.firstname = "Alexander"; // writing elements to components resp. values to properties
akl.lastname = "Kleinwächter";
```