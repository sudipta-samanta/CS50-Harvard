# Recreate 'greedy.c' in python
from cs50 import get_float
while(1):
    user_input = get_float('Prompt:')
    if user_input >= 0:
        break
cents = round(user_input * 100)
# While querters can be used
coins, cents = divmod(cents, 25)
# While dimes can be used
coins += cents // 10
cents %= 10
# While nickels can be used
coins += cents // 5
cents %= 5
# While pennies can be used
coins += cents // 1
print(coins)