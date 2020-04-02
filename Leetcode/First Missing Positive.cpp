class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // with O(n+1) space,O(n) time
        
        bool present[n+1] = {};
        
        for(int num : nums){
            if(0 < num && num <= n)
                present[num - 1] = true;
        }
        
        for(int i = 0;i <= n;i++)
            if(!present[i])
                return i + 1;
        
        return -1;
    }
};
