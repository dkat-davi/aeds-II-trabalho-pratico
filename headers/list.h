#ifndef LIST_H
#define LIST_H
#define MAX_CUSTOMERS 5       // Define o tamanho máximo da fila
#define MAX_NAME 20      // Define o tamanho do nome
#define MAX_PREFERENCE 10 // Define o tamanho da preferência

typedef struct Node {
    char name[MAX_NAME];
    char preference[MAX_PREFERENCE];
    struct Node* next;
    struct Node* prev;
} Node;


typedef struct linkedList{
    Node* head;
} linkedList;

linkedList* createLinkedList();
void lInsertAtHead(linkedList* list, char* name, char* preference);
void lInsertAtTail(linkedList* list, char* name, char* preference);
void lRemoveElement(linkedList* list, char* name);
void lDisplayList(linkedList* list);
linkedList* lFreeList(linkedList* list);
int lSearchElement(linkedList* list, char* name);
void addCustomer(linkedList* list, char* name, char* preference);
void displayWinners(linkedList* list);

#endif
