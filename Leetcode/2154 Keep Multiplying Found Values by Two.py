MAX_VAL = 1000


class Solution:
    def findFinalValue(self, nums, original):
        present = [False] * (MAX_VAL + 1)
        for num in nums:
            present[num] = True

        while original <= MAX_VAL and present[original]:
            original <<= 1

        return original
