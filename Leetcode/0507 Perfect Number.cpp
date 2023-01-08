class Solution {
public:
    bool checkPerfectNumber(int n) {
        if(n <= 0) return false;
        
        int sod = 0;
        for(int i = 1;i*i <= n;i++){
            if(!(n % i)){
                if(i != n)
                   sod += i;
                if(i != 1 && i != (n/i))
                   sod += (n/i);
            }
        }
        return sod == n;
    }
};
