#include <stdio.h>
#include <stdlib.h>

void Forward (int a, int b, void (*function)(int, int)) { // (2) Third parameter takes a function pointer
    function(a, b); // (3) The value of the pointer "function" is the function "add"
}

void add (int a, int b) {
    printf("[Add] Result = %d\n", a + b);
}

void mult (int a, int b) {
    printf("[Add] Result = %d\n", a * b);
}


int main (void) {
    int a = 3, b = 4;
    Forward(a, b, add); // (1) Add is the address to function add and is passed to "Forward"
    (*mult)(a, b); // Other option to call a function

    return 0;
}