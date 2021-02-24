#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__


long _partition(int*, long, long);
void _quickSort(int*, long, long);
void quickSort(int*, long);


long _partition(int* arr, long left, long right){
    int pivot_element = arr[left];
    int lb = left, ub = right;
    int tmp;

    while(left < right){
        while(arr[left] <= pivot_element){ ++left; }
        while(arr[right] > pivot_element){ --right; }
        if(left < right){
            tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }
    arr[lb] = arr[right];
    arr[right] = pivot_element;
    return right;
}

void _quickSort(int* arr, long left, long right){
    if(left < right){
        long pivot = _partition(arr, left, right);
        _quickSort(arr, left, pivot-1);
        _quickSort(arr, pivot+1, right);
    }
}

void quickSort(int *arr, long length){
    _quickSort(arr, 0, length-1);
}

#endif