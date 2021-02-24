#ifndef __SORTING_H__
#define __SORTING_H__

#include <stdlib.h>
#include "quickSort.h"
#include "mergeSort.h"


enum SORT_TYPE{
    BUBBLE,
    INSERTION,
    SELECTION,
    MERGE,
    QUICK,
    RANDOM,
    BOGO
};


void sort(int*, long, SORT_TYPE);
void _swap(int*, int*);
void insertionSort(int*, long);
void selectionSort(int*, long);
void bubbleSort(int*, long);
void randoSort(int*, long);


void sort(int* arr, long length, SORT_TYPE type=QUICK){
    switch(type){
        case(BUBBLE):
            bubbleSort(arr, length);
            break;
        case(INSERTION):
            insertionSort(arr, length);
            break;
        case(SELECTION):
            selectionSort(arr, length);
            break;
        case(MERGE):
            mergeSort(arr, length);
            break;
        case(QUICK):
            quickSort(arr, length);
            break;
        case(BOGO):
        case(RANDOM):
            randoSort(arr, length);
            break;
    }
}

void _swap(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void insertionSort(int* arr, long length){
    int key;
    long i, j;
    for(i = 1; i < length; ++i){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int* arr, long length){
    long i, j, min_index;
    for(i = 0; i < length-1; ++i){
        min_index = i;
        for(j = i+1; j < length; ++j){
            if(arr[j] < arr[min_index])
                min_index = j;
        }

        _swap(&arr[i], &arr[min_index]);
    }
}

void bubbleSort(int* arr, long length){
    long i, j;
    for(i = 0; i < length-1; ++i){
        for(j = 0; j < length-i-1; ++j){
            if(arr[j] > arr[j+1])
                _swap(&arr[j], &arr[j+1]);
        }
    }
}

void randoSort(int* arr, long length){
    long i;
    int index_1, index_2;
    srand(arr[0]);
    bool sorted = false;
    while(!sorted){
        for(i = 0; i < length; ++i){
            index_1 = rand() % length;
            index_2 = rand() % length;
            if(index_1 != index_2)
                _swap(&arr[index_1], &arr[index_2]);
        }

        sorted = true;
        for(i = 0; i < length-1; ++i){
            if(arr[i] > arr[i+1])
                sorted = false;
        }
    }
}

#endif