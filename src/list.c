#include "../headers/list.h"
#include "../headers/main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


linkedList* createLinkedList() {
    linkedList* list = (linkedList*)malloc(sizeof(linkedList));
    list->head = NULL;
    return list;
}


void lInsertAtHead(linkedList* list, char* name, char* preference) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->preference, preference);
    newNode->prev = NULL;
    newNode->next = list->head;
    list->head = newNode;
    if(newNode->next){
        newNode->next->prev = newNode;
    }
}


void lInsertAtTail(linkedList* list, char* name, char* preference) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->preference, preference);
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


void lRemoveElement(linkedList* list, char* name) {
    if(!list->head){
        printf("Empty Linked List.\n");
        return;
    }
    Node* temp = list->head;
    if(strcmp(temp->name, name) == 0) {
        list->head = temp->next;
        if(temp->next)
            temp->next->prev = NULL;
        free(temp);
        return;
    }
    while(temp && strcmp(temp->name, name) != 0){
        temp = temp->next;
    }
    if (temp) {
        if (temp->next)
            temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
    } else
        printf("Value %s not found.\n", name);
}


int lSearchElement(linkedList* list, char* name) {
    Node* current = list->head;
    while(current){
        if(strcmp(current->name, name) == 0){
            printf("Elemento Encontrado.\n");
            return 1;
        }
        current = current->next;
    }
    printf("Elemento não encontrado\n");
    return 0;
}


void lDisplayList(linkedList* list) {
    if (!list) {
        printf("Lista não inicializada.\n");
        return;
    }
    Node* current = list->head;
    if (!current) {
        printf("Lista vazia.\n");
        return;
    }
    while(current) {
        printf("Nome: %s, Preferência: %s\n", current->name, current->preference);
        current = current->next;
    }
}


linkedList* lFreeList(linkedList* list) {
    if (list == NULL) {
        printf("Erro: Lista nula.\n");
        return NULL;
    }
    Node* current = list->head;
    while(current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    //free(list);
    //list = NULL;
    return list;
}


void addCustomer(linkedList* list, char* name, char* preference) {
    if (list->head == NULL) {
        lInsertAtHead(list, name, preference);
    } else {
        lInsertAtTail(list, name, preference);
    }
    printf("Cliente %s adicionado com sucesso à lista.\n", name);
}


void displayWinners(linkedList* list) {
    printf("=========================================\n");
    printf("          Lista de Ganhadores          \n");
    printf("=========================================\n");
    lDisplayList(list);
}
