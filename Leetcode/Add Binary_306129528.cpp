class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        string sum = "";
        
        while(i >= 0 || j >= 0){
            int ai = i < 0? 0 : a[i--] - '0';
            int bj = j < 0? 0 : b[j--] - '0';
            
            int sm = ai + bj + carry;
            sum    = to_string(sm & 1) + sum;
            carry  = sm >> 1;
        }
        
        if(carry)
            sum = to_string(1) + sum;
        
        return sum;
    }
};
