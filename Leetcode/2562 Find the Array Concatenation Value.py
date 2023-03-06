class Solution:
    def findTheArrayConcVal(self, nums):
        total = 0

        i, j = 0, len(nums) - 1
        while i < j:
            total += int(f'{nums[i]}{nums[j]}')
            i += 1
            j -= 1

        if i == j:
            total += nums[i]
        return total
