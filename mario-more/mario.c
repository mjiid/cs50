#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 0;
    // getting the size of the bricks:
    do
    {
        n = get_int("Enter the number of bricks : ");
    }
    while (n <= 0 || n > 8);
    // making the bricks:
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        for (int j = 0; j < 2 * n + 2; j++)
        {
            if ((j < n && j >= n - i - 1) || (j >= n + 2 && j <= n + 2 + i))
            {
                printf("#");
                // calculate the number of hashes in a line.
                num++;
            }
            //break out of the loop when there are 2*(i+1) hashes in a line.
            else if (num == 2*(i+1))
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