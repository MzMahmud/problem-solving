class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> out;
        for(int n = left;n <= right;n++){
            if(is_self_dividing(n))
                out.push_back(n);
        }
        return out;
    }
    bool is_self_dividing(int n){
        int num = n;
        while(num){
            int d = num % 10;
            
            if(!d || n % d)
                return false;
            
            num /= 10;
        }
        return true;
    }
};
