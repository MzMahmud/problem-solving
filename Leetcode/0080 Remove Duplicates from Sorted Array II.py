class Solution:
    def removeDuplicates(self, nums):
        i = 0
        for num in nums:
            if i < 2 or nums[i - 2] != num:
                nums[i] = num
                i += 1
        return i 
