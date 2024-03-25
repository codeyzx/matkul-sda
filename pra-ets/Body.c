#include <malloc.h>
#include "Header.h"
#include <string.h>

Node *Alokasi(char *data)
{
    Node *temp;
    temp = malloc(sizeof(Node));
    if (temp != NULL)
    {
        temp->data = data;
        temp->next = NULL;
    }
    return temp;
}

void InitializeList(List *list)
{
    list->head = NULL;
    list->tail = NULL;
}

void PrintList(List list)
{
    Node *temp = list.head;
    while (temp != NULL)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void PrintQueue(List list)
{
    Node *temp = list.head;
    while (temp != NULL)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void PrintStack(List list)
{
    Node *temp = list.tail;
    while (temp != NULL)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void InsertFirst(List *list, char *data)
{
    Node *temp = Alokasi(data);
    if (temp != NULL)
    {
        if (list->head == NULL)
        {
            list->head = temp;
            list->tail = temp;
        }
        else
        {
            temp->next = list->head;
            list->head = temp;
        }
    }
}

void InsertLast(List *list, char *data)
{
    Node *temp = Alokasi(data);
    if (temp != NULL)
    {
        if (list->head == NULL)
        {
            list->head = temp;
            list->tail = temp;
        }
        else
        {
            list->tail->next = temp;
            list->tail = temp;
        }
    }
}

char *DeleteFirst(List *list)
{
    char *temp = NULL;
    if (list->head != NULL)
    {
        Node *tempNode = list->head;
        temp = tempNode->data;
        list->head = list->head->next;
        free(tempNode);
    }
    return temp;
}

char *DeleteLast(List *list)
{
    char *temp = NULL;
    if (list->head != NULL)
    {
        Node *tempNode = list->head;
        if (tempNode->next == NULL)
        {
            temp = tempNode->data;
            free(tempNode);
            list->head = NULL;
            list->tail = NULL;
        }
        else
        {
            while (tempNode->next->next != NULL)
            {
                tempNode = tempNode->next;
            }
            temp = tempNode->next->data;
            free(tempNode->next);
            tempNode->next = NULL;
            list->tail = tempNode;
        }
    }
}

int CountList(List list)
{
    int count = 0;
    while (list.head != NULL)
    {
        count++;
        list.head = list.head->next;
    }
    return count;
}

bool isPalindrome(char *data)
{
    List queue, stack;
    InitializeList(&queue);
    InitializeList(&stack);

    for (int i = 0; data[i] != '\0'; i++)
    {
        char *temp = malloc(sizeof(char));
        *temp = data[i];
        InsertLast(&queue, temp);
        InsertFirst(&stack, temp);
    }
    while (queue.head != NULL && stack.head != NULL)
    {
        char *tempQueue = DeleteFirst(&queue);
        char *tempStack = DeleteFirst(&stack);
        if (*tempQueue != *tempStack)
        {

            printf("%s is not a palindrome\n", data);
            return false;
        }
    }

    printf("%s is a palindrome\n", data);
    return true;
}

Node *swap(struct Node *ptr1, struct Node *ptr2)
{
    struct Node *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void SortList(List *list, int size)
{
    struct Node **h;
    int i, j, swapped;

    for (i = 0; i < size; i++)
    {

        h = &list->head;
        swapped = 0;

        for (j = 0; j < size - i - 1; j++)
        {

            struct Node *p1 = *h;
            struct Node *p2 = p1->next;

            if (strcmp(p1->data, p2->data) > 0)
            {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}

bool isBracketMatch(char *data)
{
    List stack;
    InitializeList(&stack);

    for (int i = 0; data[i] != '\0'; i++)
    {
        if (data[i] == '(' || data[i] == '[' || data[i] == '{')
        {
            char *temp = malloc(sizeof(char));
            *temp = data[i];
            InsertFirst(&stack, temp);
        }
        else if (data[i] == ')' || data[i] == ']' || data[i] == '}')
        {
            if (stack.head == NULL)
            {
                printf("%s is not a bracket match\n", data);
                return false;
            }
            char *temp = DeleteFirst(&stack);
            if (data[i] == ')' && *temp != '(')
            {
                printf("%s is not a bracket match\n", data);
                return false;
            }
            else if (data[i] == ']' && *temp != '[')
            {
                printf("%s is not a bracket match\n", data);
                return false;
            }
            else if (data[i] == '}' && *temp != '{')
            {
                printf("%s is not a bracket match\n", data);
                return false;
            }
        }
    }
    if (stack.head == NULL)
    {
        printf("%s is a bracket match\n", data);
        return true;
    }
    else
    {
        printf("%s is not a bracket match\n", data);
        return false;
    }
}