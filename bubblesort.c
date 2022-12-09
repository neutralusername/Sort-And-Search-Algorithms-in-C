void bubbleSortArray(int *input, int size, int asc) {
    //simple bubble sort implementation
    int i, j, temp; //declare variables. i and j are used for iteration, temp is used for swapping.
    for(i = 0; i < size; i++) { //iterate through the array
        for(j = 0; j < size - 1; j++) { //iterate through the array again(O(n^2))
            if(asc) { //if the array should be sorted in ascending order
                if(input[j] > input[j + 1]) { //if the current element is bigger than the next element
                    temp = input[j]; //swap the elements
                    input[j] = input[j + 1]; 
                    input[j + 1] = temp;
                }
            }
            else {
                if(input[j] < input[j + 1]) {
                    temp = input[j];
                    input[j] = input[j + 1];
                    input[j + 1] = temp;
                }
            }
        }
    }
}