class Solution:
    def alternateDigitSum(self, n: int) -> int:
        sign, alt_sum = 1, 0
        for d in str(n):
            alt_sum += int(d) * sign
            sign *= -1
        return alt_sum
