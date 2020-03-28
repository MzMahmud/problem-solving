class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        for(int i = 0;i <= rowIndex;i++)
            row.push_back(C(rowIndex,i));
        return row;
    }
    int C(int n,int k){
        long long res = 1; 
        if (k > n - k) 
        k = n - k; 
        for (int i = 0; i < k; ++i) { 
            res *= (n - i); 
            res /= (i + 1); 
        } 
        return res;         
    }
};
