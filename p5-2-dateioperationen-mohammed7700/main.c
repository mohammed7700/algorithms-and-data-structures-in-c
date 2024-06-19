#include <stdio.h>
#include <string.h>

const char* outfile_name = "numbers.out";

void print_error(int row, int col) {
    fprintf(stderr, "Fehler: Konnte Zeile %d nicht lesen: Fehler in Spalte %d.\n", row, col);
}

void print_array(FILE* out, int arr[], int n) {
  // hier fehlt Code
}

int main(int argn, const char* args[]) {

    if(argn < 2) {
        fprintf(stderr, "Aufruf mit ./sum <Eingabedatei>\n");
        return 1;
    }        
    
    FILE* fp;
    fp = fopen(args[1], "r");

    int n = 0 , m = 0;

    fscanf(fp, "%i %i", &n, &m);

    //printf("N und M: %i %i \n", n, m);

    int output[m];

    for (int i = 0; i < m; i++) {
        output[i] = 0;
    }

    int holder = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            if(fscanf(fp, "%i", &holder) == 0) {
                print_error(i,j);
            }

            output[j] += holder;

            printf("%i ", output[j]);
        }
        printf("\n");
    }

    fclose(fp);
    FILE* outputFile;
    outputFile = fopen(outfile_name, "w");


    /*printf("So sieht output array aus: \n");
    for(int i = 0; i < m; i++) {
        printf("%d ", output[m]);
    }*/

    for(int i = 0; i < m; i++) {
        fprintf(outputFile, "%d ", output[i]);
    }

    fclose(outputFile);

    return 0;
}
