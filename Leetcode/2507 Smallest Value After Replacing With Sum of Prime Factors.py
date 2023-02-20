class Solution:
    def smallestValue(self, n: int) -> int:
        while True:
            sum_p = sum_prime_factors(n)
            if n == sum_p:
                return n
            n = sum_p


def sum_prime_factors(n):
    p, sum_p = 2, 0
    while p * p <= n:
        while n % p == 0:
            sum_p += p
            n //= p
        p = 3 if p == 2 else p + 2
    if n > 1:
        sum_p += n
    return sum_p
