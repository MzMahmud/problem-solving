class Solution:
    def minInsertions(self, s):
        n = len(s)
        cache = [[None] * n for _ in range(n)]
        def min_insertions(i, j):
            if i > j:
                return 0
            if cache[i][j] is not None:
                return cache[i][j]
            if s[i] == s[j]:
                cache[i][j] = min_insertions(i + 1, j - 1)
            else:
                cache[i][j] = 1 + min(min_insertions(i + 1, j), min_insertions(i, j - 1))
            return cache[i][j]
        return min_insertions(0, n - 1)
