class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> indexOf;
        
        for(int i = 0;i < nums.size();i++){
            if(indexOf.find(nums[i]) == indexOf.end()){
                indexOf[nums[i]] = i;
            }else if( (i - indexOf[nums[i]]) <= k){
                return true;
            }else{
                indexOf[nums[i]] = i;
            }
        }
        return false;
    }
};
