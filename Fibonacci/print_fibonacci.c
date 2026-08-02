#include <stdio.h>

void printFibonacci(int n) {
    if (n <= 0) {
        printf("Please enter a positive number.\n");
        return;
    }

    long long first = 0, second = 1, next;
    printf("Fibonacci Series (%d terms): ", n);

    for (int i = 1; i <= n; i++) {
        printf("%lld ", first);
        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}

int main() {
    int terms = 10;
    printFibonacci(terms);
    return 0;
}
