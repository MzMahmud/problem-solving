class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> out;
        for(int n = left;n <= right;n++){
            if(is_self_dividing(n))
                out.emplace_back(n);
        }
        return out;
    }
    bool is_self_dividing(int n){
        string s = to_string(n);
        for(char d : s){
            int nd = d - '0';
            if(!nd || n % nd)
                return false;
        }
        return true;
    }
};
