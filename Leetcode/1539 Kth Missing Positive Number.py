class Solution:
    # O(n) time, O(1) space
    def findKthPositive(self, array, k):
        last_missing, n_missing = 1, 0
        for n in array:
            new_n_missing = n_missing + n - last_missing
            if new_n_missing >= k:
                break
            n_missing = new_n_missing
            last_missing = n + 1
        return last_missing + k - n_missing - 1
