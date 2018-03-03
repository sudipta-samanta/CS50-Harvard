from cs50 import get_int
while(1):
    # loop till user gives proper input
    user_input = get_int('Height:')
    if user_input >= 0 and user_input < 24:
        break

for row in range(1, user_input + 1):
    # for space in range(user_input - row):
    print(" " * (user_input - row), end="")
    # for elem in range(row + 1):
    print("#" * (row + 1), end="")
    print()