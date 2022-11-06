#include <cs50.h>
#include <stdio.h>

int digits(long num);

int main(void)
{
    long card_num = get_long("Enter your credit card number :");
    int digit = digits(card_num);
    if (digits != 13 || digits != 15 || digits != 16)
    {
        printf("INVALID\n");
        return -1;
    }
    else
    {
        long card_cpy = card_num;
        int sum1 = 0;
        int remainder = 0;
        int k = 0;
        while (card_cpy > 0)
        {
            if(k)
            {
                remainder = card_cpy%100;
            }

            card_cpy = card_cpy/100;

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