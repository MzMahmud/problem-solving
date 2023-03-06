class Solution:
    def getMaximumGenerated(self, n):
        if n in (0, 1):
            return n
        values = [0] * (n + 1)
        values[1] = 1
        upper_limit = (n-1)//2 + 1
        for i in range(1, upper_limit):
            values[2 * i] = values[i]
            values[2 * i + 1] = values[i] + values[i + 1]
        return max(values)
