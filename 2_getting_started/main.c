#include "sorts.h"

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
