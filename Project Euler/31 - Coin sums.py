coins = [1, 2, 5, 10, 20, 50, 100, 200]
n = len(coins)
dp = {}


def coin_change_ways(amount, index=0):
    if index == n:
        if amount == 0:
            return 1
        else:
            return 0

    if amount < 0:
        return 0

    if (index, amount) not in dp:
        take_index = coin_change_ways(amount - coins[index], index)
        dont_take_index = coin_change_ways(amount, index + 1)
        dp[(index, amount)] = take_index + dont_take_index

    return dp[(index, amount)]


print(coin_change_ways(200))
