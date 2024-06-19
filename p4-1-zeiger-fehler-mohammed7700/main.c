#include <stdio.h>

typedef struct Foo {
    double v;
} Foo;

void init_foo(Foo* foo, double v) {
    foo->v = v;
}

void cut_in_half(double* x) {
    *x = *x / 2.0;
}

int main(void) {
    Foo f;
    init_foo(&f, 1.0);

    printf("%.3f\n", f.v);

    Foo g;
    init_foo(&g, 2.0);

    printf("%.3f\n", g.v);

    int a = 10;
    int* pa = &a;

    printf("%d\n", *pa);

    double x;
    cut_in_half(&x);
    printf("%.3f\n", x);

    const double e = 2.718;
    const double* const pe = &e;
    printf("%.3f\n", *pe);

    int pi = 3;
    int* ppi = &pi;
    *ppi = 20;
    printf("%d\n", *ppi);

    char c = 'x';
    char* pc = &c;
    *pc = 'y';
    printf("%c\n", *pc);

    return 0;
}





