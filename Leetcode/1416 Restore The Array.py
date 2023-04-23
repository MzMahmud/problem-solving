MOD = 1_000_000_007

class Solution:
    def numberOfArrays(self, s, k):
        cache = [None] * len(s)
        def dfs(i):
            if i == len(s):
                return 1
            if cache[i] is not None:
                return cache[i]
            elem, cache[i] = 0, 0
            for j in range(i, len(s)):
                elem = elem * 10 + int(s[j])
                if not (1 <= elem <= k):
                    break
                cache[i] = (cache[i] + dfs(j + 1)) % MOD
            return cache[i]
        return dfs(0)
