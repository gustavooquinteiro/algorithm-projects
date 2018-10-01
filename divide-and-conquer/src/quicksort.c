#include "../lib/quicksort.h"

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
    swap(&arr[high], &arr[index]);
    return partition(arr, low, index);
    
}


int partition (int arr[], int low, int high){
    int pivot = arr[high];    
    int i = (low - 1); 
 
    for (register int j = low; j <= high- 1; j++){
        if (arr[j] <= pivot){
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 

int * randomized_quicksort(int arr[], int low, int high){
    if (low < high){
                
        int partition_index = randomized_partition(arr, low, high);

        randomized_quicksort(arr, low, partition_index - 1);    
        randomized_quicksort(arr, partition_index + 1, high);
    }
    return arr;
}


int * medianQuickSort(int arr[], int low, int high){
    if (low < high){
    
        medianOfThree(arr, low, high);        
        int partition_index = partition(arr, low, high);
        
        quickSort(arr, low, partition_index - 1);    
        quickSort(arr, partition_index + 1, high);
    }
    return arr;
}

int * quickSort(int arr[], int low, int high){
    while(low < high){

        int partition_index = partition(arr, low, high);
        
        if (partition_index - low < high -partition_index){
            quickSort(arr, low, partition_index - 1);        
            low = partition_index +1;
        }else{
            quickSort(arr, partition_index + 1, high);    
            high = partition_index-1;
        }
    
    }
    return arr;
}


int * recursiveQuickSort(int arr[], int low, int high){
    if (low < high){
    
        int partition_index = partition(arr, low, high);
        
        quickSort(arr, low, partition_index - 1);    
        quickSort(arr, partition_index + 1, high);
        return arr;
    }
    return NULL;
}
