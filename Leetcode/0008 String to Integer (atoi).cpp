class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(s[i] == ' ') i++;
        
        if(!is_valid_first_char(s[i]))
            return 0;
        
        bool is_neg = false;
        if(s[i] == '-'){
            is_neg = true;
            i++;
        }else if(s[i] == '+'){
            i++;
        }
        
        unsigned int num = 0;
        
        while(i < s.size()){
            if(!is_digit(s[i])) break;
            
            unsigned int d = s[i] - '0';
            
            unsigned int limit = (INT_MAX - d)/10;
            
            if(num > limit)
                return is_neg? INT_MIN : INT_MAX;
            
            num = num * 10 + d;
            i++;
        }
        
        if(num == (1 << 31) and !is_neg)
            return INT_MAX;
        
        return is_neg? -num : num;
    }
    
    
    bool is_valid_first_char(char c){
        return is_digit(c) or (c == '+') or (c == '-');
    }
    bool is_digit(char c){
        return '0' <= c and c <= '9';
    }
};