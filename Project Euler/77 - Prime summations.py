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


def coin_change_ways(amount: int, coins: list) -> int:
    ways = [0 for i in range(amount + 1)]
    # base case
    ways[0] = 1
    for i in range(len(coins)):
        for num in range(coins[i], amount + 1):
            ways[num] += ways[num - coins[i]]

    return ways[amount]


LIMIT = 5000
PRIMES = get_primes_upto(LIMIT)
for n in range(LIMIT + 1):
    way = coin_change_ways(n, PRIMES)
    if way >= LIMIT:
        print(n, 'way = ', way)
        break
