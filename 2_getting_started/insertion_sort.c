//
// Created by koscial on 20/04/2021.
//

#include <stdio.h>

void insertion_sort(int array[], int size);

int main() {
    int i;
    int my_array[8] = {12, 51, 123, 53, 23, 67, 86, 19};

    insertion_sort(my_array, 8);

    for (i = 0; i < 8; ++i) {
        printf("%d ", my_array[i]);
    }

    return 0
}

void insertion_sort(int array[], int size) {
    int key;
    int i, j;

    for (j = 1; j <= size; ++j) {
        key = array[j];
        i = j - 1;

        while(i > -1 && array[i] > key) {
            array[i + 1] = array[i];
            i = i - 1;
        }

        array[i + 1] = key;
    }
}