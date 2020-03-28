class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> count;
        
        for(int num : nums)
            count[num]++;
        
        int ans;
        for(int num : nums){
            if(count[num] > 1){
                ans = num;
                break;
            }
        }
        return ans;
    }
};   
