
def coin_change_ways(amount: int, coins: list) -> int:
    ways = [0 for i in range(amount + 1)]
    # base case
    ways[0] = 1
    for i in range(len(coins)):
        for num in range(coins[i], amount + 1):
            ways[num] += ways[num - coins[i]]

    return ways[amount]


coins = [1, 2, 5, 10, 20, 50, 100, 200]
print(coin_change_ways(200, coins))
