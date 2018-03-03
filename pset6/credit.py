# credit card validation
from cs50 import get_int
card = get_int('card_no:')
card_str = str(card)
IdType = None
# decide on the type of card
if len(card_str) == 15 and (card_str[:2] in ['34', '37']):
    IdType = 'AMEX'
elif len(card_str) == 16 and (card_str[:2] in ['51', '52', '53', '54', '55']):
    IdType = 'MASTERCARD'
elif len(card_str) in [13, 16] and (card_str[0] == '4'):
    IdType = 'VISA'
# initialize sum
sumId = 0
# separately store either values
double_elem = map(lambda x: int(x) * 2, card_str[-2::-2])
single_elem = map(int, card_str[-1::-2])
sumId += sum(single_elem)
# check every element in double_elem and add every character to sum
for element in double_elem:
    tempList = list(str(element))
    tempMap = map(int, tempList)
    sumId += sum(tempMap)
if sumId % 10 != 0:
    print('INVALID')
else:
    print(IdType)
