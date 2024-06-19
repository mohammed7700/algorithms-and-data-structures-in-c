#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int A[], int n){
  
  for(int i = 1; i < n; i++) {

    int key = A[i];
    int j = i - 1;

    while( j >= 0 && A[j] > key) {

      A[j + 1] = A[j];
      j = j - 1;
    }
    A[j + 1] = key;
  }
}

int main(void) {

  int n;

  scanf("%d", &n);

  int numbers[n];

  for (int i=0; i<n; i++) {
    scanf("%d", &numbers[i]);
  }

  insertion_sort(numbers, n);

  for(int i = 0; i < n; i++) {
    printf("%i ", numbers[i]);
  } 

  return 0;
}

