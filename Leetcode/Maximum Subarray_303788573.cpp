class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(!nums.size())
            return 0;
        
        vector<int> max_sum_ending_at(nums.size());
        int max_sum;
        max_sum = max_sum_ending_at[0] = nums[0];
        for(int i = 1;i < nums.size();i++){
            
            max_sum_ending_at[i] = max(nums[i],
                                       nums[i] + max_sum_ending_at[i - 1]);
            
            max_sum = max(max_sum_ending_at[i],max_sum);
        }
        
        return max_sum;
    }
};
