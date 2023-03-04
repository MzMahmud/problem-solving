class Solution:
    def countSubarrays(self, nums, min_k, max_k):
        min_position, max_position, left_bound = -1, -1, -1
        count = 0
        for i, number in enumerate(nums):
            if number < min_k or number > max_k:
                left_bound = i

            if number == min_k:
                min_position = i
            
            if number == max_k:
                max_position = i
            
            count += max(0, min(min_position, max_position) - left_bound)
        
        return count
