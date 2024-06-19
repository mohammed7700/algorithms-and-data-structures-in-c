#ifndef FRACTION_H
#define FRACTION_H

#include <stdbool.h>
#include <assert.h>
#include "genmath.h"

typedef struct Fraction {
    int p;
    int q;
} Fraction;

bool equal(Fraction x, Fraction y);
bool greater_equal(Fraction x, Fraction y);
bool less_equal(Fraction x, Fraction y) ;
bool less(Fraction x, Fraction y);
bool greater(Fraction x, Fraction y);
Fraction add(Fraction x, Fraction y);
Fraction mult(Fraction x, Fraction y);
Fraction simplify(Fraction x);
Fraction scalar_mult(int factor, Fraction x);
Fraction make_fraction(int p, int q);

#endif