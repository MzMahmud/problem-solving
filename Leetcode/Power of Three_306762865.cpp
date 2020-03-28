class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        
        double num = log10(n)/log10(3.0);
        return ((int)num) == num;
    }
};

