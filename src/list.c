#include "../headers/list.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;


typedef struct linkedList{
    Node* head;
} linkedList;


linkedList* createLinkedList() {
    linkedList* list = (linkedList*)malloc(sizeof(linkedList));
    list->head = NULL;
    return list;
}


void lInsertAtHead(linkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = list->head;
    list->head = newNode;
    if(newNode->next){
        newNode->next->prev = newNode;
    }
}


void lInsertAtTail(linkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(!list->head) {
        list->head = newNode;
        newNode->prev = NULL;
        return;
    }
    Node* current = list->head;
    while(current->next) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}


void lRemoveElement(linkedList* list, int value) {
    if(!list->head){
        printf("Empty Linked List.\n");
        return;
    }
    Node* temp = list->head;
    if(temp->data == value) {
        list->head = temp->next;
        if(temp->next)
            temp->next->prev = NULL;
        free(temp);
        return;
    }
    while(temp && temp->data != value){
        temp = temp->next;
    }
    if (temp) {
        if (temp->next)
            temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
    } else
        printf("Value %d not found.\n", value);
}


int lSearchElement(linkedList* list, int value) {
    Node* current = list->head;
    while(current){
        if(current->data == value){
            printf("Elemento Encontrado.\n");
            return 1;
        }
        current = current->next;
    }
    printf("Elemento não encontrado\n");
    return 0;
}


void lDisplayList(linkedList* list) {
    Node* current = list->head;
    while(current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


void lFreeList(linkedList* list) {
    Node* current = list->head;
    while(current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    free(list);
}
