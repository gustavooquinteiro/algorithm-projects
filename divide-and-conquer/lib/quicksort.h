#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int * quickSort(int * arr, int low, int high); 
int * medianQuickSort(int* arr, int low, int high);
int * randomized_quicksort(int * arr, int low, int high);
int * recursiveQuickSort(int arr[], int low, int high);

int randomized_partition (int * arr, int low, int high);
int partition (int * arr, int low, int high);

void medianOfThree(int * arr, int low, int high);

void swap(int* a, int* b);

#endif
