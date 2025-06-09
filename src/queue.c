#include "../headers/queue.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// Static memory allocation for the customers queue
#define MAX_CUSTOMERS 5       // Define o tamanho máximo da fila
#define MAX_NAME 20      // Define o tamanho do nome
#define MAX_PREFERENCE 10 // Define o tamanho da preferência

typedef struct {
    char name[MAX_NAME];
    char preference[MAX_PREFERENCE];

} Customer;


typedef struct {
    Customer data[MAX_CUSTOMERS];
    int front;
    int rear;
} Queue;

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
    printf("%s entrou na fila, preferindo %s. \n", name, preference);
}


void mainQueue(int option) {
    Queue comic;
    Queue ticket;
    initQueue(&comic);
    initQueue(&ticket);

    switch (option) {
        case 1:
            int quantia;
            printf("Quantos clientes quer inserir na fila?\n");
            scanf("%d", &quantia);
            for (int i = 0; i < quantia; i++) {
                char name[MAX_NAME];
                char preference[MAX_PREFERENCE];
                printf("Digite o nome do cliente %d: ", i + 1);
                scanf("%s", name);
                printf("Digite a preferência do cliente %d: ", i + 1);
                int option;
                printf("[1] Gibi\n");
                printf("[2] Ingresso\n");
                printf("Escolha uma opção: ");
                scanf("%d", &option);
                while (option < 1 || option > 2) {
                    printf("Opção inválida! Escolha novamente: ");
                    scanf("%d", &option);
                }
                if (option == 1) {
                    strcpy(preference, "gibi");
                    enqueue(&comic, name, preference);
                    printf("Cliente inserido com sucesso na fila de gibis.\n");
                } else if (option == 2) {
                    strcpy(preference, "ingresso");
                    enqueue(&ticket, name, preference);
                    printf("Cliente inserido com sucesso na fila de ingressos.\n");
                }

            }
            break;
        case 2:
            printf("Premiando cliente...\n");
            // Implementar lógica para premiar cliente
            break;
        case 3:
            printf("Listando clientes na fila...\n");
            // Implementar lógica para listar clientes
            break;
        default:
            printf("Opção inválida!\n");
    }
}