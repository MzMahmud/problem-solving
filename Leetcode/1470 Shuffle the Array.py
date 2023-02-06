class Solution:
    def shuffle(self, nums, n):
        shuffled = list(nums)
        
        i, j, k = 0, n, 0
        while j < len(nums):
            shuffled[k] = nums[i]
            shuffled[k + 1] = nums[j]
            i += 1
            j += 1
            k += 2

        return shuffled