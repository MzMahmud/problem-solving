class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        unsigned int mask = ~0; // all 1
        while(mask & n) {
            mask <<= 1;            
        }
        return ~n & ~mask;
    }
};
