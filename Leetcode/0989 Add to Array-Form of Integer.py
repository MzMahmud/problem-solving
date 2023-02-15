class Solution:
    def addToArrayForm(self, num, k):
        sum_array, carry = [], 0
        i = len(num) - 1
        while i >= 0 or k > 0 or carry > 0:
            if i >= 0:
                carry += num[i]
            if k > 0:
                carry += k % 10

            sum_array.append(carry % 10)
            carry //= 10
            i -= 1
            k //= 10

        i, j = 0, len(sum_array) - 1
        while i < j:
            sum_array[i], sum_array[j] = sum_array[j], sum_array[i]
            i += 1
            j -= 1

        return sum_array
