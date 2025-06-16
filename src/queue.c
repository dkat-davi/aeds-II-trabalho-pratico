#include "../headers/queue.h"
#include "../headers/list.h"
#include "../headers/main.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// Static memory allocation for the customers queue
#define MAX_CUSTOMERS 5       // Define o tamanho máximo da fila
#define MAX_NAME 20      // Define o tamanho do nome
#define MAX_PREFERENCE 10 // Define o tamanho da preferência

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}


bool isEmpty(Queue *q) {
    return q->front == -1;
}


bool isFull(Queue *q) {
    return q->rear == MAX_CUSTOMERS -1;
}


void enqueue(Queue *q, char *name, char *preference) {
    if (isFull(q)){
        printf("Fila Cheia! Não é possível adicionar.");
        return;
    }
    if(isEmpty(q)){
        q->front = 0;
    }
    q->rear++;
    strcpy(q->data[q->rear].name, name);
    strcpy(q->data[q->rear].preference, preference);
}


Customer dequeue(Queue *q) {
    Customer removedCustomer = {0};
    if (isEmpty(q)) {
        printf("Fila Vazia! Não é possível remover.\n");
        return removedCustomer;
    }
    printf("Cliente %s removido da fila de %s.\n", q->data[q->front].name, q->data[q->front].preference);
    // Move the front pointer to the next customer
    removedCustomer = q->data[q->front];
    for (int i = 0; i < q->rear; i++) {
        q->data[i] = q->data[i + 1];
    }
    q->rear--;
    // If the queue is empty after dequeue, reset front and rear
    if (q->rear < 0) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = 0; // Reset front to the first element
    }
    return removedCustomer;
}

void showQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Fila Vazia!\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("Nome: %s, Preferência: %s\n", q->data[i].name, q->data[i].preference);
    }
}


void newCustomer(Queue *comic, Queue *ticket) {
    // Funcion to add new customers to the queue
    int quantia;
    printf("Quantos clientes quer inserir na fila?\n");
    scanf("%d", &quantia);

    for (int i = 0; i < quantia; i++) {
        char name[MAX_NAME];
        char preference[MAX_PREFERENCE];
        
        if (i >= MAX_CUSTOMERS) {
            printf("Número máximo de clientes atingido!\n");
            break;
        }
        printf("\n=========================================\n");
        printf("Cliente %d\n", i + 1);
        printf("=========================================\n");

        // Get customer name and preference
        printf("Digite o nome do cliente %d: ", i + 1);
        scanf("%s", name);
        printf("Digite a preferência do cliente %d: \n", i + 1);
        int option;
        printf("[1] Gibi\n");
        printf("[2] Ingresso\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        // Validate option
        while (option < 1 || option > 2) {
            printf("Opção inválida! Escolha novamente: ");
            scanf("%d", &option);
        }
        // Set preference based on option
        if (option == 1) {
            strcpy(preference, "gibi");
            enqueue(comic, name, preference);
            printf("\nCliente inserido com sucesso na fila de gibis.\n");
        } else if (option == 2) {
            strcpy(preference, "ingresso");
            enqueue(ticket, name, preference);
            printf("\nCliente inserido com sucesso na fila de ingressos.\n");
        }

    }
    printf("Todos os clientes foram inseridos na fila.\n");
    printf("=========================================\n");
}


Customer rewardCustomer(Queue *comic, Queue *ticket) {
    Customer removedCustomer;
    printf("=========================================\n");
    printf("Premiação de Clientes\n");
    printf("=========================================\n");
    printf("Escolha a fila para premiar:\n");
    printf("[1] Gibi\n");
    printf("[2] Ingresso\n");
    int option;
    scanf("%d", &option);
    while (option < 1 || option > 2) {
        printf("Opção inválida! Escolha novamente: \n");
        scanf("%d", &option);
    }
    if (option == 1) {
        printf("Premiando cliente da fila de gibis...\n");
        removedCustomer = dequeue(comic);
    }
    else if (option == 2) {
        printf("Premiando cliente da fila de ingressos...\n");
        removedCustomer = dequeue(ticket);
    }
    return removedCustomer;
}


void showCustomers(Queue *comic, Queue *ticket) {
    int userOption;
    // Function to show the customers in the user selected queue
    printf("=========================================\n");
    printf("Listagem de Clientes\n");
    printf("=========================================\n");
    printf("Escolha a fila para listar os clientes:\n");
    printf("[1] Gibi\n");
    printf("[2] Ingresso\n");
    scanf("%d", &userOption);
    while (userOption < 1 || userOption > 2) {
        printf("Opção inválida! Escolha novamente: \n");
        scanf("%d", &userOption);
    }
    printf("=========================================\n");
    if (userOption == 1) {
        printf("Clientes na fila de gibis:\n");
        showQueue(comic);
    } else if (userOption == 2) {
        printf("Clientes na fila de ingressos:\n");
        showQueue(ticket);
    }
}
