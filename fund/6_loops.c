#include <stdio.h>

int test_loops (void) {
    int a = 0, b = 0;

    while (a <= 5) {
        if (a == 2) {
            printf("Not there yet, continuing ...\n");
            a++;
            continue;
        }
        if (a == 5) {
            printf("Kopfgesteuerte while-loop beendet!\n");
            break; // stops loop when condition is met
        }
        a++;
        do {
            b++;
            if (b == 5) {
                printf("Fußgesteuerte while-loop beendet!\n");
            }
        } while (b < 5);
    }
    return 0;
}

int main (void) {
    test_loops();

    return 0;
}