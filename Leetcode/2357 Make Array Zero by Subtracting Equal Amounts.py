class Solution:
    def minimumOperations(self, nums):
        uniques = set(nums)
        uniques.discard(0)
        return len(uniques)
