# include <stdio.h>
# include <stdlib.h>

void merge_sort_array(int * input, int size, int asc) {
    if (size > 1) { //if the array is empty or has only one element.  This is the base case for the recursion. If the array is empty or has only one element, it is already sorted.
        int * left = malloc(size / 2 * sizeof(int)); //create a left array
        int * right = malloc((size - size / 2) * sizeof(int)); //create a right array
        for (int i = 0; i < size / 2; i++) //for each element in the left array
            left[i] = input[i]; //copy the element from the input array
        for (int i = 0; i < size - size / 2; i++) //for each element in the right array. The right array will be bigger if the size is odd
            right[i] = input[i + size / 2]; //copy the element from the input array
        merge_sort_array(left, size / 2, asc); //sort the left array. This is the recursive call. The left array will be sorted when the function returns.
        merge_sort_array(right, size - size / 2, asc); //sort the right array. This is the recursive call. The right array will be sorted when the function returns. 
        //after the left and right arrays are sorted, they are merged into the input array. 
        int leftIndex = 0; //set the left index to 0. This will be used to keep track of which element in the left array is being compared
        int rightIndex = 0; //set the right index to 0. This will be used to keep track of which element in the right array is being compared
        //the first time this loop is run, the left and right arrays are of size 1. 
        //On each iteration, the smaller of the two elements is copied into the input array.
        //The index of the array that was copied is incremented.
        //when one of the arrays is finished, the remaining elements of the other array are copied into the input array.
        if (asc)
            for (int i = 0; i < size; i++) { //for each element in the input array
                if (leftIndex >= size / 2) { //if the left array is finished
                    input[i] = right[rightIndex]; //copy the element from the right array
                    rightIndex++; //increment the right index
                } else if (rightIndex >= size - size / 2) { //if the right array is finished
                    input[i] = left[leftIndex]; //copy the element from the left array
                    leftIndex++; //increment the left index
                } else if (left[leftIndex] < right[rightIndex]) { //if the left element is smaller than the right element
                    input[i] = left[leftIndex]; //copy the element from the left array
                    leftIndex++; //increment the left index
                } else { //if the right element is smaller than the left element
                    input[i] = right[rightIndex]; //copy the element from the right array
                    rightIndex++; //increment the right index
                }
            }
        else
            for (int i = 0; i < size; i++) { //for each element in the input array
                if (leftIndex >= size / 2) { //if the left array is finished
                    input[i] = right[rightIndex]; //copy the element from the right array
                    rightIndex++; //increment the right index
                } else if (rightIndex >= size - size / 2) { //if the right array is finished
                    input[i] = left[leftIndex]; //copy the element from the left array
                    leftIndex++; //increment the left index
                } else if (left[leftIndex] > right[rightIndex]) { //if the left element is bigger than the right element
                    input[i] = left[leftIndex]; //copy the element from the left array
                    leftIndex++; //increment the left index
                } else { //if the right element is bigger than the left element
                    input[i] = right[rightIndex]; //copy the element from the right array
                    rightIndex++; //increment the right index
                }
            }
        free(left); //free the left array
        free(right); //free the right array
    }
}