from itertools import zip_longest
from functools import reduce


class Solution:
    def multiply(self, a, b):
        return multiply_classic_math(a, b)


# uses the algorithm we use to mutiply by hand
# m = length a, n = length b
# overall time O(2 * m * (m + n) + m + n) = O(m^2 + mn)
def multiply_classic_math(a, b):
    if a == '0' or b == '0':
        return '0'

    sub_products = []
    # runs m time
    for index, ai in enumerate(reversed(a)):
        # takes O(m + n) time
        sub_product = multiply_single_digit(ai, reversed(b), index)
        sub_products.append(sub_product)

    # sums m array which takes O(m + n) each
    product = reduce(add, sub_products)
    # join takes O(m + n) time
    return "".join(reversed(product))


# O(|a| + index) time
def multiply_single_digit(digit, a, index):
    product = ['0' for _ in range(index)]
    digit, carry = int(digit), 0
    for ai in a:
        multiplied = digit * int(ai) + carry
        product.append(chr(ord('0') + multiplied % 10))
        carry = multiplied // 10

    if carry != 0:
        product.append(chr(ord('0') + carry))

    return product

# O(max(|a|,|b|)) time to simplyfy O(|a| + |b|) time


def add(a, b):
    sum, carry = [], 0

    for ai, bi in zip_longest(a, b, fillvalue='0'):
        added = int(ai) + int(bi) + carry
        sum.append(chr(ord('0') + added % 10))
        carry = added // 10

    if carry != 0:
        sum.append(chr(ord('0') + carry))

    return sum
