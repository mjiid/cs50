# TODO
from cs50 import get_int

while True:
    n = get_int("Enter the number of rows: ")
    if n >= 1 and n <= 8:
        break

for i in range(n):
    num = 0
    for j in range(2*n + 2):
        if (j < n and j >= n - i - 1) or (j >= n + 2 and j <= n + 2 +i):
            print("#", end="")
            num += 1
        elif num == 2*(i+1):
            break
        else:
            print(" ", end="")
    print()