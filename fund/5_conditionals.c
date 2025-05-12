#include <stdio.h>

int get_higherValue(void) {
    int a, b;
    printf("Bitte zwei Werte eingeben:\n");
    int check = scanf("%d %d", &a, &b);
    if (check != EOF) {
        // Equivalent to if else condition
        int c = (a > b) ? a : b;
        printf("Chose value c = %d\n", c);
        return 0;
    } else {
        printf("Fehler bei der Eingabe!\n");
        return 1;
    }
};

int task_7 (void) {
    int ival = 11, ival2 = 22;

    int res = (ival == 11) && (ival != 22);
    printf("res = %d\n", res);

    return res;
};

int main(void) {
    if (get_higherValue()) {
        printf("Ausführung erfolgreich!\n");
    };

    int res = task_7();
    if ( res ) {
        printf("Return: %d\n", res);
    }

}