class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() < 2)
            return true;
        
        bool is_increasing = true;
        for(int i = 1;i < A.size();i++)
            if(A[i - 1] > A[i]){
                is_increasing = false;
                break;
            }
        if(is_increasing)
            return true;
        
        bool is_decreasing = true;
        for(int i = 1;i < A.size();i++)
            if(A[i - 1] < A[i]){
                is_decreasing = false;
                break;
            }
        if(is_decreasing)
            return true;
        
        return false;
    }
};
