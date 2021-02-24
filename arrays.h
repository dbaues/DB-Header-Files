#ifndef __ARRAYS_H__
#define __ARRAYS_H__

#include <iostream>
#include "sorting.h"


int getLength(int*);
void printArray(int*, long);

//int getLength(int arr[]){
//    return (sizeof arr) / (sizeof arr[0]);
//}

void printArray(int* arr, long length){
    long i;
    for(i = 0; i < length; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

#endif