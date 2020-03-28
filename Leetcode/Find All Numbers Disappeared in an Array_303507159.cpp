class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < nums.size();i++){
            int num = nums[i];
            
            if(num > (n<<1))
                num -= (n<<1);
            else if(num > n)
                num -= n;
            
            nums[num - 1] += n;                
        }
        
        vector<int> missing;
        for(int i = 0;i < nums.size();i++)
            if(nums[i] <= n)
                missing.push_back(i + 1);
        
        return missing;
    }
};
