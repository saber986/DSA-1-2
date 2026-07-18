#include <stdio.h>

long long calculateFactorial(int number)
{
    if (number <= 1)
    {
        return 1;
    }

    return number * calculateFactorial(number - 1);
}

int main()
{
    int inputNumber;

    scanf("%d", &inputNumber);

    if (inputNumber < 0)
    {
        printf("Invalid input!\n");
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    long long factorialValue = calculateFactorial(inputNumber);

    printf("%lld\n", factorialValue);

    return 0;
}
