class Solution {
public:
    int getSum(int a, int b) {
        bool carry = false;
        int sum = 0;
        
        for(int i = 0;i < 32;i++){
            bool a_bit = a & (1 << i);
            bool b_bit = b & (1 << i);
            
            bool sum_bit = a_bit ^ b_bit ^ carry;
            if(sum_bit)
                sum = sum | (1 << i);
            
            carry = ((a_bit ^ b_bit) & carry) | (a_bit & b_bit);  
        }
        return sum;
    }
};
