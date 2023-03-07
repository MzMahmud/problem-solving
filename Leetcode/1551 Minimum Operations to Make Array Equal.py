class Solution:
    def minOperations(self, n):
        half_n = n >> 1
        return half_n * (n - half_n)
