class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> present;
        for(int num : nums){
            if(!present[num])
                present[num] = true;
            else
                return true;
        }
        return false;        
    }
};
