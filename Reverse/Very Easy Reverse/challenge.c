#include <stdio.h>

int main()
{
    int a, b;

    printf("Enter number a: ");
    scanf("%d", &a);

    printf("Enter number b: ");
    scanf("%d", &b);

    if (a == 38)
    {
        if (b == 39)
        {
            printf("Congratulations you have cracked it!\n");
            return 0;
        }
    }
    printf("Oops! Try again!\n");
    return 0;
}