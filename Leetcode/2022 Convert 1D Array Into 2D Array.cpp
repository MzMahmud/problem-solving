class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if((m * n) != original.size()) {
            return {};
        }
        int k = 0;
        vector<vector<int>> two_dim_array(m, vector<int>(n,0));
        for(auto &row : two_dim_array) {
            for(auto &elem : row) {
                elem = original[k++];
            }
        }
        return two_dim_array;
    }
};
