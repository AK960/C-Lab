#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // defines NULL

void tryPointers (void) {
    // Initialization
    int ivar = 255;
    int fvar = 64;
    int *iptr = &ivar;

    printf("[Initialisation]\n");
    printf("Address of pointer = %p\n", &iptr);
    printf("Address of ivar = %p\n", &ivar);
    printf("Pointer points => %p\n", iptr);
    printf("Pointer contains => %d\n\n", *iptr); // Access

    // Dereferencing (accessing / manipulating)
    printf("[Dereferencing]\n");
    *iptr = 128;
    printf("New value of pointer: %d\n", *iptr);
    printf("New value of variable: %d\n", ivar);
    // Vice versa
    printf("Old value of variable: %d\n", fvar);
    fvar = *iptr;
    printf("New value of variable: %d\n\n", fvar);

    printf("[Type Manipulation]\n");
    float fl_var = 123.45;
    // Als Float interpretiert (4 Bytes)
    float value1 = *((float*)&fl_var);  // = 123.45

    // Als Integer interpretiert (4 Bytes)
    int value2 = *((int*)&fl_var);      // = z.B. 1123477881

    // Als einzelne Bytes
    char byte0 = *((char*)&fl_var);     // Erstes Byte
    char byte1 = *((char*)&fl_var + 1); // Zweites Byte
    char byte2 = *((char*)&fl_var + 1); // Zweites Byte
    char byte3 = *((char*)&fl_var + 1); // Zweites Byte

}

int main (void) {
    tryPointers();

    return 0;
}