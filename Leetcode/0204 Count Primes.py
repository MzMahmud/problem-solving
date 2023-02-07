from math import sqrt

class Solution:
    def countPrimes(self, n):
        if n < 2:
            return 0
        
        is_prime = [1] * n
        is_prime[0] = 0
        is_prime[1] = 0
        
        limit = int(sqrt(n)) + 1
        for i in range(2, limit):
            if is_prime[j] == 0:
                continue

            for j in range(i*i, n, i):
                is_prime[j] = 0 

        return sum(is_prime)
