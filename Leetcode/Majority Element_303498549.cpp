class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> occurance;
        int n = nums.size() >> 1;
        for(int num : nums){
            occurance[num]++;
            if(occurance[num] > n)
                return num;
        }
        return -1;
    }
};
