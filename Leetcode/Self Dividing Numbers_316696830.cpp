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
        string s = to_string(n);
        for(int i = 0;i < s.size();i++){
            int nd = s[i] - '0';
            if(!nd || n % nd)
                return false;
        }
        return true;
    }
};
