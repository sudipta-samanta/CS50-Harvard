import sys
if len(sys.argv) != 2:
    sys.exit(1)
# Calculate decimal equivalent of each separate key char


def calKey(ch):
    ascii = ord(ch)
    if ascii >= 65 and ascii <= 90:
        k = ascii - 65
    elif ascii >= 97 and ascii <= 122:
        k = ascii - 97
    return k


# Store key string
keyStr = sys.argv[1]
# Check whether the given keyStr is alph string or not
if not keyStr.isalpha():
    sys.exit(1)
plainText = list(input('Plaintext:'))
keyLen = len(keyStr)
# Track a cursor to locate keyStr char, which should be
# usrd for current encrypt
indx = 0
for index, char in enumerate(plainText):
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
    if indx < keyLen:
        key = calKey(keyStr[indx])
    else:
        tempIndex = (indx - keyLen) % keyLen
        key = calKey(keyStr[tempIndex])
    c = (c + key) % 26
    # change the char in place
    plainText[index] = chr(c + p)
    # increase the index of keyStr
    indx += 1
print('ciphertext: ', ''.join(plainText))