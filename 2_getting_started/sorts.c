#include <limits.h>
#include <math.h>
#include <stdio.h>

#include "sorts.h"

void merge(int array[], int p, int q, int r);

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

void merge_sort(int array[], int p, int r) {
    if (p < r) {
        int q = floor((double) (p + r) / 2);
        merge_sort(array, p, q);
        merge_sort(array, q + 1, r);
        merge(array, p, q, r);
    }
}

void merge(int array[], int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    int left_array[n1 + 1], right_array[n2 + 1];

    // Prepare left array with sentinel value
    for (i = 0; i < n1; ++i) {
        left_array[i] = array[p + i];
    }
    left_array[n1] = INT_MAX;

    // Prepare right array with sentinel value
    for (j = 0; j < n2; ++j) {
        right_array[j] = array[q + j + 1];
    }
    right_array[n2] = INT_MAX;

    i = 0;
    j = 0;
    for (k = p; k <= r; ++k) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i += 1;
        }
        else {
            array[k] = right_array[j];
            j += 1;
        }
    }
}