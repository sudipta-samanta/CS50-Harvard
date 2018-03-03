import crypt
import sys

# checking my hash value with the cmnd line input


def checkHashValue(word, salt, hashValue):
    value = crypt.crypt(word, salt)
    if value == hashValue:
        print(word)
        sys.exit()


def main():
    if len(sys.argv) != 2:
        sys.exit(1)
    # store cmnd line input
    cmd_input = sys.argv[1]
    salt = cmd_input[:2]
    hashValue = cmd_input[2:]
    # create a list of all available character
    availabale_char = []
    for ch in range(65, 91):
        availabale_char.append(chr(ch))
    for ch in range(97, 123):
        availabale_char.append(chr(ch))
    # Iterate over 5 times to do a brute-force search
    for pos1 in range(52):
        w1 = availabale_char[pos1]
        checkHashValue(w1, salt, hashValue)
        for pos2 in range(52):
            w2 = w1 + availabale_char[pos2]
            checkHashValue(w2, salt, hashValue)
            for pos3 in range(52):
                w3 = w2 + availabale_char[pos3]
                checkHashValue(w3, salt, hashValue)
                for pos4 in range(52):
                    w4 = w3 + availabale_char[pos4]
                    checkHashValue(w4, salt, hashValue)
                    for pos5 in range(52):
                        w5 = w4 + availabale_char[pos5]
                        checkHashValue(w5, salt, hashValue)
    return 0


if __name__ == '__main__':
    main()