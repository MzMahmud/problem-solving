class Solution:
    def addToArrayForm(self, num, k):
        reverse_inplace(num)
        carry, i = 0, 0
        while i < len(num) or k > 0 or carry > 0:
            if i == len(num):
                num.append(0)
            carry, num[i] = divmod(num[i] + carry + k % 10, 10)
            i, k = i + 1, k // 10
        return reverse_inplace(num)


def reverse_inplace(array):
    i, j = 0, len(array) - 1
    while i < j:
        array[i], array[j] = array[j], array[i]
        i += 1
        j -= 1
    return array
