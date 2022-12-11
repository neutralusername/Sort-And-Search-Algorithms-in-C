#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int pot(signed long int base, int power) {
    int mediary_val = base;
    for (int i = 0; i <= power; i++) {
        mediary_val = mediary_val * base;
    }
    return mediary_val;
}

void rand_array(signed int *array, int arraysize, int mode_neg, int mode_asc,
               int reverse_order) {     // ) { //int valrange, , ){

    int check_array[arraysize];
    for (int i = 0; i < arraysize; i++) {
        int randomint = rand();
        if (mode_neg == 1) {
            randomint = randomint * (pot(-1, rand()));
            if (randomint < 0) {
                randomint -= 1;
            }
        }

        if (mode_asc == 0) {                    //pure chaos
            *(array + i) = randomint;
            check_array[i] = randomint;
        }

        if (mode_asc == 1) {                     //ascending chaos
            *(array + i) = randomint;
            check_array[i] = randomint;
            if (i > 0) {
                int counter = 0;
                int temp;
                while (*(array + i - counter) < *(array + i - counter - 1)) {
                    if (i == arraysize || counter >= i || randomint == *(array + i - counter - 1)) {
                        break;
                    }
                    temp = *(array + i - counter - 1);
                    *(array + i - counter - 1) = randomint;
                    check_array[i - counter - 1] = randomint;
                    *(array + i - counter) = temp;
                    check_array[i - counter] = temp;

                    counter++;
                }
            }
            //printf("[%d: %d] | ", i, *(array + i));
        }

    }

    if (reverse_order == 1) {
        for (int i = 0; i < arraysize/2; i++) {
            int temp = *(array + i);
            *(array + i) = *(array + arraysize - i);
            *(array + arraysize - i) = temp;
        }
    }
}

// Merge two subarrays L and M into arr, arr L  M  R
void merge(int arr[], int p, int q, int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
    if (l < r) {

        // m is the middle point for splitting into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}




void copyArray(int *source_ar, int source_size, int *dest_ar) {
    for (int i = 0; i < source_size; i++) {
        *(dest_ar + i) = *(source_ar + i);
    }
    return;
}


int main() {
    int randomar1size = 7, randomar2size = 7;
    int randar1[randomar1size], randar2[randomar2size];
    int *prandar1 = &randar1[0];
    int *prandar2 = &randar2[0];
    time_t t;
    srand((unsigned) time(&t));


    memset(randar1, 0, (randomar1size * 4));
    memset(randar2, 0, (randomar2size * 4));
    for (int i = 0; i < randomar1size; i++) {
        printf("%d ", randar1[i]);
    }
    rand_array(prandar1, randomar1size, 1, 1, 0);                  //array , size , Negativ , Ascending , Reverse Order
    copyArray(prandar1, randomar1size, prandar2);
    printf("Hello World, %d %d %d %d\n\n\n", randar1[0], randar1[1], randar1[2], pot(-1, 3));
    for (int i = 0; i < randomar2size; i++) {
        printf("%d ", randar1[i]);
    }
    printf("\n\n\n pure chaos");
    rand_array(randar2, randomar2size, 1, 0, 0);
    for (int i = 0; i < randomar2size; i++) {
        printf("%d ", randar2[i]);
    }
    printf("\n\n\n ascending");
    rand_array(randar2, randomar2size, 1, 1, 1);
    for (int i = 0; i < randomar2size; i++) {
        printf("%d ", randar2[i]);
    }
    printf("\n\n\n merge sorted");
    mergeSort(prandar2, 0, randomar2size-1);
    for (int i = 0; i < randomar2size; i++) {
        printf("%d ", randar2[i]);
    }
    return 0;


}
