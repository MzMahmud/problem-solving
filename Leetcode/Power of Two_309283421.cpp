class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        /*
        bool foundMSB = false;
        bool ans = true;
        
        n--;
        for(int i = 31;i >= 0;i--){
            bool bit = (n & (1<<i));
            if(bit)
               foundMSB = true;
            if(foundMSB)
               ans &= bit;        
        }
        return ans;
        // n - 1 = all ones in binary if n is a power of two
        // 8 - 1 = 7 = (111)_2
        // 8 - 1 = 7 = (111)_2
        */
        return !(n - (n & (-n)));
    }
};
