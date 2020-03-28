class Solution {
public:
    // Kadan's Algo
    int maxSubArray(vector<int>& nums) {
        if(!nums.size())
            return 0;
        
        int max_sum_ending_at_i_1;
        int max_sum;
        max_sum = max_sum_ending_at_i_1 = nums[0];
        for(int i = 1;i < nums.size();i++){
            
            max_sum_ending_at_i_1 = max(nums[i],
                                        nums[i] + max_sum_ending_at_i_1);
            
            max_sum = max(max_sum_ending_at_i_1,max_sum);
        }
        
        return max_sum;
    }
};
