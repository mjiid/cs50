#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 0;
    do
    {
        n = get_int("Enter the number of bricks : ");
    }
    while(n <= 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 2*n+2; j++)
        {
            if((j >= n - i - 1 && j < n) || (j > n + 2 && j <  n + 3 + i + 1) )
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}