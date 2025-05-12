// Chapter 3 - Data types
// File to repeat data types and specifications

#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // can be used to check for value space limits, e.g., SCHAR_MIN/-MAX or INT_MIN/-MAX

int print_size(int type) {

    switch(type) {
        case 0:
            printf("Size of signed char = %zu byte(s).\n", sizeof(signed char));
            break;
        case 1:
            printf("Size of short = %zu bytes.\n", sizeof(short));
            break;
        case 2:
            printf("Size of int = %zu bytes.\n", sizeof(int));
            break;
        case 3:
            printf("Size of long = %zu bytes.\n", sizeof(long));
            break;
        case 4:
            printf("Size of long long = %zu bytes.\n", sizeof(long long));
            break;
        case 5: 
            printf("Size of bool = %zu byte(s).\n", sizeof(bool));
            break;
        default:
            printf("Ungültige Eingabe: Bitte wähle Zahlen zwischen 0-5!\n");
            break;
    }

    return 0;
}
    

int main(void) {

    const int i = 5; // constant variable, useful for i.e. pointers that should not be manipulated
    int type = 0;

    printf("Choose Datatype:\n");
    printf("0 => signed char\n1 => short\n2 => int\n3 => long\n4 => long long\n5 => bool\nEingabe: ");
    scanf("%d", &type);
    printf("\n");

    print_size(type);

    return 0;
}

