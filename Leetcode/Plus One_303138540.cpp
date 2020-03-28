class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(!digits.size())
            return {1};
        
        bool overflow = true;
        for(int digit : digits)
            if(digit != 9){
                overflow = false;
                break;
            }
        
        if(overflow){
            vector<int> res(digits.size() + 1,0);
            res[0] = 1;
            return res;
        }
        
        int i = (int)digits.size() - 1;
        int carry = 1;
        vector<int> res(i+1);
        while(i >= 0){
            if(digits[i] == 9 && carry)
                res[i] = 0,carry = 1;
            else
                res[i] = digits[i] + carry,carry = 0;
            i--;
        }
        return res;
                
    }
};
