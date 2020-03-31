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


primes = get_primes_upto(1000000)


def has_dist_primes(n, pi):
    """
    returns true if n has exactly p distinct prime factors
    """
    count = 0
    for p in primes:
        if p*p > n:
            break

        if count > pi:
            return False

        if n % p == 0:
            count += 1
            while n % p == 0:
                n = n//p

    if n > 1:
        count += 1

    return count == pi


# find p consecutive numbers with p distincts prime factors
p = 4
n = 2
while True:
    found = True
    for num in range(n, n + p):
        found = found and has_dist_primes(num, p)

    if found:
        print(list(range(n, n + p)))
        break

    n += 1
