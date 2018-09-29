#include "../lib/quicksort.h"
// A utility function to swap two elements
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void medianOfThree(int * arr, int low, int high){
    int half = (high - low)/2;

    int begin = arr[low];
    int middle = arr[half];
    int end = arr[high];
    
    
    if ((begin < middle && middle <= end) || (end < middle && middle <= begin)){
        swap(&arr[half], &arr[high]);    
        return;
    }
 
    if ((begin < end && end <= middle) || (middle < end && end <= begin)){
        return;
    }
 
    if ((middle <= begin && begin < end) || (end <= begin && begin < middle)){
        swap(&arr[low],&arr[high]);
        return;
    }
    
    
}

int randomized_partition (int arr[], int low, int high){
    int index = rand() % high;
    while (index > high){
        index = index % high;
    }
    swap(&arr[high], &arr[index]);
    return partition(arr, low, index);
    
}



/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high){
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++){
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot){
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 

int * randomized_quicksort(int arr[], int low, int high){
    if (low < high){
        /* partition_index is partitioning index, arr[p] is now
           at right place */
    
        //medianOfThree(arr, low, high);
        
        int partition_index = randomized_partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        
        randomized_quicksort(arr, low, partition_index - 1);    
        randomized_quicksort(arr, partition_index + 1, high);
    }
    return arr;
}


int * medianQuickSort(int arr[], int low, int high){
    if (low < high){
        /* partition_index is partitioning index, arr[p] is now
           at right place */
    
        medianOfThree(arr, low, high);
        
        int partition_index = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, partition_index - 1);    
        quickSort(arr, partition_index + 1, high);
    }
    return arr;
}

int * quickSort(int arr[], int low, int high){
    if(low < high){

        int partition_index = partition(arr, low, high);
 
        quickSort(arr, low, partition_index - 1);    
        quickSort(arr, partition_index + 1, high);
    }
    return arr;
}
