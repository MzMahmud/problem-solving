class Solution {
public:
    int trailingZeroes(int n) {
        int zeros = 0;
        long long pow_5 = 5;
        
        while(pow_5 <= n){
            zeros += (n/pow_5);
            pow_5 *= 5;
        }
        return zeros;
    }
};
