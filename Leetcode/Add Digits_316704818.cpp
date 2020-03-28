class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;
        int mod = num % 9; 
        return  mod ? mod : 9;
    }
};
