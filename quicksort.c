void quicksort(int *arr, int len) {
    int pivot = arr[len / 2];
    arr[len / 2] = arr[len - 1];

    // Declaration of sub arrays and working indexes
    int i0 = 0, i1 = 0;
    int *sub0 = malloc(sizeof(int) * len);
    int *sub1 = malloc(sizeof(int) * len);

    // Separating elements relative to pivot
    for (int i = 0; i < len - 1; i++)
        (arr[i] > pivot) ? (sub1[i1++] = arr[i]) : (sub0[i0++] = arr[i]);

    // Recursive calls on sub arrays
    if (i0 > 1)
        quicksort(sub0, i0);
    if (i1 > 1)
        quicksort(sub1, i1);

    // Reassembly of sub array 0, pivot, sub array 1 into the original array
    for (int i = 0; i < i0; i++)
        arr[i] = sub0[i];
    for (int i = 0; i < i1; i++)
        arr[i0 + i + 1] = sub1[i];
    arr[i0] = pivot;

    free(sub0);
    free(sub1);
}