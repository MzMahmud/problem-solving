EVEN_DIGITS = '02468'


class Solution:
    def largestOddNumber(self, number):
        i = len(number)
        while i > 0 and number[i-1] in EVEN_DIGITS:
            i -= 1
        return number[0:i]
