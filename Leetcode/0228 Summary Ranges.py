class Solution:
    def summaryRanges(self, nums):
        n = len(nums)
        if n == 0:
            return []
        ranges = []
        a, b = nums[0], nums[0]
        for num in nums:
            if num <= (b + 1):
                b += int(num == (b + 1))
            else:
                ranges.append(f'{a}' if a == b else f'{a}->{b}')
                a, b = num, num
        ranges.append(f'{a}' if a == b else f'{a}->{b}')
        return ranges
