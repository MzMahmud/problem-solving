"""
Solution
https://leetcode.com/problems/airplane-seat-assignment-probability/solutions/3179809/0-5-if-n-1-else-1-math-proof/ 
"""
class Solution:
    def nthPersonGetsNthSeat(self, n):
        return .5 if n > 1 else 1
