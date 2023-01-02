cmake_minimum_required(VERSION 3.24)
project(TIProjekt C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TIProjekt
        array_functions.c
        array_functions.h
        bubblesort.c
        bubblesort.h
        exercises.c
        exercises.h
        insertionsort.c
        insertionsort.h
        key_value_pair.h
        linkedlist_functions.c
        linkedlist_functions.h
        main.c
        mergesort.c
        mergesort.h
        node.h
        quicksort.c
        quicksort.h
        search.c
        search.h
        tree_node.h
        quicksort_search_stdlib.c
        quicksort_search_stdlib.h
        )

