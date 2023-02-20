class Solution:
    def commonFactors(self, a, b):
        return divisor_count(gcd(a, b))


def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


def divisor_count(a):
    d, count = 1, 0
    while d * d <= a:
        if a % d == 0:
            count += 1
            other_d = a // d
            if d != other_d:
                count += 1
        d += 1
    return count
