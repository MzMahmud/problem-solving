class Solution {
public:
    vector<vector<int>> out;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> taken;
        findSum(candidates,taken,target);
        return out;
    }
    void findSum(vector<int> nums,vector<int> taken,int target){
        if(target == 0){
            out.push_back(taken);
            return;
        }

        int n = nums.size();

        if(target < 0 || n == 0)
            return;

        taken.push_back(nums[n - 1]);
        findSum(nums,taken,target - nums[n - 1]);//take last element

        taken.pop_back();
        nums.pop_back();
        findSum(nums,taken,target);//dont take last element
    } 
    
};
