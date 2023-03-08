from math import ceil


class Solution:
    def minEatingSpeed(self, piles, h):
        def can_eat(k):
            time = sum(map(lambda pile: ceil(pile/k), piles))
            return time <= h

        max_val, sum_val = max_sum(piles)
        lo = max(1, sum_val//h)
        hi = max_val
        while lo <= hi:
            mid = (lo + hi) // 2
            if can_eat(mid):
                hi = mid - 1
            else:
                lo = mid + 1
        return lo


def max_sum(array):
    max_val, sum_val = array[0], 0
    for val in array:
        max_val = max(max_val, val)
        sum_val += val
    return max_val, sum_val
