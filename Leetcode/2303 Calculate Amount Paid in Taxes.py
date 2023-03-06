class Solution:
    def calculateTax(self, brackets, income):
        total_tax, lower = 0, 0
        for upper, percent in brackets:
            if income <= lower:
                break
            taxable = min(upper, income) - lower
            total_tax += taxable * percent / 100
            lower = upper
        return total_tax
