class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        
        int count = 0;
        for(int  i = 0;i < 32;++i)
            count += (bool)(diff & (1 << i));
        return count;
    }
};