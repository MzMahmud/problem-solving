class Solution:
    def maxProfit(self, prices):
        max_profit, buying_price = 0, None
        for price in prices:
            if buying_price is None:
                buying_price = price
                continue
            max_profit = max(max_profit, price - buying_price)
            buying_price = min(buying_price, price)
        return max_profit
