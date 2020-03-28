class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c % 4 == 3)
            return false;
        
        for(long long a = 0;a*a <= c;a++){
            double b = sqrt(c - a*a + .0);
            if(b == (int) b)
                return true;
        }
        return false;
    }
    
};
