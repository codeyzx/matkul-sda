#include <stdio.h>

void display(int n);
void upper(int j, int n, int i);
void lower(int j, int n, int i);
int main(int argc, char const *argv[])
{
    int one = 1;
    int three = 3;
    int five = 5;
    int seven = 7;
    display(seven);
    // display(five);
    // display(three);
    // display(one);
    return 0;
}

void upper(int j, int n, int i)
{
    if (j < ((n / 2) + 1) - i)
    {
        printf(" ");
    }
    else
    {
        printf("*");
    }
}

void lower(int j, int n, int i)
{
    if (j < (i - (n / 2) + 1))
    {
        printf(" ");
    }
    else if (j < (i - (n / 2) + 1) + (n - i) * 2 - 1)
    {
        printf("*");
    }
}

void display(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ((n / 2) + 1) - i + ((i + 1) * 2) - 1; j++)
        {
            if (i <= n / 2)
            {
                upper(j, n, i);
            }
            else
            {
                lower(j, n, i);
            }
        }

        printf("\n");
    }
}

// *** CORET CORET
// get scan input n
// n must be odd

// 7 star
// (7/2)+1=3+1=4
// x < (n/2)+1; x++
//    *         4 1 6
//   ***        3 3 4
//  *****       2 5 2
// *******      1 7 0
//  *****       2 5
//   ***        3 3
//    *         4 1
// 4 5 6

// 4+1 == 4*2 - 2 - 1 = 5
// 4-1 == 5*2 - 2 -
// 4-3

// 4 + 1 || 4(n/2)+4=8-3=5
// 4 - 1 || 5(n/2)+4=9-6=3
// 4 - 3 || 6(n/2)+4=10-9=1

// 4 + 1 || 4(n/2)+2=6-1=5
// 4 - 1 || 5(n/2)+2=7-4=3
// 4 - 3 || 6(n/2)+2=8-7=1

// 4 + 1 || 4(n/2)+1=5-0=5
// 4 - 1 || 5(n/2)+1=6-3=3
// 4 - 3 || 6(n/2)+1=7-6=1

// 5 star
// (5/2)+1=2+1=3
//   *          3 1
//  ***         2 3
// *****        1 5
//  ***         2 3
//   *          3 1

// 3 star
// (3/2)+1=1+1=2
//  *           2 1
// ***          1 3
//  *           2 1

// *** 3 LOOP AND BEFORE MODULAR
// void display(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (i <= n / 2)
//         {
//             for (int j = 0; j < ((n / 2) + 1) - i + ((i + 1) * 2) - 1; j++)
//             {
//                 if (j < ((n / 2) + 1) - i)
//                 {
//                     printf(" ");
//                 }
//                 else
//                 {
//                     printf("*");
//                 }
//             }
//         }
//         else
//         {

//             for (int l = 0; l < (i - (n / 2) + 1) + (n - i) * 2 - 1; l++)
//             {
//                 if (l < (i - (n / 2) + 1))
//                 {
//                     printf(" ");
//                 }
//                 else
//                 {

//                     printf("*");
//                 }
//             }
//         }

//         printf("\n");
//     }
// }