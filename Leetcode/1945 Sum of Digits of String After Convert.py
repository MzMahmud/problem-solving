class Solution:
    def getLucky(self, s, k):
        n = sum(map(letter_digit_sum, s))
        for _ in range(k-1):
            n = digit_sum(n)
        return n


def letter_digit_sum(letter):
    letter_number = ord(letter) - ord('a') + 1
    return digit_sum(letter_number)


def digit_sum(n):
    return sum(map(int, str(n)))
