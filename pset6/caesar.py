import sys
# check if it have proper cmnd line argument
# or exit
if len(sys.argv) != 2:
    sys.exit(1)
plainText = input('plain_text:')
# store the key value to encrypt
key = int(sys.argv[1])
textList = list(plainText)
for index, char in enumerate(textList):
    ascii = ord(char)
    # if not alpabetic char, ignore
    if not char.isalpha():
        continue
    # c -> position relative to 65 or 97
    # p -> relativr base
    if ascii >= 65 and ascii <= 90:
        c = ascii - 65
        p = 65
    elif ascii >= 97 and ascii <= 122:
        c = ascii - 97
        p = 97
    c = (c + key) % 26
    # chang the char in place
    textList[index] = chr(c + p)
print('ciphertext: ', ''.join(textList))