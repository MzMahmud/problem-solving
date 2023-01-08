class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int num : nums){
            int digits = floor(log10(num)) + 1;
            if(!(digits & 1))
                count++;
        }
        return count;
    }
};
