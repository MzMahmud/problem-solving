class Solution:
    def searchInsert(self, nums, target):
        lo, hi = 0, len(nums) - 1
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                lo = lo + 1
            else:
                hi = hi - 1
        return mid if target < nums[mid] else mid + 1
