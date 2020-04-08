class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // bottom up dp
        for(int i = m - 1;i >= 0;i--){
            for(int j = n - 1;j >= 0;j--){
                
                // base case
                if(i == (m-1) && j == (n-1))
                    continue;
                
                //Only Down
                if(j == (n - 1))
                    grid[i][j] += grid[i+1][j]; 
                
                //Only Right
                else if(i == (m - 1))
                    grid[i][j] += grid[i][j+1];
                
                // both options
                else
                    grid[i][j] += min(grid[i][j+1],grid[i+1][j]);
            }
        } 
        return grid[0][0];
    }
};