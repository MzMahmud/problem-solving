class Solution:
    def digitSum(self, string, k):
        while len(string) > k:
            string = "".join(sum_of_group(string, k))
        return string


def sum_of_group(string, k):
    s_len = len(string)
    for i in range(0, s_len, k):
        j = min(i + k, s_len)
        yield digit_sum(string, i, j)


def digit_sum(string, i, j):
    sum_of_digit = 0
    while i < j:
        sum_of_digit += int(string[i])
        i += 1
    return f"{sum_of_digit}"
