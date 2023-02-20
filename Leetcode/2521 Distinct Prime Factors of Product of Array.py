from functools import reduce


class Solution:
    def distinctPrimeFactors(self, nums):
        prime_factor_sets = map(prime_factors, nums)
        product_prime_factor_sets = reduce(merge_set, prime_factor_sets)
        return len(product_prime_factor_sets)


def merge_set(a, b):
    a.update(b)
    return a


def prime_factors(n):
    p, primes = 2, set()
    while p * p <= n:
        k = 0
        while n % p == 0:
            k += 1
            n //= p
        if k != 0:
            primes.add(p)
        p = 3 if p == 2 else p + 2

    if n > 1:
        primes.add(n)

    return primes
