#include <malloc.h>
#include "DHeader.h"

DNode *DAlokasi(char *data)
{
    DNode *temp;
    temp = malloc(sizeof(DNode));
    if (temp != NULL)
    {
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;
    }
    return temp;
}

void DInitializeList(DList *list)
{
    list->head = NULL;
    list->tail = NULL;
}

void DPrintList(DList list)
{
    DNode *temp = list.head;
    while (temp != NULL)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void DInsertFirst(DList *list, char *data)
{
    DNode *temp = DAlokasi(data);
    if (temp != NULL)
    {
        if (list->head == NULL)
        {
            list->tail = temp;
        }
        else
        {
            temp->next = list->head;
            list->head->prev = temp;
        }
        list->head = temp;
    }
}

void DInsertLast(DList *list, char *data)
{
    DNode *temp = DAlokasi(data);
    if (temp != NULL)
    {
        if (list->head == NULL)
        {
            list->head = temp;
            list->tail = temp;
        }
        else
        {
            temp->prev = list->tail;
            list->tail->next = temp;
            list->tail = temp;
        }
    }
}

char *DDeleteFirst(DList *list)
{
    char *temp = NULL;
    if (list->head != NULL)
    {
        DNode *tempNode = list->head;
        temp = tempNode->data;
        list->head = list->head->next;
        if (list->head != NULL)
            list->head->prev = NULL;
        free(tempNode);
    }
    return temp;
}

char *DDeleteLast(DList *list)
{
    char *temp = NULL;
    if (list->head != NULL)
    {
        DNode *tempNode = list->tail;
        temp = tempNode->data;
        list->tail = list->tail->prev;
        if (list->tail != NULL)
            list->tail->next = NULL;
        free(tempNode);
    }
    return temp;
}

bool DisPalindrome(char *data)
{
    DList queue;
    DInitializeList(&queue);

    for (int i = 0; data[i] != '\0'; i++)
    {
        char *temp = malloc(sizeof(char));
        *temp = data[i];
        DInsertLast(&queue, temp);
    }

    // print queue using head and tail (reverse)
    DNode *tempHead = queue.head;
    DNode *tempTail = queue.tail;
    while (tempHead != NULL && tempTail != NULL)
    {
        if (*tempHead->data != *tempTail->data)
        {
            printf("%s is not a palindrome\n", data);
            return false;
        }
        tempHead = tempHead->next;
        tempTail = tempTail->prev;
    }

    printf("%s is a palindrome\n", data);
    return true;
}