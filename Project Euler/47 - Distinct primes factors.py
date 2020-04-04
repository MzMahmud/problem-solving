from mymath import get_primes_upto

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

# 134043


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
