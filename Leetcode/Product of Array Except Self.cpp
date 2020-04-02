class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //O(n) time,O(1) extra space
        int n = nums.size();
        vector<int> left(n);
        
        left[0] = 1;
        for(int i = 1;i < n;i++)
            left[i]  = left[i - 1]*nums[i - 1];

        int right = 1;
        for(int i = n - 2;i >= 0;i--){
            right   *= nums[i + 1]; 
            left[i] *= right;
        }
        return left;
    }
};
