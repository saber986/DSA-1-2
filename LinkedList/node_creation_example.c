#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

int main()
{
    Node *head = NULL;

    head = createNode(10);

    if (head != NULL)
    {
        printf("%d\n", head->data);
    }

    head = createNode(100);

    if (head != NULL)
    {
        printf("%d\n", head->data);
    }

    free(head);

    return 0;
}
