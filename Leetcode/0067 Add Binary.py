from itertools import zip_longest


class Solution:
    def addBinary(self, a, b):
        sum, carry = [], 0

        for ai, bi in zip_longest(reversed(a), reversed(b), fillvalue='0'):
            digit_sum = carry + int(ai) + int(bi)
            sum.append(f'{digit_sum % 2}')
            carry = digit_sum // 2

        if carry > 0:
            sum.append(f'{carry}')

        return "".join(reversed(sum))
