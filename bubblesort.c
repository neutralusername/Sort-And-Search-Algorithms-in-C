void bubbleSortArray(int *input_array, int length, int ascending) {
    //simple bubble sort implementation
    int i, j, temp; //declare variables. i and j are used for iteration, temp is used for swapping.
    for(i = 0; i < length; i++) { //iterate through the array
        for(j = 0; j < length - 1; j++) { //iterate through the array again(O(n^2))
            if(ascending) { //if the array should be sorted in ascending order
                if(input_array[j] > input_array[j + 1]) { //if the current element is bigger than the next element
                    temp = input_array[j]; //swap the elements
                    input_array[j] = input_array[j + 1]; 
                    input_array[j + 1] = temp;
                }
            }
            else {
                if(input_array[j] < input_array[j + 1]) {
                    temp = input_array[j];
                    input_array[j] = input_array[j + 1];
                    input_array[j + 1] = temp;
                }
            }
        }
    }
}