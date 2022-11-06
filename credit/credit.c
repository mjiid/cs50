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
        int  k = 0, sum1;
        while (card_cpy > 0)
        {
            int remainder = card_cpy % 10;
            card_cpy = card_cpy / 100;
            
            printf("%d\n",remainder);
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