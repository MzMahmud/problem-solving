typedef vector<vector<int>> Grid;

class Solution {
public:
    int maxAreaOfIsland(Grid &grid) {
        int max_area = 0;
        for(int i = 0;i < grid.size();++i){
            for(int j = 0;j < grid[0].size();++j){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(i,j,area,grid);
                    max_area = max(max_area,area);
                }
            }
        }
        return max_area;
    }
    
    void dfs(int i,int j,int &area,Grid &grid){
        int i_max = grid.size();
        int j_max = grid[0].size();
        
        if(i < 0 or j < 0 or i >= i_max or j >= j_max or grid[i][j] == 0)
            return;    
        
        grid[i][j] = 0;
        ++area;
        dfs(i - 1,j    ,area,grid);// up
        dfs(i + 1,j    ,area,grid);// down
        dfs(i    ,j - 1,area,grid);// left
        dfs(i    ,j + 1,area,grid);// right
    }
};