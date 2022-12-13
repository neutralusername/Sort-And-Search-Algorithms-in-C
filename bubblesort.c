void bubble_sort_array(int * array, int length, int ascending) {
    // simple bubble sort implementation
    int i, j, temp; // declare variables. i and j are used for iteration, temp is used for swapping.
    for (i = 0; i < length; i++) { // iterate through the array
        for (j = 0; j < length - 1; j++) { // iterate through the array again(O(n^2))
            if (ascending) { // if the array should be sorted in ascending order
                if (array[j] > array[j + 1]) { // if the current element is bigger than the next element
                    temp = array[j]; // swap the elements
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            } else {
                if (array[j] < array[j + 1]) {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
}