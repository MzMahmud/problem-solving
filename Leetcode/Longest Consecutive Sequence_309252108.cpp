class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        
        sort(nums.begin(),nums.end());
        
        int currentStreak = 1;
        int longestStreak = 1;
        
        for(int i = 1;i < nums.size();i++){
            int diff = nums[i] - nums[i - 1]; 
            if(diff == 1){
                currentStreak++;
            }else if(diff == 0){
                
            }else{
                longestStreak = max(longestStreak,currentStreak);
                currentStreak = 1;
            }
        }
        longestStreak = max(longestStreak,currentStreak);
        return longestStreak;
    }
};
