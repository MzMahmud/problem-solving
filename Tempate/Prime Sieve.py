from math import sqrt


def get_primes_upto(n):
    """
        Uses Sieve of Eratosthenes to find 
        primes upto n 
    """
    isPrime = [1 for _ in range(n+5)]
    primes = []

    if n > 2:
        primes.append(2)

    limit = sqrt(n+0.0) + 2
    for i in range(3, n + 1, 2):
        if isPrime[i] == 1:
            primes.append(i)
            if i < limit:
                for j in range(i*i, n + 1, 2*i):
                    isPrime[j] = 0

    return primes


print(len(get_primes_upto(1000)))
