#include <stdio.h>
int fibonacci(int term){
    if (term <= 1)
    {
        return term;
    }

    return fibonacci(term - 1) + fibonacci(term - 2);
}

int main()
{
    int totalTerms;

    scanf("%d", &totalTerms);

    for (int currentTerm = 0; currentTerm < totalTerms; currentTerm++)
    {
        printf("%d ", fibonacci(currentTerm));
    }

    return 0;
}
