
#include <string.h>
#include <stdio.h>

int main() {

    printf("Zahl Quadrat Kehrwert \n");

    // durchläuft 12 mal
    for(int i = 0; i < 12; i++) {
        
        //printed 1 bis 12 (0+1 - 11+1) formatiert mit Quadrat und Kehrwert and der richtigen Stelle
        printf(" %3i %7i %8f\n", i+1, (i+1)*(i+1), (float)1/(i+1));
    }

    return 0;
}