class Solution:
    def jump(self, nums):
        n = len(nums)
        if n == 1:
            return 0

        jump, steps, max_reach = 1, nums[0], nums[0]
        for i in range(1, n - 1):
            max_reach = max(max_reach, i + nums[i])
            steps -= 1
            if steps == 0:
                jump += 1
                steps = max_reach - i

        return jump
