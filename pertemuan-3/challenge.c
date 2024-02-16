#include <stdio.h>
int main(int argc, char const *argv[])
{
    // for (int i = 1; i <= 5; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    // for (int i = 1; i <= 15; i++)
    // {
    //     printf("*");
    //     if (i == 1)
    //     {
    //         printf("\n");
    //     }
    //     else if (i == 3)
    //     {
    //         printf("\n");
    //     }
    //     else if (i == 6)
    //     {
    //         printf("\n");
    //     }
    //     else if (i == 10)
    //     {
    //         printf("\n");
    //     }
    // }

    // for (int i = 1; i <= 15; i++)
    // {
    //     printf("*");
    //     if (i == 1 || i == 3 | i == 6 || i == 10)
    //     {
    //         printf("\n");
    //     }
    // }

    // for (int i = 15; i >= 14; i -= 2)
    // {
    //     printf("*");
    // }

    int i = 1;
    int j = 1;
    while (i <= j && i <= 5)
    {
        printf("*");

        i++;
        j = i + 1;
        if (j > i)
        {
            printf("\n");
            j++;
        }
    }

    // int i = 1;
    // while (i <= 15)
    // {
    //     printf("*");

    // }

    return 0;
}
