# TODO
from cs50 import get_int, get_string
import re

def main():
    number = get_int("Number: ")
    num_list = re.findall('[0-9]', str(number))
    digits = len(num_list)
    if (digits != 13 and digits != 15 and digits != 16):
        print("5")
        print(INVALID)
        return 0
    else:
        first = int(num_list[0])
        sec = int(num_list[0] + num_list[1])
        card_cpy = number
        remainder, rem = 0, 0
        k, sum1, sum2 = 0, 0, 0

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
        total = sum1 + sum2
        if (total % 10 != 0):
            print("INVALID")
            print("1")
            return 0
        elif first == 4:
            print("VISA")
            print("2")
            return 0
        elif (sec== 34 or sec == 37):
            print("AMEX")
            print("3")
            return 0
        elif (sec == 51 or sec == 52 or sec == 53 or sec == 54 or sec== 55):
            print("MASTERCARD")
            print("4")
            return 0
        else:
            print("INVALID")
            print("5")
            return 0


main()
