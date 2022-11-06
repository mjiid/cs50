#include <cs50.h>
#include <stdio.h>

int digits(long num);
int first_dig(long num);
int two_digs(long num);

int main(void)
{
    long card_num = get_long("Enter your credit card number :");
    int digit = digits(card_num);

    //validating the number of digits :
    if (digit != 13 && digit != 15 && digit != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        int first = first_dig(card_num);
        int two = two_digs(card_num);
        long card_cpy = card_num;
        int remainder = 0,rem = 0;
        int  k = 0, sum1 = 0, sum2 = 0, total = 0;

        //validating the card by Luhn's algorithm:
        while (card_cpy > 0)
        {
            //getting the digits of the number:
            remainder = card_cpy % 10;
            card_cpy = card_cpy / 10;
            if (k)
            {
                remainder = remainder * 2;
                //getting the digits of the remainder:
                while (remainder > 0)
                {
                    rem = remainder % 10;
                    remainder = remainder / 10;
                    sum1 += rem;
                }
                k = 0;
            }
            else
            {
                sum2 += remainder;
                k=1;
            }
        }
        total = sum1 + sum2;
        // validate the card :
        if ( (total % 10) != 0 )
        {
            printf("INVALID\n");
            return 0;
        }
        else if (first == 4)
        {
            printf("VISA\n");
            return 0;
        }
        else if (two == 34 || two == 37)
        {
            printf("AMEX\n");
            return 0;
        }
        else if (two == 51 ||two == 52 ||two == 53 ||two == 54 ||two == 55 )
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
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

//determines the first digit of a given number :
int first_dig(long num)
{
    while (num > 10)
    {
        num = num / 10;
    }
    return num;
}

//determines the second digit of a given number :

int two_digs(long num)
{
    while (num > 100)
    {
        num = num / 10;
    }
    return num;
}