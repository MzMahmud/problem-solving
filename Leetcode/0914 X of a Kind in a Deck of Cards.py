from functools import reduce
from collections import Counter


class Solution:
    def hasGroupsSizeX(self, deck):
        return reduce(gcd, Counter(deck).values()) > 1


def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)
