
#include <string.h>
#include <stdio.h>

int main(void) {

  int n=0;

  printf("Bitte Anzahl eingeben: ");

  if(scanf("%i", &n) == 0){

    printf("Fehler!\n");
    return 1;
  }

  printf("\n");
 
  int input[n];

  for(int i=0; i < n; ++i) {

    printf("Zahl %d: ", i+1);

    if(scanf("%d", &input[i]) == 0) {

      printf("Fehler!\n");
      return 2;
    }

    printf("\n");
  }

  int m_sum = input[0];

  for(int i=0; i < n; ++i) {
    int sum = 0;
    for(int j=0; i+j < n; ++j) {
      sum += input[i+j];
    }
    if(sum > m_sum) {
      m_sum = sum;
    }
  }

  printf("Ergebnis: %i\n", m_sum);

  return 0;
}
