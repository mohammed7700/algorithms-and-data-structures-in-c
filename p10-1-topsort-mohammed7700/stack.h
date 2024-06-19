#ifndef CA_STACK_H_
#define CA_STACK_H_

#include "dlinkedlist.h"
#include <stdbool.h>

void push(DList *stack, int key);
int pop(DList *stack);
bool is_empty(const DList *stack);

#endif
