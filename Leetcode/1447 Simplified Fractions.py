class Solution:
    # farey sequence without 0 and 1
    def simplifiedFractions(self, n):
        a, b, c, d = 0, 1, 1, n
        fractions = []
        a_end = n - 1
        while a < a_end:
            k = (n + b) // d
            a, b, c, d = c, d, k*c - a, k*d - b
            fractions.append(f'{a}/{b}')
        return fractions
