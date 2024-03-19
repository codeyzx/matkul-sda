#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "../include/LinkedList.h"

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

LinkedList *createList()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    if (list == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void enqueueBegin(LinkedList *list, int data)
{
    Node *newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
    if (list->tail == NULL)
    {
        list->tail = newNode;
    }
}

void enqueueEnd(LinkedList *list, int data)
{
    Node *newNode = createNode(data);
    if (list->tail == NULL)
    {
        list->head = newNode;
    }
    else
    {
        list->tail->next = newNode;
    }
    list->tail = newNode;
}

void enqueueNth(LinkedList *list, int data, size_t position)
{
    if (position == 0)
    {
        enqueueBegin(list, data);
        return;
    }
    Node *newNode = createNode(data);
    Node *current = list->head;
    for (size_t i = 0; i < position - 1 && current != NULL; i++)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        fprintf(stderr, "Invalid position\n");
        exit(EXIT_FAILURE);
    }
    newNode->next = current->next;
    current->next = newNode;
    if (newNode->next == NULL)
    {
        list->tail = newNode;
    }
}

int dequeueBegin(LinkedList *list)
{
    if (list->head == NULL)
    {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = list->head;
    int data = temp->data;
    list->head = list->head->next;
    if (list->head == NULL)
    {
        list->tail = NULL;
    }
    free(temp);
    return data;
}

int dequeueEnd(LinkedList *list)
{
    if (list->head == NULL)
    {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    int data;
    if (list->head->next == NULL)
    {
        data = list->head->data;
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        return data;
    }
    Node *current = list->head;
    while (current->next != list->tail)
    {
        current = current->next;
    }
    data = list->tail->data;
    free(list->tail);
    list->tail = current;
    list->tail->next = NULL;
    return data;
}

int dequeueNth(LinkedList *list, size_t position)
{
    if (position == 0 || list->head == NULL)
    {
        return dequeueBegin(list);
    }
    Node *current = list->head;
    for (size_t i = 0; i < position - 1 && current->next != NULL; i++)
    {
        current = current->next;
    }
    if (current->next == NULL)
    {
        fprintf(stderr, "Invalid position\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = current->next;
    int data = temp->data;
    current->next = temp->next;
    if (current->next == NULL)
    {
        list->tail = current;
    }
    free(temp);
    return data;
}

void recursiveDisplayList(Node *current)
{
    if (current == NULL)
    {
        printf("NULL");
        return;
    }
    printf("%d -> ", current->data);
    recursiveDisplayList(current->next);
}

void displayList(LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    recursiveDisplayList(list->head);
    printf("\n\n");
}

void recursiveFreeList(Node *current)
{
    if (current == NULL)
        return;
    recursiveFreeList(current->next);
    free(current);
}

void freeList(LinkedList *list)
{
    recursiveFreeList(list->head);
    free(list);
}