//
// Created by koscial on 20/04/2021.
//

#include <stdio.h>

void print_array(int array[], int size);
void insertion_sort(int array[], int size);
void selection_sort(int array[], int size);


int main() {
    int is_array[8] = {12, 51, 123, 51, 23, 67, 86, 19};
    int ss_array[8] = {12, 51, 123, 51, 23, 67, 86, 19};

    // Insertion sort
    print_array(is_array, 8);
    insertion_sort(is_array, 8);
    print_array(is_array, 8);

    // Selection sort
    print_array(ss_array, 8);
    selection_sort(ss_array, 8);
    print_array(ss_array, 8);

    return 0;
}

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