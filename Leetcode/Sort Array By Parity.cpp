class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ret(A);
        int i = 0;
        int odd_i  = ret.size() - 1;
        while(i < odd_i){
            if(ret[i] & 1) //odd
                swap(ret[i],ret[odd_i--]);
            else              
                i++;
        }
        return ret;
    }
};
