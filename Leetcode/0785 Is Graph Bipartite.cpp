typedef vector<vector<int>> Graph;
typedef vector<char> Color;

#define NO_COLOR -1

class Solution {
public:
    bool isBipartite(Graph &graph) {
        Color color(graph.size(),NO_COLOR);
        
        for(int u = 0;u < graph.size();++u){
            if(color[u] == NO_COLOR)
                if(!dfs(graph,color,u))
                    return false;
        }
        return true;
    }
    
    bool dfs(const Graph &adj,Color &color,int u,bool node_color = 0){
        if(color[u] != NO_COLOR)
            return color[u] == node_color;            
        
        
        color[u] = node_color;
        
        for(int i = 0;i < adj[u].size();++i){
            int v = adj[u][i];
            if(!dfs(adj,color,v,!node_color))
                return false;
        }
        
        return true;
    }
    
};