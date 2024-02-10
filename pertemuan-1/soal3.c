
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
    struct Node *prev;
} Node;

// Fungsi untuk membuat sebuah node baru dengan data tertentu.
Node *createNode(char data);

// Fungsi untuk menyisipkan node baru di awal linked list.
void insertAtBeginning(Node **head, char data);

// Fungsi untuk menyisipkan node baru pada posisi tertentu dalam linked list.
void insertWithPosition(Node **head, char data, int position);

// Fungsi untuk menghapus node dengan data tertentu dari linked list.
void deleteNode(Node **head, char key);

// Fungsi untuk mencetak linked list dari depan ke belakang.
void printListForward(Node *head);

// Fungsi untuk mencetak linked list dari belakang ke depan.
void printListReverse(Node *head);

// Fungsi untuk mencari posisi suatu data dalam linked list.
void findDataPosition(Node *head, char data);

int main(int argc, char const *argv[])
{

    Node *head = NULL;

    int choice, position;
    char data, key;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert new data\n");
        printf("2. Insert new data with position\n");
        printf("3. Find position data\n");
        printf("4. Delete data\n");
        printf("5. Print list (forward)\n");
        printf("6. Print list (reverse)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf(" %c", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf(" %c", &data);
            printf("Enter position: ");
            scanf(" %i", &position);
            insertWithPosition(&head, data, position);
            break;
        case 3:
            printf("Enter data to find the position: ");
            scanf(" %c", &data);
            findDataPosition(head, data);
            break;
        case 4:
            printf("Enter data to delete: ");
            scanf(" %c", &key);
            deleteNode(&head, key);
            break;
        case 5:
            printListForward(head);
            break;
        case 6:
            printListReverse(head);
            break;
        case 7:
            printf("Exiting...\n");
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }
    } while (choice != 7);

    return 0;
}

Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(Node **head, char data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertWithPosition(Node **head, char data, int position)
{

    Node *newNode = createNode(data);

    if (position <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    if (*head == NULL && position != 1)
    {
        printf("Position out of bounds\n");
        return;
    }

    if (position == 1)
    {

        newNode->next = *head;
        if (*head != NULL)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    Node *prev = NULL;
    Node *curr = *head;
    int i = 1;

    while (i < position && curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }

    if (i != position)
    {
        printf("Position out of bounds\n");
        return;
    }

    prev->next = newNode;
    newNode->prev = prev;
    newNode->next = curr;
    if (curr != NULL)
        curr->prev = newNode;
}

void deleteNode(Node **head, char key)
{
    if (*head == NULL)
    {
        printf("List is empty, cannot delete\n");
        return;
    }

    Node *current = *head;
    Node *prev = NULL;

    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Key not found in the list\n");
        return;
    }

    if (prev == NULL)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        prev->next = current->next;
        if (current->next != NULL)
            current->next->prev = prev;
    }

    free(current);
}

void printListForward(Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    printf("\nForward Linked List: ");

    Node *current = head;

    while (current != NULL)
    {
        printf("%c%s", current->data, (current->next == NULL) ? "" : ", ");
        current = current->next;
    }
}

void printListReverse(Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    while (head->next != NULL)
    {
        head = head->next;
    }

    printf("\nReversed Linked List: ");
    while (head != NULL)
    {
        printf("%c%s", head->data, (head->prev == NULL) ? "" : ", ");
        head = head->prev;
    }
}

void findDataPosition(Node *head, char data)
{
    int i = 1;
    while (head != NULL)
    {
        if (head->data == data)
            break;

        head = head->next;
        i++;
    }

    if (head == NULL)
    {
        puts("Data not found");
        return;
    }

    int j = 1;
    while (head->next != NULL)
    {
        head = head->next;
    }

    while (head != NULL)
    {
        if (head->data == data)
            break;
        head = head->prev;
        j++;
    }

    printf("\n%c is at index %i (forward) and %i (reverse)\n", data, i, j);
}