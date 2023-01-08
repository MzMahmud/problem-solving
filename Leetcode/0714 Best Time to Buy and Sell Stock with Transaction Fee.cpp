class Solution {
    vector<vector<int>> dp;
public:
    int maxProfit(vector<int>& prices,int fee) {
        dp = vector<vector<int>>(prices.size(),vector<int>(2,-1));
        return profit(prices,fee);;
    }
    double profit(const vector<int>& prices,int fee,int i = 0, int bought = 0) {
        if (i == prices.size())
            return 0;

        if(dp[i][bought] < 0){
            
            int &ans = dp[i][bought];
            
            if (bought) {
                // sell
                int sell = profit(prices,fee,i + 1, !bought) + prices[i] - fee;

                // skip
                int skip = profit(prices,fee,i + 1, bought);
                ans = max(sell, skip);
            } else {
                // buy
                int buy = profit(prices,fee,i + 1, !bought) - prices[i];

                // skip
                int skip = profit(prices,fee,i + 1, bought);
                ans = max(buy, skip);
            }
        }
        
        return dp[i][bought];
    }
};