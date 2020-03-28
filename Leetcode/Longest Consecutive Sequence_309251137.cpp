class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        
        sort(nums.begin(),nums.end());
        int ans[nums.size()],max_ans = 1;
        ans[0] = 1;
        for(int i = 1;i < nums.size();i++){
            int diff = nums[i] - nums[i - 1]; 
            if(diff == 1){
                ans[i] = ans[i - 1] + 1;
            }else if(!diff){
                ans[i] = ans[i - 1];
            }else{
                ans[i] = 1;
            }
            max_ans = max(max_ans,ans[i]);
        }
        return max_ans;
    }
};
