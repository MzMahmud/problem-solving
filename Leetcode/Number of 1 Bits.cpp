class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        /*for(uint32_t i = 0;i < 32;i++){
            bool bit = n & ( (uint32_t)1 << i );
            if(bit)
                count++;
        }*/
        
        while(n){
            count++;
            n -= (n & -n); 
        }
        return count;
    }
};
