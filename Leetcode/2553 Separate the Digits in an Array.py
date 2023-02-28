class Solution:
    def separateDigits(self, nums):
        separate = []
        for num in nums:
            separate.extend(str(num))
        return list(map(int, separate))
