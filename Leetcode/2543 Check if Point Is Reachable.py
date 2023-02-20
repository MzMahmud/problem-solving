from math import gcd


class Solution:
    def isReachable(self, x, y) -> bool:
        return is_power_of_two(gcd(x, y))


def is_power_of_two(n):
    return n != 0 and (n & (n - 1)) == 0
