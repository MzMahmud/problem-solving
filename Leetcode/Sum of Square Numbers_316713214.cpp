class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c % 4 == 3)
            return false;
        int lim = sqrt(c + .0);
        for(long long i = 0;i <= lim;i++){
            if(is_square(c - i*i))
                return true;
        }
        return false;
    }
    
    bool is_square(int n){
        return sqrt(n + .0) == (int) sqrt(n + .0);
    }
};
