class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for(int i = L;i <= R;i++)
            if(is_prime(set_bit_count(i)))
                ++ans;
        return ans;
    }
    
    int set_bit_count(int n){
        int set_bits = 0;
        while(n){
            set_bits += (n & 1);
            n >>= 1;
        }
        return set_bits;
    }
    
    bool is_prime(int n){
        if(n < 2)    return false;
        if(n == 2)   return true;
        if(!(n & 1)) return false;
        
        for(int i = 3;i*i <= n;i += 2)
            if(!(n % i))
                return false;
        return true;
    }
};
