#ifndef Header_H
#define Header_H
#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
    char *data;
    struct Node *next;
} Node;

typedef struct list
{
    Node *head;
    Node *tail;
} List;

Node *Alokasi(char *data);

void InitializeList(List *list);

void PrintList(List list);

void PrintQueue(List list);

void PrintStack(List list);

void InsertFirst(List *list, char *data);

void InsertLast(List *list, char *data);

char *DeleteFirst(List *list);

char *DeleteLast(List *list);

bool isPalindrome(char *data);

Node *swap(struct Node *ptr1, struct Node *ptr2);

void SortList(List *list, int size);

int CountList(List list);

bool isBracketMatch(char *data);

#endif