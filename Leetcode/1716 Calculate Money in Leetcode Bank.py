MONEY_IN_A_WEEK = 28
DAYS_IN_A_WEEK = 7


class Solution:
    def totalMoney(self, n: int) -> int:
        full_weeks, extra_days = divmod(n, DAYS_IN_A_WEEK)
        money = MONEY_IN_A_WEEK * full_weeks
        money += DAYS_IN_A_WEEK * full_weeks * (full_weeks - 1) // 2
        money += full_weeks * extra_days
        money += extra_days * (extra_days + 1) // 2
        return money
