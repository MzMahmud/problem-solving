class Solution:
    def replaceNonCoprimes(self, nums):
        stack = []
        for n in nums:
            while (g := gcd(n, stack[-1] if stack else 1)) != 1:
                n *= stack.pop() // g
            stack.append(n)
        return stack

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)  
