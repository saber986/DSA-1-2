#include <stdio.h>

int calculateSum(int number)
{
    if (number <= 1)
    {
        return 1;
    }

    return number + calculateSum(number - 1);
}

int main()
{
    int inputNumber;

    scanf("%d", &inputNumber);

    printf("Sum = %d\n", calculateSum(inputNumber));

    return 0;
}
