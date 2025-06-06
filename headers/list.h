#ifndef LIST_H
#define LIST_H


typedef struct linkedList linkedList;

linkedList* lCreateLinkedList();
void lInsertAtHead(linkedList* list, int value);
void lInsertAtTail(linkedList* list, int value);
void lRemoveElement(linkedList* list, int value);
int lSearchElement(linkedList* list, int value);
void lDisplayList(linkedList* list);
void lFreeList(linkedList* list);

#endif
