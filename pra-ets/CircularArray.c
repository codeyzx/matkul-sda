#include <stdio.h>
#define MAX_SIZE 10 // Change this to the desired size of your circular array

// Structure to hold the circular array
typedef struct
{
    int arr[MAX_SIZE];
    int front, rear;
} CircularArray;

// Function to initialize the circular array
void initialize(CircularArray *ca)
{
    ca->front = -1;
    ca->rear = -1;
}

// Function to check if the circular array is empty
int isEmpty(CircularArray *ca)
{
    return (ca->front == -1 && ca->rear == -1);
}

// Function to check if the circular array is full
int isFull(CircularArray *ca)
{
    printf("front: %d, rear: %d, modulo: %d (%d)\n", ca->front, ca->rear, (ca->rear + 1) % MAX_SIZE, (ca->rear + 1) % MAX_SIZE == ca->front);
    return ((ca->rear + 1) % MAX_SIZE == ca->front);
}

// Function to add an element to the circular array
void enqueue(CircularArray *ca, int data)
{
    if (isFull(ca))
    {
        printf("Circular array is full. Cannot enqueue.\n");
        return;
    }
    else if (isEmpty(ca))
    {
        ca->front = 0;
        ca->rear = 0;
    }
    else
    {
        ca->rear = (ca->rear + 1) % MAX_SIZE;
    }
    ca->arr[ca->rear] = data;
}

// Function to remove an element from the circular array
int dequeue(CircularArray *ca)
{
    int data;
    if (isEmpty(ca))
    {
        printf("Circular array is empty. Cannot dequeue.\n");
        return -1;
    }
    else if (ca->front == ca->rear)
    {
        data = ca->arr[ca->front];
        ca->front = -1;
        ca->rear = -1;
    }
    else
    {
        data = ca->arr[ca->front];
        ca->front = (ca->front + 1) % MAX_SIZE;
    }
    return data;
}

// Function to display the elements of the circular array
void display(CircularArray *ca)
{
    if (isEmpty(ca))
    {
        printf("Circular array is empty.\n");
        return;
    }
    printf("Circular array elements: ");
    int i = ca->front;
    while (i != ca->rear)
    {
        printf("%d ", ca->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", ca->arr[ca->rear]);
}

int main()
{
    CircularArray ca;
    initialize(&ca);

    enqueue(&ca, 10);
    enqueue(&ca, 20);
    enqueue(&ca, 30);

    display(&ca);

    printf("Dequeued element: %d\n", dequeue(&ca));
    printf("Dequeued element: %d\n", dequeue(&ca));
    printf("Dequeued element: %d\n", dequeue(&ca));
    printf("Dequeued element: %d\n", dequeue(&ca));
    printf("Dequeued element: %d\n", dequeue(&ca));

    enqueue(&ca, 40);
    enqueue(&ca, 50);
    enqueue(&ca, 60);
    enqueue(&ca, 70);
    enqueue(&ca, 80);
    enqueue(&ca, 90);
    enqueue(&ca, 100);
    enqueue(&ca, 110);
    enqueue(&ca, 120);
    enqueue(&ca, 130);
    enqueue(&ca, 140);
    enqueue(&ca, 150);
    enqueue(&ca, 160);

    display(&ca);

    return 0;
}
