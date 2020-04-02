class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> ret(A.size());
        
        int even_i = 0;
        int  odd_i = 1;
        for(int i = 0;i < A.size();i++){
            if(A[i] & 1){
                ret[odd_i] = A[i];
                odd_i += 2;
            }else{
                ret[even_i] = A[i];
                even_i += 2;
            }
        }
        
        return ret;
    }
};
