class Solution:
    def countEven(self, num: int) -> int:
        return sum(map(lambda _: 1, filter(is_digit_sum_even, range(2, num + 1))))


def digit_sum(n):
    return sum(map(int, str(n)))


def is_digit_sum_even(n):
    return digit_sum(n) % 2 == 0
