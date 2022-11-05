#include <cs50.h>
#include <stdio.h>

int main(void)
{
    do
    {
        int n = get_int("Enter the number of bricks : ");
    }
    while(n <= 0)

    for (int i = 0; i < n; i++)
    {
        if ( i == n + 1 || i == n + 2)
        {
            printf(" ");
        }
    }
}