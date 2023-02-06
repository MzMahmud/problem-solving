class Solution:
    # O(n) time, O(1) space
    def shuffle(self, nums, n):
        length = 2 * n

        for start in range(1, n):
            # if number is visited skip this start position
            if nums[start] < 0:
                continue

            prev_value, curr = nums[start], 2 * start
            while True:
                curr_nums = nums[curr]
                # as 1 <= nums[i] <= 10^3 put a negative number 
                # to indicate that this position is already visited
                nums[curr] = -prev_value 
                prev_value = curr_nums

                if curr == start:
                    break

                curr += curr if curr < n else curr - length + 1

        for i in range(length):
            nums[i] = abs(nums[i])

        return nums