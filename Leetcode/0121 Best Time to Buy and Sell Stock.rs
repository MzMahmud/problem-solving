impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let (mut maximum_profit, mut buying_price) = (0, -1);
        for price in prices {
            if buying_price < 0 {
                buying_price = price;
                continue;
            }
            maximum_profit = std::cmp::max(maximum_profit, price - buying_price);
            buying_price = std::cmp::min(buying_price, price);
        }
        maximum_profit
    }
}