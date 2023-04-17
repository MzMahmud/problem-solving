class Solution:
    def kidsWithCandies(self, candies, extra):
        max_val = max(candies)
        return list(map(lambda val: val + extra >= max_val, candies))
