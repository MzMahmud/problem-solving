from itertools import zip_longest
from functools import reduce


class Solution:
    def multiply(self, a, b):
        return multiply_optimized(a, b)


# O(m * n) time, O(m + n) space
def multiply_optimized(a, b):
    if a == '0' or b == '0':
        return '0'

    m, n = len(a), len(b)
    product = [0 for _ in range(m + n)]
    last_index = len(product) - 1

    for i, ai in enumerate(reversed(a)):
        ai = int(ai)
        for bi in reversed(b):
            multiplied = product[i] + ai * int(bi)
            product[i] = multiplied % 10
            if i < last_index:
                product[i+1] += multiplied // 10
            i += 1

    while product[-1] == 0:
        product.pop()

    return "".join(map(str, reversed(product)))


# uses the algorithm we use to mutiply by hand
# m = length a, n = length b
# overall time O(2 * m * (m + n) + m + n) = O(m^2 + mn)
# O(m^2 + mn) space
def multiply_classic_math(a, b):
    if a == '0' or b == '0':
        return '0'

    sub_products = []
    # runs m time
    for index, ai in enumerate(reversed(a)):
        # takes O(m + n) time and space
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
