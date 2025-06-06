#include "../headers/stack.h"
#include <stdio.h>
#include <stdlib.h>
#define STACK_H


typedef struct Node {
	int data;
	struct Node* next;
} Node;


typedef struct Stack {
	Node* top;
} Stack;


Stack* s_createStack() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->top = NULL;
	return stack;
}


void s_push(Stack* stack, int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = stack->top;
	stack->top = newNode;
}


int s_pop(Stack* stack) {
    if(!stack->top){
        printf("Empty Stack");
        return -1;
    }
	Node* temp = stack->top;
	int poppedValue = stack->top->data;
	stack->top = stack->top->next;
	free(temp);
	return poppedValue;
}


int s_peek(Stack* stack) {
    if(!stack->top){
        printf("Empty Stack");
        return -1;
    }
    return stack->top->data;
}


void s_display(Stack* stack) {
    Node* current = stack->top;
    printf("Pilha: ");
    while(current){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
