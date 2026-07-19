#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int frontIndex;
    int rearIndex;
    int capacity;
    int *elements;
} Queue;

Queue *createQueue(int capacity)
{
    Queue *queuePtr = (Queue *)malloc(sizeof(Queue));

    queuePtr->frontIndex = -1;
    queuePtr->rearIndex = -1;
    queuePtr->capacity = capacity;
    queuePtr->elements = (int *)calloc(capacity, sizeof(int));

    return queuePtr;
}

int isEmpty(Queue *queuePtr)
{
    return (queuePtr->frontIndex == -1);
}

int isFull(Queue *queuePtr)
{
    return (queuePtr->rearIndex == queuePtr->capacity - 1);
}

void enqueue(Queue *queuePtr, int value)
{
    if (isFull(queuePtr))
    {
        printf("Queue is full\nQueue overflow!!\n");
        return;
    }

    if (queuePtr->frontIndex == -1)
    {
        queuePtr->frontIndex = 0;
    }

    queuePtr->rearIndex++;
    queuePtr->elements[queuePtr->rearIndex] = value;
}

int dequeue(Queue *queuePtr)
{
    if (isEmpty(queuePtr) || queuePtr->frontIndex > queuePtr->rearIndex)
    {
        printf("Queue is empty\nQueue underflow!!\n");
        return -1;
    }

    int removedValue = queuePtr->elements[queuePtr->frontIndex];
    queuePtr->frontIndex++;

    if (queuePtr->frontIndex > queuePtr->rearIndex)
    {
        queuePtr->frontIndex = -1;
        queuePtr->rearIndex = -1;
    }

    return removedValue;
}

void displayQueue(Queue *queuePtr)
{
    if (isEmpty(queuePtr))
    {
        printf("Queue is empty\n");
        return;
    }

    for (int position = queuePtr->frontIndex; position <= queuePtr->rearIndex; position++)
    {
        printf("%d ", queuePtr->elements[position]);
    }

    printf("\n");
}

int main()
{
    int queueSize;

    scanf("%d", &queueSize);

    Queue *myQueue = createQueue(queueSize);

    for (int index = 0; index < queueSize; index++)
    {
        int value;
        scanf("%d", &value);
        enqueue(myQueue, value);
    }

    displayQueue(myQueue);

    dequeue(myQueue);
    displayQueue(myQueue);

    dequeue(myQueue);
    displayQueue(myQueue);

    dequeue(myQueue);
    displayQueue(myQueue);

    free(myQueue->elements);
    free(myQueue);

    return 0;
}
