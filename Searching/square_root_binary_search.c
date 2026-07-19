#include <stdio.h>

typedef long long ll;

double calculateSquareRoot(double number)
{
    double left = 1.0;
    double right = number;
    double middle;

    int iterations = 100;

    while (iterations--)
    {
        middle = (left + right) / 2.0;

        if (middle * middle > number)
        {
            right = middle;
        }
        else
        {
            left = middle;
        }
    }

    return middle;
}

ll perfectSquareRoot(ll number)
{
    ll left = 1;
    ll right = number;
    ll middle;

    while (left <= right)
    {
        middle = (left + right) / 2;

        if (middle * middle == number)
        {
            return middle;
        }
        else if (middle * middle > number)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }

    return -1;
}

int main()
{
    ll number;

    scanf("%lld", &number);

    ll perfectRoot = perfectSquareRoot(number);

    if (perfectRoot != -1)
    {
        printf("\nSquare root of %lld is %lld\n", number, perfectRoot);
    }
    else
    {
        printf("\nThe number is not a perfect square.\n");
    }

    double approximateRoot = calculateSquareRoot(175);

    printf("%.5lf\n", approximateRoot);

    return 0;
}
