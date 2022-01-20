class Solution {
public:
    string convertToBase7(int num) {
        bool is_negative = false;
        if(num < 0) {
            is_negative = true;
            num = -num;
        }
        string num_base_7 = "";
        do {
            num_base_7.push_back(num % 7 + '0');
            num /= 7;
        } while(num);
        if(is_negative){
            num_base_7.push_back('-');
        }
        reverse(num_base_7.begin(), num_base_7.end());
        return num_base_7;
    }
};
