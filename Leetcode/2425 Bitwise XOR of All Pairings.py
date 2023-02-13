from functools import reduce


class Solution:
    def xorAllNums(self, nums_1, nums_2):
        all_xor = 0

        if len(nums_1) % 2 == 1:
            all_xor ^= reduce(xor, nums_2)

        if len(nums_2) % 2 == 1:
            all_xor ^= reduce(xor, nums_1)

        return all_xor


def xor(a, b):
    return a ^ b
