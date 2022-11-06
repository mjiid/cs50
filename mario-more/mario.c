#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 0;
    do
    {
        n = get_int("Enter the number of bricks : ");
    }
    while(n <= 0 || n > 8);

    for (int i = 0; i < n; i++)
    {
        int num = 0;
        for (int j = 0; j < 2*n+2; j++)
        {
            if ( (j < n && j >= n-i-1) || (j >= n + 2 && j <= n+2+i))
            {
                printf("#");
                num++;
            }
            else if(num == 2*(i+1))
            {
                break;
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}