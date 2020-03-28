class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool is_increasing = true;
        bool is_decreasing = true;
        
        for(int i = 1;i < A.size();i++){
            if(A[i - 1] > A[i])
                is_increasing = false;
            
            if(A[i - 1] < A[i])
                is_decreasing = false;
        }
        
        return is_increasing || is_decreasing;
    }
};
