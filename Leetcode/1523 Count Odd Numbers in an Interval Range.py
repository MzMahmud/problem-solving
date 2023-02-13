class Solution:
    def countOdds(self, low, high):
        return count_odds(high) - count_odds(low - 1)


def count_odds(n):
    return (n + 1) // 2
