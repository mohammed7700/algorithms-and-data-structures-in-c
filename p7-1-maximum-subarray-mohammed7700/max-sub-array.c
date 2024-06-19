#include <stdio.h>
#include <stdlib.h>

int max_sub_array(const int* arr, int n) {
    // TODO Hier den Algorithmus Ihrer Wahl implementieren
    //Algo. A
    
    // if(n == 1) {

    //     return arr[n-1];
    // }
    // int tmpSum = 0;
    // int rSubSum = arr[n/2];
    // int rIndex;
    // int lSubSum = arr[n/2];
    // int lIndex;

    // for(int i = n/2; i < n; i++) {
    //     tmpSum += arr[i]; 
    //     if( rSubSum < tmpSum)
    //         rSubSum = tmpSum;
    // }

    // tmpSum = 0;

    // for(int i = n/2; 0 < i; i--) {
    //     tmpSum += arr[i]; 
    //     if( lSubSum < tmpSum)
    //         rSubSum = tmpSum;
    // }


    // Algo. A
    int bestSum = arr[0];
    int tmpSum = 0;

    for(int i = 0; i < n; i++){

        for(int j = i; j < n; i++) {

            tmpSum += arr[j];

            if(tmpSum > bestSum){
                bestSum = tmpSum;
            }
        }
        
        tmpSum = 0;
    }


    return bestSum;
}

/* Unterhalb dieser Zeile muss nichts verändert werden */

int* read_input(FILE* f, int* n) {
    *n = 0;
    if(fscanf(f, "%d", n) != 1 || n < 0) {
        fprintf(stderr, "[FEHLER] Zeile 1: Natürliche Zahl erwartet.\n");
        return NULL;
    }

    int* arr = malloc(*n*sizeof(int));
    for(int i=0; i < *n; ++i) {
        if(fscanf(f, "%d", &arr[i]) != 1) {
            fprintf(stderr, "[FEHLER] Zeile %d: Zahl erwartet.\n", i+2);
            free(arr);
            return NULL;
        }
    }

    return arr;
}

int main(void) {
    int n;
    int* input = read_input(stdin, &n);

    printf("Max: %d\n", max_sub_array(input, n));

    free(input);

    return 0;
}
