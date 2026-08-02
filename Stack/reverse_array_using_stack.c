#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        push(arr[i]);
    }
    printf("\n");

    printf("Reversed Array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = pop();
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
