class Solution {
    int get_wealth(const vector<int> &account) {
        int wealth = 0;
        for(const int &money : account) {
            wealth += money;
        }
        return wealth;
    }
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = INT_MIN;
        for(const auto &account : accounts) {
            max_wealth = max(max_wealth, get_wealth(account));
        }
        return max_wealth;
    }
};
