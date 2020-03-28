class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //vector<int> index;
        unordered_map<int,int> look_up;
        
        for(int i = 0;i < nums.size();i++){
            
            if(look_up.find(target-nums[i])!= look_up.end())
                return {look_up[target-nums[i]],i};
            
            look_up[nums[i]]=i;
            
        }
        return {};
        
    }
};
