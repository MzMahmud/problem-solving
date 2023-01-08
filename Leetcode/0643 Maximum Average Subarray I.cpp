class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long window_sum = 0;
        for(int i = 0;i < k;++i) {
            window_sum += nums[i];
        }
        long long max_sum = window_sum;
        for(int i = k; i < nums.size();++i) {
            window_sum += (nums[i] - nums[i - k]);
            if(window_sum > max_sum) {
                max_sum = window_sum;
            }
        }
        return (max_sum + .0) / k;
    }
};
