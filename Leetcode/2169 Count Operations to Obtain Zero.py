class Solution:
    def countOperations(self, a, b):
        if a == 0 or b == 0:
            return 0
        div, mod = divmod(a, b)
        return div + self.countOperations(b, mod)
