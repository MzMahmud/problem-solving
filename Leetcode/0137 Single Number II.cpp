class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        
        int missing = 0,bit_sum;
        
        for(int i = 0;i < 32;i++){
            bit_sum = 0;
            
            for(int num : nums)
                if(num & (1<<i))
                    bit_sum++;

            if(bit_sum % 3)
                missing |= (1<<i);
        }
        
        return missing;
    }
};


