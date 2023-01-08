#define ABS(x) ( (x) < 0? -1*(x) : (x) )

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate = -1; 
        for(int i = 0;i < nums.size();i++){
            int index = ABS(nums[i]) - 1;
            if(nums[index] < 0){
                duplicate = index + 1;
                break;
            }else
                nums[index] *= -1;    
        }
        
        for(int i = 0;i < nums.size();i++)
            nums[i] = ABS(nums[i]);
        return duplicate;
    }
};
