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
        
