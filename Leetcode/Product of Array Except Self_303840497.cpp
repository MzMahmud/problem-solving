class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //O(n) time,O(3n) = O(n) space
        
        int n = nums.size();
        
        vector<int> left(n);
        vector<int> right(n);
        vector<int> output(n);

        
        left[0] = right[n-1] = 1;
        
        for(int i = 1;i < n;i++)
            left[i]  = left[i - 1]*nums[i - 1];
        for(int i = n - 2;i >= 0;i--)
            right[i] = right[i + 1]*nums[i + 1];
        
        for(int i = 0;i < n;i++)
            output[i] = left[i]*right[i];
        
        return output;
    }
};
