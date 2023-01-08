class Solution {
public:
    bool canJump(vector<int>& nums) {
        int can_reach = 0;
        for(int i = 0;i < nums.size();++i){
            if(can_reach < i) return false;
            can_reach = max(can_reach,i + nums[i]);
        }
        return true;        
    }
};