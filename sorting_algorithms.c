#include <time.h>
#include <stdio.h>
#include "quicksort.h"
#include "linked_list.h"

#define N 100

void execute_12();
void execute_13();

// actual implementations missing
void execute_11() {}
void execute_14() {}

void bubblesort(int *arr, int len) {}
void insertionsort(int *arr, int len) {}
void mergesort(int *arr, int len) {}

void randomize(int *arr, int len) {}
void ascending(int *arr, int len) {}
void descending(int *arr, int len) {}
void print_array(int *arr, int len) {}

int string_eq(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s2 != *s1)
            return 0;
        s1++;
        s2++;
    }
    return *s1 == *s2;
}

int main(int argc, char *args[])
{
    if (argc == 2)
    {
        if (string_eq(args[1], "1.1"))
        {
            execute_11();
        }
        else if (string_eq(args[1], "1.2"))
        {
            execute_12();
        }
        else if (string_eq(args[1], "1.3"))
        {
            execute_13();
        }
        else if (string_eq(args[1], "1.4"))
        {
            execute_14();
        }
        else
        {
            fprintf(stderr, "invalid argument. valid arguments are \"1.1\", \"1.2\", \"1.3\", \"1.4\"");
        }
    }
    else
    {
        fprintf(stderr, "invalid amount of arguments");
    }
    return 0;
}

// 1.2

void print_with_buffer(long int x, int total_len)
{
    printf("%ld", x);
    int slen = 0;
    while (x /= 10)
        slen++;
    for (int i = 0; i < total_len - (slen + 1); i++)
    {
        printf(" ");
    }
}

void execute_12()
{
    int arrsizes[7] = {8, 32, 128, 512, 2084, 8192, 32768};
    long int times[4][21];

    for (int s = 0; s < 4; s++)
    {
        for (int i = 0; i < 21; i++)
        {
            int len = arrsizes[i / 3];
            int *arr = malloc(sizeof(int) * len);

            switch (i % 3)
            {
            case 0:
                randomize(arr, len);
                break;
            case 1:
                ascending(arr, len);
                break;
            case 2:
                descending(arr, len);
                break;
            }

            long int t_before = clock();

            switch (s)
            {
            case 0:
                bubblesort(arr, len);
                break;
            case 1:
                insertionsort(arr, len);
                break;
            case 2:
                mergesort(arr, len);
                break;
            case 3:
                quicksort(arr, len);
                break;
            }

            long int elapsed = clock() - t_before;
            times[s][i] = elapsed;

            free(arr);
        }
    }

    // Printing out the results

    printf("reults 1.2\n\n");
    printf("array size    | ");

    for (int i = 0; i < 7; i++)
    {
        print_with_buffer(arrsizes[i], 3 * 5);
    }

    printf("\narray vals    | ");
    for (int i = 0; i < 21; i++)
    {
        switch (i % 3)
        {
        case 0:
            printf("rnd  ");
            break;
        case 1:
            printf("asc  ");
            break;
        case 2:
            printf("des  ");
            break;
        }
    }

    printf("\n--------------+");
    for (int i = 0; i < 21; i++)
        printf("-----");

    for (int s = 0; s < 4; s++)
    {
        switch (s)
        {
        case 0:
            printf("\nbubblesort    | ");
            break;
        case 1:
            printf("\ninsertionsort | ");
            break;
        case 2:
            printf("\nmergesort     | ");
            break;
        case 3:
            printf("\nquicksort     | ");
            break;
        }

        for (int i = 0; i < 21; i++)
        {
            print_with_buffer(times[s][i], 5);
        }
    }

    printf("\n\n(results in clock ticks)\n\n");
}

// 1.3

void execute_13()
{
    int arr[2000];
    randomize(arr, 2000);

    printf("reults 1.3\n\n");
    for (int i = 0; i < 20; i++)
    {
        long int t_before = clock();
        bubblesort(arr, 2000);
        long int elapsed = clock() - t_before;

        printf("test %d: %ld clock ticks\n", i, elapsed);
    }
}