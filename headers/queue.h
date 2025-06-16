#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX_CUSTOMERS 5
#define MAX_NAME 20
#define MAX_PREFERENCE 10

typedef struct {
    char name[MAX_NAME];
    char preference[MAX_PREFERENCE];
} Customer;

typedef struct {
    Customer data[MAX_CUSTOMERS];
    int front;
    int rear;
} Queue;

// Funções de inicialização e manipulação da fila
void initQueue(Queue *q);
bool isEmpty(Queue *q);
bool isFull(Queue *q);
void enqueue(Queue *q, char *name, char *preference);
Customer dequeue(Queue *q);
void showQueue(Queue *q);

// Funções de interface com o sistema
void newCustomer(Queue *comic, Queue *ticket);
void rewardCustomer(Queue *comic, Queue *ticket);
void showCustomers(Queue *comic, Queue *ticket);

#endif
