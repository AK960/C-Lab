#include <stdio.h>
#include <stdlib.h>

void print_array1D (int array[], int n);
void print_array2D (int array[], int row_count, int col_count);

int try_array1D() {
    int array1[5] = {1, 2, 3, 4, 5};
    int size1 = sizeof(array1)/sizeof(int); // sizeof returns size in bytes (int is initialized with 4 bytes)
    printf("Size of array1 = %d\n", size1);

    int array2[2];
    array2[0] = 7;
    array2[1] = 8;
    int size2 = sizeof(array2)/sizeof(int);
    printf("Size of array2 = %d\n", size2);

    // Two options of passing an array to a function
    print_array1D(array1, size1); //passing array name and length
    print_array1D(&array2[0], size2); //passing address of the 1st element

    return 0;
}

void print_array1D(int array[], int n) {
    printf("Printing 1D-array ...\n");
    for (int i = 0; i < n; i++) { // must be < not <=, counts from 0
        printf("%d ", array[i]);
    }
    printf("\n");
}

void print_array2D (int *array, int row_count, int col_count) {
    printf("Printing 2D-array ...\n");
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count; j++) {
            printf("%d ", array[i * col_count + j]);
        }
        printf("\n");
    }
}

int try_array2D () {
    int table [][2] = {1, 2, 8, 2, 3, 4};
    int table2 [][4] = { 1 };
    // sizeof operation returns unsigned long (here, int would work fine though)
    int size_row = sizeof(table[0])/sizeof(int);
    int size_row2 = sizeof(table2[0])/sizeof(int);
    int size_col = sizeof(table)/sizeof(int)/size_row;
    int size_col2 = sizeof(table2)/sizeof(int)/size_row2;
    printf("Row size table = %d\n", size_row);
    printf("Row size table2 = %d\n", size_row2);
    printf("Col size table = %d\n", size_col);
    printf("Col size table2 = %d\n", size_col2);

    // Two options of passing an array to a function
    print_array2D(&table[0][0], size_row, size_col);
    print_array2D(table2, size_row2, size_col2);

    return 0;
}

int main (void) {
    try_array1D();
    try_array2D();
    return 0;
}
