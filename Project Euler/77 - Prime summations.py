from mymath import get_primes_upto


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

# 71 way =  5007
