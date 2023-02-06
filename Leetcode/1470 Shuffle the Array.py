class Solution:
    # O(n) time, O(1) space
    # found this solution by traking what values goes where
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

    MAX_BIT_SIZE = 10
    BIT_MASK = (1 << MAX_BIT_SIZE) - 1

    # O(n) time, O(1) space
    # seen solution and got the idea to store new values in higher bits
    def shuffle(self, nums, n):
        i, j, k = 0, n, 0
        while i < n:
            # get previous value stored in last bits
            x_value = nums[i] & Solution.BIT_MASK
            # store updated value in front bits
            nums[k] |= (x_value << Solution.MAX_BIT_SIZE)

            y_value = nums[j] & Solution.BIT_MASK
            nums[k + 1] |= (y_value << Solution.MAX_BIT_SIZE)

            i, j, k = i + 1, j + 1, k + 2

        for i in range(2 * n):
            # store new value stored in front bits
            nums[i] >>= Solution.MAX_BIT_SIZE

        return nums
