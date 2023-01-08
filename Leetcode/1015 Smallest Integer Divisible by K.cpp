class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0)
            return -1;
        
        int mod = 1,digits = 1;
        while(mod % k){
            ++digits;
            mod = (10*mod + 1) % k;
        }
        return digits;
    }
};
