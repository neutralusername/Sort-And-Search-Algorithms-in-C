#include <stdlib.h>

int compare(int a, int b, int ascending);

void quick_sort_array(int * array, int length, int ascending) {
    int pivot = array[length / 2];
    array[length / 2] = array[length - 1];

    // Declaration of sub arrays and working indexes
    int i0 = 0, i1 = 0;
    int * sub0 = malloc(sizeof(int) * length);
    int * sub1 = malloc(sizeof(int) * length);

    // Separating elements relative to pivot
    for (int i = 0; i < length - 1; i++)
        compare(pivot, array[i], ascending) ? (sub1[i1++] = array[i]) : (sub0[i0++] = array[i]);

    // Recursive calls on sub arrays
    if (i0 > 1)
        quick_sort_array(sub0, i0, ascending);
    if (i1 > 1)
        quick_sort_array(sub1, i1, ascending);

    // Reassembly of sub array 0, pivot, sub array 1 into the original array
    for (int i = 0; i < i0; i++)
        array[i] = sub0[i];
    for (int i = 0; i < i1; i++)
        array[i0 + i + 1] = sub1[i];
    array[i0] = pivot;

    free(sub0);
    free(sub1);
}

// checks if a and b are int the specified order
// returns 0 if a == b
int compare(int a, int b, int ascending) {
    return (ascending) ? (a < b) : (a > b);
}