class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        // Transpose
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);

        // swap column
        for (int i = 0; i < matrix.size(); i++) {
            int start = 0;
            int end   = matrix[i].size() - 1;
            while (start < end)
                swap(matrix[i][start++], matrix[i][end--]);
        }
    }
};
