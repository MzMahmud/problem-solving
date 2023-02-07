class Solution:
    def countPrimes(self, n):
        if n < 3:
            return 0
        if n == 3:
            return 1

        nums = (n - 4) // 2 + 1
        is_prime = [True] * nums
        for i in range(3, n, 2):
            i_index = (i - 3) // 2
            if not is_prime[i_index]:
                continue
            j = i * i
            while (index := (j - 3) // 2) < nums:
                is_prime[index] = False
                j += (2 * i)

        return 1 + sum(is_prime)
