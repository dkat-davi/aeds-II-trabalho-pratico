#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack; // Forward declaration

Stack* s_createStack();
void s_push(Stack* stack, int value);
int s_pop(Stack* stack);
int s_peek(Stack* stack);
void s_display(Stack* stack);

#endif
