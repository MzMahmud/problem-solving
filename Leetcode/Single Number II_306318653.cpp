class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int missing = 0;
        
        for(int i = 0;i < 32;i++){
            int bit_sum = 0;
            
            for(int num : nums)
                if(num & (1<<i))
                    bit_sum++;

            if(bit_sum % 3)
                missing = missing | (1<<i);
        }
        
        return missing;
    }
};


