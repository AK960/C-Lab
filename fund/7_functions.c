#include <stdio.h>
#include <stdlib.h>

int glob_var = 5; // when using global vars, careful with naming

int print_globVar() {
    printf("[Func] glob_var = %d\n", glob_var);
    return 0;
}

int inc_globVar() {
    glob_var++;
    print_globVar();
    return 0;
}

int main () {
    printf("Exit success: %d\n", EXIT_SUCCESS);
    printf("Exit failure: %d\n", EXIT_FAILURE);

    int glob_var = 3; // defined locally in stack-area for main
    printf("[Main] glob_var = %d\n", glob_var);

    print_globVar();
    inc_globVar();

    return 0;
}