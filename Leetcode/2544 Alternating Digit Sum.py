class Solution:
    def alternateDigitSum(self, n: int) -> int:
        sign, alt_sum = 1, 0
        while n > 0:
            alt_sum += sign * (n % 10)
            n //= 10
            sign *= -1
        return -1 * sign * alt_sum
