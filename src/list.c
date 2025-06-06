#include "../headers/list.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct linkedList{
    Node* head;
} linkedList;


linkedList* lCreateLinkedList() {
    linkedList* list = (linkedList*)malloc(sizeof(linkedList));
    list->head = NULL;
    return list;
}


void lInsertAtHead(linkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}


void lInsertAtTail(linkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(!list->head) {
        list->head = newNode;
        return;
    }
    Node* current = list->head;
    while(current->next) {
        current = current->next;
    }
    current->next = newNode;
}


void lRemoveElement(linkedList* list, int value) {
    if(!list->head){
        printf("Empty Linked List.");
        return;
    }
    Node* current = list->head;
    if(current->data == value) {
        list->head = current->next;
        free(current);
        return;
    }
    while(current->next && current->next->data != value){
        current = current->next;
    }
    if(current->next->data == value){
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            return;
    }
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
    free(list);
}

