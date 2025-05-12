// Chapter 1 - Introduction
// File to test the conversion from .c source code file to elf-file
// To create elf-File: gcc <file.c> -o <path_to_outFile>

#include <stdio.h>

int sayHello(char *s){    
    printf("%s", s);
    return 0;
}

int main(void) {
    sayHello("Hello World!\n");
    return 0;
}
