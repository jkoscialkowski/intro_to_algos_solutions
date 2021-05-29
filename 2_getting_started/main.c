#include "sorts.h"
#include "../utils.h"

int main() {
    int is_array[9] = {12, 51, 123, 51, 23, 67, 86, 19, 321};
    int ss_array[9] = {12, 51, 123, 51, 23, 67, 86, 19, 321};
    int ms_array[13] = {12, 51, 123, 51, 23, 67, 86, 19, 321, 2, 41, 77, 14};

    // Insertion sort
    print_array(is_array, 9);
    insertion_sort(is_array, 9);
    print_array(is_array, 9);

    // Selection sort
    print_array(ss_array, 9);
    selection_sort(ss_array, 9);
    print_array(ss_array, 9);

    // Merge sort
    print_array(ms_array, 13);
    merge_sort(ms_array, 0, 12);
    print_array(ms_array, 13);

    return 0;
}
