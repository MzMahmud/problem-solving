class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> sorted_square(A.size());
        int i = 0;
        int j = (int) A.size() - 1;
        int k = (int) A.size() - 1;
        
        while(i <= j){
            int square_i = A[i]*A[i];
            int square_j = A[j]*A[j]; 
            
            if(square_i > square_j){
                sorted_square[k] = square_i;
                i++;
            }else{
                sorted_square[k] = square_j;
                j--;
            }
            k--;
        }
        return sorted_square;
    }
};
