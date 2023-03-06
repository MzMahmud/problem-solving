class Solution:
    # O(log n) time, O(1) space
    def findKthPositive(self, array, k):
        last_missing, n_missing = 1, 0
        
        lo, hi = 0, len(array) - 1
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            new_n_missing = array[mid] - mid - 1
            if new_n_missing < k:
                lo = mid + 1
                n_missing = new_n_missing
                last_missing = array[mid] + 1
            else:
                hi = mid - 1

        return last_missing + k - n_missing - 1

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
