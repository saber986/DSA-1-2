#include <stdio.h>

void generateFibonacci(int remainingTerms, int currentValue, int nextValue)
{
    if (remainingTerms == 0)
    {
        return;
    }

    printf("%d ", currentValue);

    generateFibonacci(remainingTerms - 1, nextValue, currentValue + nextValue);
}

int main()
{
    int totalTerms;

    scanf("%d", &totalTerms);

    int firstTerm = 0;
    int secondTerm = 1;

    generateFibonacci(totalTerms, firstTerm, secondTerm);

    return 0;
}
