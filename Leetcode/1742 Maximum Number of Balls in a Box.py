MAX_DIGIT_SUM = 50


class Solution:
    def countBalls(self, start, end):
        digit_sums = [0] * MAX_DIGIT_SUM
        for n in range(start, end + 1):
            digit_sum = sum(map(int, str(n)))
            digit_sums[digit_sum] += 1
        return max(digit_sums)
