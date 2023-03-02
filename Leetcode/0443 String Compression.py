class Solution:
    def compress(self, chars):
        n = len(chars)
        i, k = 0, 0
        for j in range(n + 1):
            if j == n or chars[i] != chars[j]:
                chars[k] = chars[i]
                k += 1
                run_len = j - i
                if run_len > 1:
                    for d in str(run_len):
                        chars[k] = d
                        k += 1
                i = j
        return k
