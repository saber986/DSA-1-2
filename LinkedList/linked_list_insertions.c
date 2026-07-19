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

void insertAtFront(Node **head, int value)
{
    Node *newNode = createNode(value);

    if (newNode == NULL)
    {
        return;
    }

    newNode->next = *head;
    *head = newNode;
}

void insertAtBack(Node **head, int value)
{
    Node *newNode = createNode(value);

    if (newNode == NULL)
    {
        return;
    }

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *current = *head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

void insertAtPosition(Node **head, int value, int position)
{
    if (position == 1)
    {
        insertAtFront(head, value);
        return;
    }

    Node *newNode = createNode(value);

    if (newNode == NULL)
    {
        return;
    }

    Node *current = *head;

    for (int index = 1; index < position - 1 && current != NULL; index++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void displayList(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    Node *head = NULL;

    insertAtFront(&head, 10);
    displayList(head);

    insertAtFront(&head, 50);
    insertAtBack(&head, 40);
    displayList(head);

    displayList(head);

    insertAtFront(&head, 100);
    displayList(head);

    insertAtBack(&head, 30);
    insertAtPosition(&head, 99, 3);
    displayList(head);

    return 0;
}
