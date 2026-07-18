#include <stdio.h>

int main()
{
    int sortedArray[] = {2, 3, 11, 25, 26, 27, 35, 45, 50, 50, 60, 66, 89, 100, 150};
    int arraySize = 15;
    int targetValue;

    printf("Enter the element to search: ");
    scanf("%d", &targetValue);

    int leftIndex = 0;
    int rightIndex = arraySize - 1;
    int middleIndex;

    while (leftIndex <= rightIndex)
    {
        middleIndex = (leftIndex + rightIndex) / 2;

        if (sortedArray[middleIndex] == targetValue)
        {
            printf("\nElement found at index %d\n", middleIndex);
            return 0;
        }
        else if (sortedArray[middleIndex] > targetValue)
        {
            rightIndex = middleIndex - 1;
        }
        else
        {
            leftIndex = middleIndex + 1;
        }
    }

    printf("\nElement not found.\n");

    return 0;
}
