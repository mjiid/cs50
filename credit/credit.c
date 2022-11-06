#include <cs50.h>
#include <stdio.h>

int digits(long num);

int main(void)
{
    long card_num = get_long("Enter your credit card number :");
    int digit = digits(card_num);
    if (digit != 13 && digit != 15 && digit != 16)
    {
        printf("INVALID\n");
        return -1;
    }
    else
    {
        long card_cpy = card_num;
        printf("%li\n",card_cpy);
        int remainder = 0;
        int  k = 0, sum1 = 0, sum2 = 0;;
        while (card_cpy > 0)
        {
            remainder = card_cpy % 10;
            card_cpy = card_cpy / 100;
            if (k)
            {
                printf("%d",remainder);
                sum1 += 2 * remainder;
                k = 1;
            }
            else
            {
                sum2 += remainder;
                k = 0;
            }
        }

    }

}

// calculate the number of digits in a given number.
int digits(long num)
{
    int dig = 0;
    while (num > 0)
    {
        num = num /10;
        dig++;
    }
    return dig;
}