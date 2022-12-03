# TODO
from cs50 import get_int, get_string
import re

def main():
    number = get_int("Number: ")
    num_list = re.findall('[0-9]', str(number))
    digits = len(num_list)

    if digits != 13 and digits != 15 and digits != 16:
        print(INVALID)
        return 0
    else:
        first = int(num_list[0])
        sec = int(num_list[1])
        card_cpy = card_num
        remainder, rem = 0, 0
        k, sum1, sum2, total = 0, 0, 0, 0

        while card_cpy > 0:
            remainder = card_cpy % 10
            card_cpy /= 10
            if k:
                remainder *= 2
                while remainder > 0:
                    rem = remainder % 10
                    remainder /= 10
                    sum1 += rem
                k = 0
            else:
                sum2 += remainder
                k = 1

            else
            {
                sum2 += remainder;
                k = 1;
            }
        }
        total = sum1 + sum2;
        // validate the card :
        if ((total % 10) != 0)
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
        else if (two == 51 || two == 52 || two == 53 || two == 54 || two == 55)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }

