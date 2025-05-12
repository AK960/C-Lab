// Chapter 2 - First steps
// File to introduce printf function and conventions

#include <stdio.h>

int exc1() {
    printf("Task 1: Valid Identifiers?\n");
    printf("[Error] int anzahlPreise<30 = 1; - cannot use <\n");
    printf("[Error] int _#Preise_kleiner_30 = 2; - cannot use #\n");
    int _groesster_Wert = 3;
    int groesster_Wert = 4;
    int größter_Wert = 5;
    printf("[Correct] _groesster_Wert = %d\n", _groesster_Wert);
    printf("[Correct] groesster_Wert = %d\n", groesster_Wert);
    printf("[Correct] größter_Wert = %d\n\n", größter_Wert);
    return 0;
};

int exc2() {
    printf("Task 2: Syntax\n");
    printf("[Error] Forgot ; after return value.\n\n");
    return 0;
};

int exc3() {
    printf("Task 3: Includes\n");
    printf("[Error] Forgot to include <stdio.h> header file.\n\n");
    return 0;
};

int main(void) {
    // Call exercise 1
    exc1();
    exc2();
    exc3();

    char myString[] = "%s";
    printf("Mit '%s' kann ich einen String ausgeben!\n", myString);
    
    return 0;
}
