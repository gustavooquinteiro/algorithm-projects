#include "../lib/testes.h"


typedef struct {
    char * nome;
    float tempo;
}Algoritmo;


int fibonacci(int n){
  if(n <= 0)
    return 0;
  int i = n-1;
  int a = 1;
  int b = 0;
  int c = 0;
  int d = 1;
  int aux1 = 0;
  int aux2 = 0;
  while(i > 0){
    if (i%2 != 0){
      aux1 = d*b + c*a;
      aux2 = d*(b+a)+c*b;
      a = aux1;
      b = aux2;
    }
    aux1 = pow(c, 2) + pow(d,2);
    aux2 = d*((c<<1) +d);
    c = aux1;
    d = aux2;
    i = i >> 1;
  }
  return a+b;
}

void format(float tempo){
    int horas, minutos, segundos;
    horas = (tempo/3600); //resultado da hora
    minutos = (tempo -(3600*horas))/60;
    segundos = (tempo -(3600*horas)-(minutos*60));
    if (tempo >=60) {
        if (tempo>=3600){
            printf(" %.2d:%.2d h\n", horas, minutos);
        }else{
            printf(" %d:%.2d min\n", minutos, segundos);
        }
    } else{
        printf(" %.3f seg\n", tempo);
    }
}


void remover(int * arr){
    free(arr);
    arr = NULL;
}

int cmp(Algoritmo a, Algoritmo b){
    return (a.tempo < b.tempo);
}


void test(int * arr, int zero, int n){
        int indice = 6;

        Algoritmo algoritmos[indice];
        algoritmos[0].nome = "Mergesort                 |";
        algoritmos[0].tempo = 0.0f;
        algoritmos[1].nome = "RandomizedQuicksort       |";
        algoritmos[1].tempo = 0.0f;
        algoritmos[2].nome = "MedianQuicksort           |";
        algoritmos[2].tempo = 0.0f;
        algoritmos[3].nome = "Quicksort (last element)  |";
        algoritmos[3].tempo = 0.0f;
        algoritmos[4].nome = "Quicksort (first element) |";
        algoritmos[4].tempo = 0.0f;
        algoritmos[5].nome = "std::sort                 |";
        algoritmos[5].tempo = 0.0f;
        /*algoritmos[6].nome = "Heapsort                  |";
        algoritmos[6].tempo = 0.0f;
        algoritmos[7].nome = "Insertionsort             |";
        algoritmos[7].tempo = 0.0f;
        algoritmos[8].nome = "Selectionsort             |";
        algoritmos[8].tempo = 0.0f;
        algoritmos[9].nome = "Bubblesort                |";
        algoritmos[9].tempo = 0.0f;
        algoritmos[10].nome = "Gnomesort                 |";
        algoritmos[10].tempo = 0.0f;
        algoritmos[11].nome = "Radixsort                 |";
        algoritmos[11].tempo = 0.0f;
        algoritmos[12].nome = "Shellsort                 |";
        algoritmos[12].tempo = 0.0f;
        algoritmos[13].nome = "BubblesortOptimized       |";
        algoritmos[13].tempo = 0.0f;
        */
        clock_t begin, end;

        begin = clock();
        int * array1 = randomized_quicksort(arr, zero, n); // Quicksort utilizando o randomized_partition
        end = clock();
        //printf("Randomized Quicksort finalizado\n");
        float timerquicksort = ((float) end - begin)/CLOCKS_PER_SEC;
        algoritmos[1].tempo = timerquicksort;

        begin = clock();
        int * array2 = medianQuickSort(arr, zero, n);
        end = clock();
        //printf("Median Quicksort finalizado\n");
        float timemquicksort = ((float)end - begin)/CLOCKS_PER_SEC;
        algoritmos[2].tempo = timemquicksort;


        begin = clock();
        int * array4 = mergeSort(arr, zero, n);
        end = clock();
        //printf("Mergesort finalizado\n");
        float timemergesort = ((float)end - begin)/CLOCKS_PER_SEC;
        algoritmos[0].tempo = timemergesort;

        begin = clock();
        int * array3 = quickSortHigh(arr, zero, n);
        end = clock();
        //printf("Quicksort finalizado\n");
        float timequicksortHigh = ((float)end - begin)/CLOCKS_PER_SEC;
        algoritmos[3].tempo = timequicksortHigh;

        begin = clock();
        int * array12 = quickSortLow(arr, zero, n);
        end = clock();
        //printf("Quicksort finalizado\n");
        float timequicksortLow = ((float)end - begin)/CLOCKS_PER_SEC;
        algoritmos[4].tempo = timequicksortLow;


        begin = clock();
        std::sort(arr, arr+n);
        end = clock();
       // printf("std::sort finalizado\n");
        algoritmos[5].tempo = ((float)end - begin)/CLOCKS_PER_SEC;;
        /*

         begin = clock();
        int * array10 = heapSort(arr, n);
        end = clock();
        //printf("Heapsort finalizado\n");
        float timeheapsort = ((float)end - begin)/CLOCKS_PER_SEC;
        algoritmos[6].tempo = timeheapsort;


        begin = clock();
        int * array5 = radixsort(arr, n);
        end = clock();
        //printf("Radixsort finalizado\n");
        float timeradixsort = ((float)end - begin)/CLOCKS_PER_SEC;
        algoritmos[11].tempo = timeradixsort;

        begin = clock();
        int * array6 = shellSort(arr, n);
        end = clock();
        //printf("Shellsort finalizado\n");
        float timeshellsort = ((float)end - begin)/CLOCKS_PER_SEC;
        algoritmos[12].tempo = timeshellsort;

        begin = clock();
        int * array7 = bubbleSort(arr, n);
        end = clock();
        //printf("Bubblesort finalizado\n");
        float timebubblesort = ((float)end - begin)/CLOCKS_PER_SEC;
        algoritmos[9].tempo = timebubblesort;


        begin = clock();
        int * array13 = bubbleSortOptimized(arr, n);
        end = clock();
        //printf("Bubblesort finalizado\n");
        algoritmos[13].tempo =  ((float)end - begin)/CLOCKS_PER_SEC;

        begin = clock();
        int * array8 = insertionSort(arr, n);
        end = clock();
        //printf("Insertionsort finalizado\n");
        float timeinsertionsort = ((float)end - begin)/CLOCKS_PER_SEC;
        algoritmos[7].tempo = timeinsertionsort;

        begin = clock();
        int * array9 = selectionSort(arr, n);
        end = clock();
        //printf("Selectionsort finalizado\n");
        float timeselectionsort = ((float)end - begin)/CLOCKS_PER_SEC;
        algoritmos[8].tempo = timeselectionsort;



        begin = clock();
        int * array11 = gnomeSort(arr, n);
        end = clock();
       // printf("Gnomesort finalizado\n");
        float timegnomesort = ((float)end - begin)/CLOCKS_PER_SEC;
        algoritmos[10].tempo = timegnomesort;


        */

        std::sort(algoritmos, algoritmos+indice, cmp);

        printf("Algoritmo de ordenação    | Tempo total\n");
        for (register int i =0; i < indice; i++){
            printf("%s ", algoritmos[i].nome);
            format(algoritmos[i].tempo);
        }

        printf("\n\n");
}


int main(){
    int n = 1000;
    int j = 1;
    int limit = INT_MAX;
    printf("Benchmark Divide-and-Conquer Sorting Algorithms\n\n");
    int cont = 1;

    while (n < limit){
        printf("Teste %d - Vetor com %d numeros \n", j++, n);
        int * arr = (int *)malloc(n *sizeof(int));
        register int i;
        time_t t;
        srand((unsigned) time(&t));
        for (i = 0; i < n; i++){
            arr[i] = rand();
        }
        printf("\n");
        printf("Random numbers vector\n\n");
        test(arr, 0, n-1);

        // ------------------------------------------------

        for (i = 0; i < n; i++){
            arr[i] = n-i;
        }
        printf("Reverse-order vector\n\n");
        test(arr, 0, n-1);

        // ------------------------------------------------

        for (i = 0; i < n; i++){
            arr[i] = i+1;
        }
        printf("Ordered vector\n\n");
        test(arr, 0, n-1);

        // ------------------------------------------------

        int r = (n >> 1) - 1;
        for (i = n; i > r; i--){
            swap(&arr[rand()%i], &arr[rand()%r]);
        }

        printf("Almost Ordered vector\n\n");
        test(arr, 0, n-1);

        // ------------------------------------------------

        srand((unsigned) time(&t));
        int seed[] = {
                        rand() % (n+1), rand() % (n-1) ,
                        rand() % (n+2), rand() % (n-2),
                        rand() % (n+3), rand() % (n-3),
                        rand() % (n+4), rand() % (n-4),
                        rand() % (n+5), rand() % (n-5)
                    };

        for(i=0; i<n; i++){
            arr[i] = seed[rand()%10];
        }
        printf("Few Unique vector\n\n");
        test(arr, 0, n-1);



        remover(arr);
        n += pow(j, fibonacci(cont++));
        printf("-------------------------------------------------\n");
    }
    return 0;

}
