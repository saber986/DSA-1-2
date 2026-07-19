#include <stdio.h>
#include <stdlib.h>

int *createDynamicArray(int capacity)
{
    return (int *)calloc(capacity, sizeof(int));
}

int *resizeArray(int *arrayPtr, int newCapacity)
{
    if (arrayPtr == NULL)
    {
        printf("\nArray is empty.\nReallocation failed!!\n");
        return arrayPtr;
    }

    int *newArray = (int *)realloc(arrayPtr, newCapacity * sizeof(int));

    if (newArray == NULL)
    {
        printf("Reallocation failed.\n");
        return arrayPtr;
    }

    return newArray;
}

void displayArray(int *arrayPtr, int startIndex, int endIndex)
{
    for (int index = startIndex; index < endIndex; index++)
    {
        printf("%d ", arrayPtr[index]);
    }
}

int main()
{
    int *dynamicArray;
    int initialSize;

    printf("Enter size: ");
    scanf("%d", &initialSize);

    dynamicArray = createDynamicArray(initialSize);

    printf("Enter %d integers:\n", initialSize);

    for (int index = 0; index < initialSize; index++)
    {
        scanf("%d", dynamicArray + index);
    }

    printf("\n%d elements are:\n", initialSize);
    displayArray(dynamicArray, 0, initialSize);
    printf("\n");

    int additionalElements;

    printf("Enter number of new elements: ");
    scanf("%d", &additionalElements);

    int updatedSize = initialSize + additionalElements;

    dynamicArray = resizeArray(dynamicArray, updatedSize);

    printf("\nEnter %d new elements:\n", additionalElements);

    for (int index = initialSize; index < updatedSize; index++)
    {
        scanf("%d", dynamicArray + index);
    }

    printf("\nNewly added elements:\n");
    displayArray(dynamicArray, initialSize, updatedSize);

    printf("\nAll elements are:\n");
    displayArray(dynamicArray, 0, updatedSize);

    free(dynamicArray);
    dynamicArray = NULL;

    return 0;
}
