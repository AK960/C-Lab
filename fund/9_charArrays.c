#include <stdio.h>
#include <stdlib.h>

int printString (char array[], int len) {
    printf("Your string: %s\n", array);

    return 0;
}

int set_charArrays(void) {
    char myString[30];
    int len = sizeof(myString);

    printf("Input:~$ ");
    if (fgets(myString, sizeof(myString), stdin) == NULL) {
        printf("Reading failed!\n");
        return EXIT_FAILURE;
    }

    printString(&myString[0], len);
    printString(myString, len);

    return EXIT_SUCCESS;
}

int main (void) {

    set_charArrays();
    /*
    char string[15] = "String!";
    char string2[] = {'S', 't', 'r', 'i', 'n', 'g', '!', '\0'};

    int size = sizeof(string);
    int size2 = sizeof(string2);

    printf("Size = %lu\nSize2 = %lu\n", size, size2);
    */
    return 0;
}