class Solution:
    # n = length of weights, s = sum of weights
    def shipWithinDays(self, weights, days):
        lo, hi = 0, 0
        # O(n) time
        for weight in weights:
            lo = max(lo, weight)
            hi += weight
        capacity = 0
        # loop runs at most O(log s) time
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            # O(n) time
            if can_ship(mid, weights, days):
                capacity = mid
                hi = mid - 1
            else:
                lo = mid + 1
        # so the loop runs in O(n log s) time
        return capacity


def can_ship(capacity, weights, max_days):
    days, weight_sum = 1, 0
    for weight in weights:
        if weight_sum + weight > capacity:
            days += 1
            weight_sum = 0
        weight_sum += weight
    return days <= max_days
