MOD = 1_000_000_007

class Solution:
    def numOfWays(self, nums):
        m = len(nums)
        nCr = [[0]*(n + 1) for n in range(m)]
        for n in range(m):
            for r in range(n + 1):
                if r == 0 or r == n:
                    nCr[n][r] = 1;
                else:
                    nCr[n][r] = (nCr[n - 1][r] + nCr[n - 1][r - 1]) % MOD
                
        def ways(nums):
            n = len(nums)
            if n < 3:
                return 1
            left, right = [], []
            for i in range(1, n):
                if nums[i] < nums[0]:
                    left.append(nums[i])
                elif nums[i] > nums[0]:
                    right.append(nums[i])
            return (((ways(left) * ways(right)) % MOD) * nCr[n - 1][len(left)]) % MOD;

        return (ways(nums) - 1) % MOD
