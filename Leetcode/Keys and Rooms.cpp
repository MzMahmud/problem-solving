class Solution {
    int count;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        count = 0;
        dfs(0,visited,rooms);
        return count == rooms.size();
    }
    
    void dfs(int u,vector<bool> &visited,vector<vector<int>>& rooms){
        if(visited[u]) return;
        
        visited[u] = true;
        ++count;
        
        for(int v : rooms[u])
            dfs(v,visited,rooms);
    }
};