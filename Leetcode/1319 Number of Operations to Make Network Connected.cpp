class Solution {
public:
    int makeConnected(int n, const vector<vector<int>> &connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        auto adjList = getAdjList(n, connections);
        vector<bool> visited(n, false);
        int nConnectedComponents = 0;
        for(int start = 0; start < n; start++) {
            if(!visited[start]) {
                dfs(start, adjList, visited);
                nConnectedComponents++;
            }
        }
        return nConnectedComponents - 1;
    }

    vector<vector<int>> getAdjList(int n, const vector<vector<int>> &edges) {
        vector<vector<int>> adjList(n, vector<int>());
        for(auto &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    }

    void dfs(int start, const vector<vector<int>> &adjList, vector<bool>& visited) {
        if (visited[start]) {
            return;
        }
        visited[start] = true;
        for(auto child : adjList[start]) {
            dfs(child, adjList, visited);
        }
    }
};
