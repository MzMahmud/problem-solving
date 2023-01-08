inline bool bit_i(int n,int i){return n & (1 << i);}

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0;
        int a_b = a | b;
        
        for(int i = 0;i < 32;i++){
            if(bit_i(a_b,i) != bit_i(c,i)){
                ++flip;
                if(bit_i(a,i) and bit_i(b,i))
                    ++flip;
            }
        }
        return flip;
    }
};