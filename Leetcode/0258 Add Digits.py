class Solution:
    def addDigits(self, n):
        if n == 0: return 0
        if (mod := n % 9) == 0: return 9
        return mod
