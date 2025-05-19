#include <stdio.h>
#include <stdlib.h>

// Pointer as parameter
void reset (int *val) {
    *val = 0;
}

// Pointer as return value
int *ifget (void) {
    static int buffer[5] = {1, 2, 3, 4, 5};

    return buffer;
}

void test_pointerArithmetics (void) {
    int a[5];
    int *aptr = &a;
    int *bptr = &a[2];

    printf("[Arithmetics]\n");
    printf("Adresses:\n[aptr] %p\n[bptr] %p\n", aptr, bptr);
    printf("[Diff] %ld\n", bptr - aptr);

    aptr = aptr + 2;
    printf("[aNew] %p\n", aptr);

    if (aptr == bptr) {
        printf("[Comp] Pointers point to same element\n");
    } else {
        printf("[Comp] Pointers are different\n");
    }
    printf("\n");
}

void test_charPointers (void) {
    char str[] = "hallo";
    char *ptr = "welt";

    printf("[Prev]\n");
    printf("Array: | %p | %c |\n", &str, str[0]);
    printf("Point: | %p | %c |\n", ptr, *ptr);

    ptr = str; // Pointer now points on array
    printf("[Post]\n");
    printf("Array: | %p | %c |\n", &str, str[0]);
    printf("Point: | %p | %c |\n", ptr, *ptr);


}

int main (void) {
    int ival = 123;
    int *iptr = &ival;
    printf("[Old]\n");
    printf("| Address: %p | Value: %d |\n", &ival, ival);
    printf("| Address: %p | Value: %d |\n\n", iptr, *iptr);

    // Pointer as parameter
    reset(iptr); // same as reset(&ival);
    printf("[New]\n");
    printf("| Address: %p | Value: %d |\n", &ival, ival);
    printf("| Address: %p | Value: %d |\n", iptr, *iptr);

    // Pointer as return value
    int *rv_ptr = ifget();
    printf("Values returned:\n");
    for (int i = 0; i < 5; i++) {
        printf("[%d]%d\n", i, *(rv_ptr + i));
    }
    printf("\n");

    test_pointerArithmetics();

    test_charPointers();

    return 0;
}