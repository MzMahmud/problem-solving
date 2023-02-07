from sortedcontainers import SortedSet

class Solution:
    def nthUglyNumber(self, n):
        ugly_numbers = SortedSet([1])
        i = 0
        while ugly_numbers and i < n:
            ugly_number = ugly_numbers.pop(0)
            i += 1
            for factor in (2, 3, 5):
                ugly_numbers.add(ugly_number * factor)

        return ugly_number