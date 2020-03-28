class Solution {
public:
    bool hasAlternatingBits(int n) {
        n = (n ^ (n >> 1));
        
        /* 101010
         * 010101 (xor)
           111111  
         */
        
        bool ans = true;
        bool foundMSB = false;
        for(int i = 31;i >= 0;i--){
            bool bit = n & (1 << i);
            if(bit)
                foundMSB = true;
            if(foundMSB)
                ans &= bit; 
        }
        return ans;
    }
};
