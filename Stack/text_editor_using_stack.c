#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX][100];
int top = -1;

void push(char text[]) {
    if (top < MAX - 1) {
        top++;
        strcpy(stack[top], text);
    }
}

void undo() {
    if (top >= 0) {
        top--;
    }
}

void display() {
    if (top >= 0) {
        printf("Current Text: %s\n", stack[top]);
    } else {
        printf("Editor is empty\n");
    }
}

int main() {
    push("Hello");
    display();

    push("Hello World");
    display();

    push("Hello World!");
    display();

    printf("After Undo:\n");
    undo();
    display();

    printf("After Undo again:\n");
    undo();
    display();

    return 0;
}
