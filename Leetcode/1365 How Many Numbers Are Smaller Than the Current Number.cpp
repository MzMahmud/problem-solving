// O(n) solution for 0<=nums[i]<=100
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int a[101] = {};// as 0 <= nums[i] <= 100
        for(int n : nums)
            a[n]++;
        
        for(int i = 1;i <= 100;i++)
            a[i] += a[i - 1];
        
        vector<int> out(nums.size());
        for(int i = 0;i < nums.size();++i)
            out[i] = nums[i] ? a[nums[i] - 1] : 0;
        
        return out;
    }
};

/* General O(nlogn) solution 
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,vector<int>> ni;
        
        int i = 0;
        for(int n : nums){
            ni[n].push_back(i);
            i++;
        }
        
        vector<int> out(nums.size());
        int less = 0;
        for(auto p : ni){
            for(auto i : p.second){
                out[i] = less;
            }
            less += p.second.size();
        }
        return out;
    }
};*/