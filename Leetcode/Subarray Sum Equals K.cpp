class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sum_count;
        sum_count[0] = 1;
        int sum = 0,ans = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            int need = sum - k;
            
            if(sum_count.find(need) != sum_count.end())
                ans += sum_count[need];
            
            sum_count[sum]++;
        }
        return ans;
    }
};