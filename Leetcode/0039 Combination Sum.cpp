class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> taken;
        vector<vector<int>> out;
        
        int n = candidates.size();
        findSum(out,candidates,n - 1,taken,target);
        return out;
    }

    void findSum(vector<vector<int>>& out,vector<int>& nums,int index,vector<int> taken,int target){
        if(target == 0){
            out.push_back(taken);
            return;
        }

        int n = nums.size();

        if(target < 0 || index < 0)
            return;

        taken.push_back(nums[index]);
        findSum(out,nums,index,taken,target - nums[index]);//take last element

        taken.pop_back();
        findSum(out,nums,index - 1,taken,target);//dont take last element
    } 
};
