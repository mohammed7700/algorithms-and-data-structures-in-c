#include <stdio.h>
#include <stdlib.h>

typedef struct Foo{
    double* arr;
    int size;
} Foo;

int imin(int x, int y){
    return (x <= y ? x : y);
}

double* init_array(int n) {
    double* array = (double*)malloc(n*sizeof(array));  //Variable existierte nur im Scope
    for(int i=0; i < n; ++i) {
        array[i] = i;
    }
    return array;
}

Foo* create_foo(int size) {
    Foo* f = (Foo*)malloc(sizeof(Foo)); // nicht initialisiert gewesen
    f->arr = init_array(size);
    f->size = size;
    return f;
}

void print_foo(const Foo* f) {
    for(int i=0; i < f->size; ++i) {
        printf("%.3f", f->arr[i]);
    }
    printf("\n");
}

Foo* add_foo(Foo* f1, Foo* f2) {
    int n = imin(f1->size, f2->size);
    Foo* sum = create_foo(n); // sum war nicht initialisiert nur der Speicher für den Struct reserviert, über vorhandene Methode erstellen und values setzen

    for(int i=0; i < n; ++i) {
        sum->arr[i] = f1->arr[i] + f2->arr[i];
    }

    return sum;
}

int main(void) {
    const int n_foos = 10;
    const int foo_size = 5;
    Foo** foos = (Foo**) malloc(n_foos*sizeof(Foo*));
    for(int i=0; i < n_foos; ++i) {
        foos[i] = create_foo(foo_size);
    }

    for(int i=0; i < n_foos; ++i) {
        print_foo(foos[i]);
    }

    Foo* foo_sum = add_foo(foos[0], foos[1]); // wurde falsch übergeben nicht als pointer!
    print_foo(foo_sum);
    
    //speicher die allokiert worden freigeben für alle arr in foos und alle foo's in foos und foos selbst und foo_sum und dessen arr
    for(int i=0; i < n_foos; ++i) {
        free(foos[i]->arr);
    }
    for(int i=0; i < n_foos; ++i) {
        free(foos[i]);
    }

    free(foos);
    free(foo_sum->arr);
    free(foo_sum);

    return 0;
}

