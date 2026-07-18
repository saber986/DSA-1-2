#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int topIndex;
    int capacity;
    int *elements;
} Stack;

Stack *createStack(int capacity)
{
    Stack *stackPtr = (Stack *)malloc(sizeof(Stack));

    stackPtr->topIndex = -1;
    stackPtr->capacity = capacity;
    stackPtr->elements = (int *)malloc(sizeof(int) * capacity);

    return stackPtr;
}

int isFull(Stack *stackPtr)
{
    return (stackPtr->topIndex == stackPtr->capacity - 1);
}

int isEmpty(Stack *stackPtr)
{
    if (stackPtr == NULL)
    {
        return 1;
    }

    return (stackPtr->topIndex == -1);
}

void push(Stack *stackPtr, int value)
{
    if (isFull(stackPtr))
    {
        printf("Stack is full\n");
        return;
    }

    stackPtr->topIndex++;
    stackPtr->elements[stackPtr->topIndex] = value;
}

int pop(Stack *stackPtr)
{
    if (isEmpty(stackPtr))
    {
        printf("Stack underflow!!\n");
        return -1;
    }

    int removedValue = stackPtr->elements[stackPtr->topIndex];
    stackPtr->topIndex--;

    return removedValue;
}

int peek(Stack *stackPtr)
{
    if (isEmpty(stackPtr))
    {
        printf("Stack is empty\n");
        return -1;
    }

    return stackPtr->elements[stackPtr->topIndex];
}

void freeStack(Stack *stackPtr)
{
    free(stackPtr->elements);
    free(stackPtr);
}

int main()
{
    int stackSize;

    printf("Enter size: ");
    scanf("%d", &stackSize);

    Stack *myStack = createStack(stackSize);

    int emptyStatus = isEmpty(myStack);
    printf("%d\n", emptyStatus);

    for (int index = 0; index < stackSize; index++)
    {
        int value;
        scanf("%d", &value);
        push(myStack, value);
    }

    for (int index = 0; index <= myStack->topIndex; index++)
    {
        printf("%d ", myStack->elements[index]);
    }

    printf("\nTop element: %d\n", peek(myStack));

    pop(myStack);

    printf("New top element: %d\n", peek(myStack));

    freeStack(myStack);
    myStack = NULL;

    emptyStatus = isEmpty(myStack);
    printf("%d\n", emptyStatus);

    return 0;
}
