from math import sqrt


class Solution:
    def pivotInteger(self, n):
        square = (n * (n + 1)) >> 1
        root = sqrt(square)
        root_int = int(root)
        return root_int if root_int == root else -1
