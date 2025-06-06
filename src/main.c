#include "../headers/queue.h"
#include "../headers/stack.h"
#include "../headers/list.h"
#include <stdio.h>

void showMessageQueue();


void showMessageStack() {
    Stack* stack = s_createStack();
    s_push(stack, 10);
    s_push(stack, 20);
    s_push(stack, 30);
    s_display(stack);
};


void showMessageList();

int main()
{
    showMessageQueue();
    showMessageStack();
    showMessageList();

    return 0;
}
