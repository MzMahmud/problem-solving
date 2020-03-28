class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(!nums.size())
        return;
        
        int j = (int) nums.size() - 1;
        for(int i = 0;i < j;i++){
            if(!nums[i]){
               int k = i + 1;
               while(k < j && !nums[k])
            k++;
        swap(nums[i],nums[k]);
      }
    }
    }
};
