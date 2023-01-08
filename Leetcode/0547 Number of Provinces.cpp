typedef vector<vector<int>> Matrix;

class Solution {
public:
    int findCircleNum(Matrix &M) {
        vector<bool> visited(M.size(),0);
        int circle = 0;
        for(int u = 0;u < M.size();++u){
            if(!visited[u]){
                ++circle;
                dfs(u,visited,M);
            }
        }
        return circle;
    }
    
    void dfs(int u,vector<bool> &visited,const Matrix &mat){
        if(visited[u]) return;
        
        visited[u] = true;
        for(int v = 0;v < mat[u].size();++v)
            if(mat[u][v] == 1)
                dfs(v,visited,mat);
    }
};