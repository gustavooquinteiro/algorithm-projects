#include "../lib/testes.h"

float format(float c){
    if (c >=60) return (float)c/60;
    return c;
}


void remover(int * arr){
    free(arr);
    arr = NULL;
}

int main(){
    int n;
    while (scanf("%d", &n) && n !=0){
            
        int * arr = (int *)malloc(n *sizeof(int));
        
        for (register int i = 0; i < n; i++){
            arr[i] = rand() % n;
        }
        printf("Criado vetor com %d numeros aleatórios\n", n);
        clock_t begin, end;
        
        begin = clock();
        int * array1 = randomized_quicksort(arr, 0, n-1); // Quicksort utilizando o randomized_partition
        end = clock();
        //printf("Randomized Quicksort finalizado\n");
        float timerquicksort = end - begin;
        timerquicksort = ((float)timerquicksort)/CLOCKS_PER_SEC;
        
        
        begin = clock();
        int * array2 = medianQuickSort(arr, 0, n-1); 
        end = clock();
        //printf("Median Quicksort finalizado\n");
        float timemquicksort = end - begin;
        timemquicksort = ((float)timemquicksort)/CLOCKS_PER_SEC;
        
        
        
        begin = clock();
        int * array3 = quickSort(arr, 0, n-1); 
        end = clock();
        //printf("Quicksort finalizado\n");
        float timequicksort = end - begin;
        timequicksort = ((float)timequicksort)/CLOCKS_PER_SEC;
        
        
        begin = clock();
        int * array4 = mergeSort(arr, 0, n-1);
        end = clock();
        //printf("Mergesort finalizado\n\n\n");
        float timemergesort = end - begin;
        timemergesort = ((float)timemergesort)/CLOCKS_PER_SEC;
        
   
        
        
        printf("Algoritmo de ordenação                 | Tempo total\n"); 
        printf("Quicksort recursivo                    | %.3f s\n", format(timequicksort));
        printf("Randomized Quicksort                   | %.3f s\n", format(timerquicksort));
        printf("Quicksort com pivo mediano             | %.3f s\n", format(timemquicksort));
        printf("Mergesort                              | %.3f s\n", format(timemergesort));
    
    
        
        remover(arr);        
    }
    return 0;
    
} 
