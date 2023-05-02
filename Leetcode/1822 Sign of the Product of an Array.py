sig_num = lambda n: 0 if n == 0 else (-1 if n < 0 else 1)

class Solution:
    def arraySign(self, nums):
        return reduce(lambda sign, n: sign*sig_num(n), nums, 1)
      
