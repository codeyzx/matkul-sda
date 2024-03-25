#ifndef DHeader_H
#define DHeader_H

#include <stdio.h>
#include <stdbool.h>

typedef struct DNode
{
    char *data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

typedef struct dlist
{
    DNode *head;
    DNode *tail;
} DList;

DNode *DAlokasi(char *data);

void DInitializeList(DList *list);

void DPrintList(DList list);

void DInsertFirst(DList *list, char *data);

void DInsertLast(DList *list, char *data);

char *DDeleteFirst(DList *list);

char *DDeleteLast(DList *list);

bool DisPalindrome(char *data);

#endif
