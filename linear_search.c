#include <stdio.h>

int main()
{
    int numbers[] = {2, 3, 11, 25, 26, 27, 35, 45, 50, 50, 60, 66, 89, 100, 150};
    int arraySize = 15;
    int targetValue;

    printf("Enter the element to search: ");
    scanf("%d", &targetValue);

    int foundIndex = -1;

    for (int index = 0; index < arraySize; index++)
    {
        if (numbers[index] == targetValue)
        {
            foundIndex = index;
            break;
        }
    }

    if (foundIndex != -1)
    {
        printf("\nElement found at index %d\n", foundIndex);
    }
    else
    {
        printf("\nElement not found.\n");
    }

    return 0;
}
