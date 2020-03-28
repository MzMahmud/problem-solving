class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {    
        int count = 0;
        int iMax =    grid.size();
        
        if(!iMax) return 0;
        
        int jMax = grid[0].size();
        for(int i = 0;i < iMax;i++){
            for(int j = 0;j < jMax;j++){
                if(grid[i][j] == '1'){
                    count++;
                    floodFill(i,j,grid);
                }       
            }
        }
        return count;
    }
    
    void floodFill(int i,int j,vector<vector<char>>& grid){
        int iMax =    grid.size();
        int jMax = grid[0].size();
        
        if(i < 0 || i >= iMax || 
           j < 0 || j >= jMax || 
           grid[i][j] == '0' )
            return;
        
        grid[i][j] = '0';
        
        floodFill(i + 1,j    ,grid); // down
        floodFill(i - 1,j    ,grid); // up
        floodFill(i    ,j + 1,grid); // right
        floodFill(i    ,j - 1,grid); //left
    }
};
