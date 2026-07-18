#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numbers;

    numbers = (int *)calloc(4, sizeof(int));

    if (numbers == NULL)
    {
        return 1;
    }

    for (int index = 0; index < 4; index++)
    {
        scanf("%d", numbers + index);
    }

    printf("\nFirst element = %d\n", *numbers);

    for (int index = 0; index < 4; index++)
    {
        printf("%d ", *(numbers + index));
    }

    free(numbers);

    return 0;
}
