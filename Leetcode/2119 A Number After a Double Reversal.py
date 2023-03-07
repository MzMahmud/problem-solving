class Solution:
    def isSameAfterReversals(self, number):
        return number == 0 or number % 10 != 0
