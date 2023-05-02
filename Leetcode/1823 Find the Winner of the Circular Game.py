class Solution:
    def findTheWinner(self, n, k):
        return josephus(n, k) + 1

def josephus(n, k):
    return 0 if n == 1 else (josephus(n - 1, k) + k) % n 
