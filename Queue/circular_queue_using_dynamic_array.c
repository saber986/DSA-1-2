#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int frontIndex;
    int rearIndex;
    int capacity;
    int *elements;
} CircularQueue;

CircularQueue *createQueue(int capacity)
{
    CircularQueue *queuePtr = (CircularQueue *)malloc(sizeof(CircularQueue));

    queuePtr->frontIndex = -1;
    queuePtr->rearIndex = -1;
    queuePtr->capacity = capacity;
    queuePtr->elements = (int *)calloc(capacity, sizeof(int));

    return queuePtr;
}

int isEmpty(CircularQueue *queuePtr)
{
    return (queuePtr->frontIndex == -1);
}

int isFull(CircularQueue *queuePtr)
{
    return ((queuePtr->rearIndex + 1) % queuePtr->capacity == queuePtr->frontIndex);
}

void enqueue(CircularQueue *queuePtr, int value)
{
    if (isFull(queuePtr))
    {
        printf("Queue overflow!!\n");
        return;
    }

    if (queuePtr->frontIndex == -1)
    {
        queuePtr->frontIndex = 0;
        queuePtr->rearIndex = 0;
    }
    else
    {
        queuePtr->rearIndex = (queuePtr->rearIndex + 1) % queuePtr->capacity;
    }

    queuePtr->elements[queuePtr->rearIndex] = value;
}

int dequeue(CircularQueue *queuePtr)
{
    if (isEmpty(queuePtr))
    {
        printf("Queue is empty\nQueue underflow!!\n");
        return -1;
    }

    int removedValue = queuePtr->elements[queuePtr->frontIndex];

    if (queuePtr->frontIndex == queuePtr->rearIndex)
    {
        queuePtr->frontIndex = -1;
        queuePtr->rearIndex = -1;
    }
    else
    {
        queuePtr->frontIndex = (queuePtr->frontIndex + 1) % queuePtr->capacity;
    }

    return removedValue;
}

void displayQueue(CircularQueue *queuePtr)
{
    if (isEmpty(queuePtr))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    for (int index = queuePtr->frontIndex;
         index != queuePtr->rearIndex;
         index = (index + 1) % queuePtr->capacity)
    {
        printf("%d ", queuePtr->elements[index]);
    }

    printf("%d\n", queuePtr->elements[queuePtr->rearIndex]);
}

int peek(CircularQueue *queuePtr)
{
    if (isEmpty(queuePtr))
    {
        printf("Queue is empty!!\n");
        return -1;
    }

    return queuePtr->elements[queuePtr->frontIndex];
}

void freeQueue(CircularQueue *queuePtr)
{
    free(queuePtr->elements);
    free(queuePtr);
}

int main()
{
    int queueSize;

    scanf("%d", &queueSize);

    CircularQueue *myQueue = createQueue(queueSize);

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);

    displayQueue(myQueue);

    printf("%d\n", peek(myQueue));

    dequeue(myQueue);
    displayQueue(myQueue);

    dequeue(myQueue);
    displayQueue(myQueue);

    freeQueue(myQueue);

    return 0;
}
