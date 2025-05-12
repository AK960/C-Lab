#include <stdio.h>
#include <stdlib.h>

int test_scanf(void) {
    int a;
    int b = 0, c = 0;
    printf("Bitte Zahl eingeben:\n");
    const int check = scanf("%d", &a);

    if (check == EOF) {
        printf("Fehler beim Eingeben! Bitte noch einmal versuchen ...\n");
        return 1;
    } else {
        printf("[Eingabe]\nWert: %d\nAddr: %p\n\n", a, &a);
    }

    printf("[Werte]\nb = %d\nc = %d\n\n", b, c);
    b++; ++c;
    printf("Incrementing postfix: c++ = %d\n", c);
    printf("Incrementing prefix: ++b = %d\n", b);
    b--; --c;
    printf("Decrementing postfix: c-- = %d\n", c);
    printf("Decrementing prefix: --b = %d\n", b);

    return 0;
}

int main(void) {
    test_scanf();


    return 0;
}