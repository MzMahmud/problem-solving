number_in_word = {
    0: '', 1: 'one', 2: 'two', 3: 'three', 4: 'four',
    5: 'five', 6: 'six', 7: 'seven', 8: 'eight',
    9: 'nine', 10: 'ten', 11: 'eleven', 12: 'twelve',
    13: 'thirteen', 14: 'fourteen', 15: 'fifteen', 16: 'sixteen',
    17: 'seventeen', 18: 'eighteen', 19: 'nineteen', 20: 'twenty',
    30: 'thirty', 40: 'forty', 50: 'fifty', 60: 'sixty',
    70: 'seventy', 80: 'eighty', 90: 'ninety', 100: 'hundred',
    1000: 'thousand'
}  # words upto thousand


def to_word(n, padding=""):
    if n == 0:
        return "zero"

    word = ""
    n = n % 10000
    thousand = n//1000
    if thousand > 0:
        word += (number_in_word[thousand] + padding
                 + number_in_word[1000] + padding)

    n = n % 1000
    hundred = n//100
    if hundred > 0:
        word += (number_in_word[hundred] + padding
                 + number_in_word[100] + padding)
        if n % 100 > 0:
            word += ('and' + padding)

    n = n % 100
    if n <= 20:
        word += number_in_word[n]
    else:
        ten = (n//10) * 10
        word += (number_in_word[ten]
                 + padding + number_in_word[n % 10])

    return word


while True:
    try:
        n = int(input("Enter a number [1,10000): "))
        print(n, ' in word: ', to_word(n, padding=' '))
    except:
        print("invalid input!")
        break

last = 1000
sum = 0
for n in range(1, last + 1):
    sum += len(to_word(n))

print(sum)
