#include "../lib/testes.h"

void format(float c){
    if (c >=60) {
        if (c>=3600){
            printf(" %.2f h\n", c/3600);    
        }else{
            printf(" %.2f min\n", c/60);
        }
        
    } else{
        printf(" %.3f seg\n", c);
    }
}


void remover(int * arr){
    free(arr);
    arr = NULL;
}


void test(int * arr, int zero, int n){
        clock_t begin, end;
        
        begin = clock();
        int * array1 = randomized_quicksort(arr, zero, n); // Quicksort utilizando o randomized_partition
        end = clock();
        //printf("Randomized Quicksort finalizado\n");
        float timerquicksort = end - begin;
        timerquicksort = ((float)timerquicksort)/CLOCKS_PER_SEC;
        
        
        begin = clock();
        int * array2 = medianQuickSort(arr, zero, n); 
        end = clock();
        //printf("Median Quicksort finalizado\n");
        float timemquicksort = end - begin;
        timemquicksort = ((float)timemquicksort)/CLOCKS_PER_SEC;
        
        begin = clock();
        int * array4 = mergeSort(arr, zero, n);
        end = clock();
        //printf("Mergesort finalizado\n\n\n");
        float timemergesort = end - begin;
        timemergesort = ((float)timemergesort)/CLOCKS_PER_SEC;
        
        begin = clock();
        int * array3 = quickSort(arr, zero, n); 
        end = clock();
        //printf("Quicksort finalizado\n");
        float timequicksort = end - begin;
        timequicksort = ((float)timequicksort)/CLOCKS_PER_SEC;
            
        printf("Algoritmo de ordenação                  | Tempo total\n");     
        printf("Mergesort                               |");
        format(timemergesort);  
        printf("Randomized Quicksort                    |");
        format(timerquicksort);
      
        printf("Quicksort com pivo mediano              |");
        format(timemquicksort);
        printf("Quicksort recursivo                     |");
        format(timequicksort);
                
                
        printf("\n\n");
}


int main(){
    int n = 1000;
    int j = 1;
    while (n < 256000){
        printf("Teste %d\n", j++);    
        int * arr = (int *)malloc(n *sizeof(int));
        
        for (register int i = 0; i < n; i++){
            arr[i] = rand();
        }
        printf("Criado vetor com %d numeros aleatórios\n", n);
        test(arr, 0, n-1);
        
        for (register int i = 0; i < n; i++){
            arr[i] = rand() % (n - i);
        }
        printf("Criado vetor com %d numeros almost in-order\n", n);
        test(arr, 0, n-1);
        
        int k = n;
        for (register int i = 0; i < n; i++){
            arr[i] = k--;
        }
        printf("Criado vetor com %d numeros reverse-order\n", n);
        test(arr, 0, n-1);

        for (register int i = 0; i < n; i++){
            arr[i] = i;
        }
        printf("Criado vetor com %d numeros in-order\n", n);
        test(arr, 0, n-1);
        

        remover(arr);        
        n = n << 2;
        printf("-------------------------------------------------\n");
    }
    return 0;
    
} 
