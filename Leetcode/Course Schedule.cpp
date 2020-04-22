typedef vector<vector<int>> Graph;
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        Graph adj(n);
        for(int i = 0;i < prerequisites.size();++i){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
        
        vector<char> color(n,'w');
        for(int u = 0;u < n;++u){
            if(color[u] == 'w'){
                if(has_cycle(u,color,adj))
                    return false;
            }
        }
        return true;
    }
    
    bool has_cycle(int u,vector<char> &color,const Graph &adj){
        
        // color = gray -> back edge -> has cycle
        if(color[u] == 'g')
            return true;
        
        // color = black -> forward edge -> already visited
        if(color[u] == 'b')
            return false;
        
        color[u] = 'g';
        
        for(int i = 0;i < adj[u].size();++i){
            int v = adj[u][i];
            if(has_cycle(v,color,adj))
                return true;
        }
        
        color[u] = 'b';
        return false;
    }
};