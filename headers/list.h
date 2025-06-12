#ifndef LIST_H
#define LIST_H


typedef struct linkedList linkedList;

linkedList* lCreateLinkedList();
void lInsertAtHead(linkedList* list, char* name, char* preference);
void lInsertAtTail(linkedList* list, char* name, char* preference);
void lRemoveElement(linkedList* list, char* name);
void lDisplayList(linkedList* list);
linkedList* lFreeList(linkedList* list);
int lSearchElement(linkedList* list, char* name);
void mainList(int option, char* name, char* preference);

#endif
