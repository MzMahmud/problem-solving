class Solution:
    def minimizeArrayValue(self, nums):
        prefix_sum, max_value = 0, 0
        for i, num in enumerate(nums):
            prefix_sum += num
            value = ceil(prefix_sum / (i + 1))
            max_value = max(max_value, value)
        return max_value
