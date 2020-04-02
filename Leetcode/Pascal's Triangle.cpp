class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows < 1)
            return {};
        
        vector<vector<int>> rows;
        
        rows.push_back({1});
        
        for(int i = 1;i < numRows;i++){
            vector<int> row = {1};
            for(int j = 1;j < i;j++)
                row.push_back(rows[i-1][j-1] + rows[i-1][j]);
            row.push_back(1);
            rows.push_back(row);
        }
        
        return rows;
    }
};
