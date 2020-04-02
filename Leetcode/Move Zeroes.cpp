class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        
if(!nums.size())
      return;
      
    for(int lastNonZero = 0,cur = 0;
        cur < nums.size();cur++){
      if(nums[cur])
        swap(nums[lastNonZero++],nums[cur]);
    }

    }
};
