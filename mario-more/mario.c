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
        for (int j = 0; j < n; j++)
        {
            if(i >= j)
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