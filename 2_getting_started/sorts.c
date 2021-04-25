#include <stdio.h>
#include "sorts.h"

void print_array(int array[], int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertion_sort(int array[], int size) {
    int key;
    int i, j;

    for (j = 1; j < size; ++j) {
        key = array[j];
        i = j - 1;

        while (i > -1 && array[i] > key) {
            array[i + 1] = array[i];
            i = i - 1;
        }

        array[i + 1] = key;
    }
}

void selection_sort(int array[], int size) {
    int i, j, smallest_idx; // Indices
    int switcher; // Values from the array

    for (i = 0; i < size - 1; ++i) {
        smallest_idx = i;

        for (j = i + 1; j < size; ++j) {
            if (array[j] < array[smallest_idx]) {
                smallest_idx = j;
            }
        }

        switcher = array[smallest_idx];
        array[smallest_idx] = array[i];
        array[i] = switcher;
    }
}