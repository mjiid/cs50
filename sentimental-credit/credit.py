# TODO
from cs50 import get_int, get_string
import re

def main():
    number = get_int("Number: ")
    digits = len(re.findall('[0-9]', str(number)))
    if digits != 13 and digits != 15 and digits != 16:
        print(INVALID)
        return 0
