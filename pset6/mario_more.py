from cs50 import get_int


while(1):
    user_input = get_int('height:')
    if user_input >= 0 and user_input < 24:
        break
for row in range(1, user_input + 1):
    line = ''
    line += ' ' * (user_input - row)
    line += '#' * row
    line += '  '
    line += '#' * row
    print(line)
