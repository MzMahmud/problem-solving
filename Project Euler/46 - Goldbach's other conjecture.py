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


def is_square(n):
    root = sqrt(n)
    return int(root) == root


def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    i = 3
    while i*i <= n:
        if n % i == 0:
            return False
        i += 2

    return True


primes = get_primes_upto(1000000)

MAX_N = 1000000

for n in range(3, MAX_N+1, 2):
    if is_prime(n):
        continue

    found = False
    for p in primes[1:]:
        if p > n:
            break

        # n = p + 2*a^2
        a = (n - p)//2
        if is_square(a):
            found = True
            break

    if not found:
        print(f'Counter Example {n}')
        break
