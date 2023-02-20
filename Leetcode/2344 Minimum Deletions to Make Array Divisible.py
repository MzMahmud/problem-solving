from functools import reduce


class Solution:
    def minOperations(self, nums, nums_divide):
        g = reduce(gcd, nums_divide)
        smallest_div = min(filter(lambda n: g % n == 0, nums), default=INF)
        if smallest_div == INF:
            return -1
        return sum(map(lambda n: n < smallest_div, nums))


INF = float('inf')


def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)
