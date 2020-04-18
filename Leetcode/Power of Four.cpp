class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        
        int p = num & (-num);
        if(num != p) // not eve power of two
            return false;
        
        // only even index bit is set
        return (num & 0b01010101010101010101010101010101);
    }
};