class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0;
        
        for(auto c : s){
            if(c == ')')
                --balance;
            else
                ++balance;
            
            if(balance < 0)
                return false;
        }
        
        
        balance = 0;
        reverse(begin(s),end(s));
        for(auto c : s){
            if(c == '(')
                --balance;
            else
                ++balance;
            
            if(balance < 0)
                return false;
        }
        return true;
    }
};