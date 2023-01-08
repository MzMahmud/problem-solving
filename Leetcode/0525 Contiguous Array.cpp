// Explaination: https://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        
        int max_size = -1,sum = 0;
        
        unordered_map<int,int> sum_min_index;
        sum_min_index[0] = -1;
        
        for(int i = 0;i < n;i++){
            sum += (nums[i]? 1 : -1); 
            
            if(sum_min_index.find(sum) != sum_min_index.end())
                max_size = max(max_size,i - sum_min_index[sum]);
            else
                sum_min_index[sum] = i;
        }
        
        return (max_size < 0)? 0 : max_size; 
    }
};