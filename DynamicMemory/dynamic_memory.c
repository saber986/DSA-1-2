#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int *a = malloc(sizeof(int) * n);
    printf("Enter elements:");
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    printf("Average is: %d", sum / n);
    free(a);
    return 0;
}
