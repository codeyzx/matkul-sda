#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
} LinkedList;

LinkedList *createList();
Node *createNode(int data);
void enqueueBegin(LinkedList *list, int data);
void enqueueEnd(LinkedList *list, int data);
void enqueueNth(LinkedList *list, int data, size_t position);
int dequeueBegin(LinkedList *list);
int dequeueEnd(LinkedList *list);
int dequeueNth(LinkedList *list, size_t position);
void recursiveDisplayList(Node *current);
void displayList(LinkedList *list);
void recursiveFreeList(Node *current);
void freeList(LinkedList *list);

#endif
