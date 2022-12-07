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

int rand_array(signed int *array, int arraysize, int mode_neg, int mode_asc_desc){     // ) { //int valrange, , ){
    time_t t;

    srand(time(0));
    for (int i = 0; i < arraysize; i++) {
        int randomint = rand();
        if (mode_neg == 1) {
            randomint = randomint * (pot(-1, rand()));
            if (randomint < 0) {
                randomint -= 1;
            }
        }


        if (mode_asc_desc == 0) {                    //pure chaos
            *(array + i) = randomint;
        }

        /* Prototyp für echte random descending und ascending arrays
        if (mode_asc_desc == 1){                     //ascending chaos
            }
            printf("[%d: %d] | ", i, *(array + i));
    }
         */
    }
    return 0;
}

int asc_array(signed int *array, int arraysize){
    for(int i =0; i<arraysize; i++)
        *(array+i) = -32768+i;
    return 0;
}
int desc_array(signed int *array, int arraysize){
    for(int i =0; i<arraysize; i++)
        *(array+i) = 32767-i;
    return 0;
}

int copyArray(int *source_ar, int source_size, int *dest_ar){
    for(int i=0; i < source_size; i++) {
        *(dest_ar + i) = *(source_ar + i);
    }
    return 0;
}


int main() {
    int randomar1size = 150, randomar2size = 150;
    int randar1[randomar1size], randar2[randomar2size];
    int *prandar1 = &randar1[0];
    int *prandar2 = &randar2[0];




    memset( randar1, 0, (randomar1size*4));
    for(int i = 0; i<randomar1size; i++){
        printf("%d ", randar1[i]);
    }
    rand_array(prandar1, randomar1size, 1, 0);
    copyArray(prandar1, randomar1size, prandar2);
    printf("Hello World, %d %d %d %d\n\n\n", randar1[0], randar1[1], randar1[2], pot(-1, 3));
    for(int i = 0; i<randomar2size; i++){
        printf("%d ", randar2[i]);
    }
    printf("\n\n\n");
    asc_array(prandar2, randomar2size);
    for(int i = 0; i<randomar2size; i++){
        printf("%d ", randar2[i]);
    }
    printf("\n\n\n");
    desc_array(prandar2, randomar2size);
    for(int i = 0; i<randomar2size; i++){
        printf("%d ", randar2[i]);
    }
    return 0;


}