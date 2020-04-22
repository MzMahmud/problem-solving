typedef vector<vector<int>> Graph;

class Solution {

  private:
    list<int> order;
    bool has_cycle;
    string color;
    Graph adj;

  public:
    vector<int> findOrder(int n, vector<vector<int>> &prereq) {
        has_cycle = false;

        adj = Graph(n);
        for (int i = 0; i < prereq.size(); ++i) {
            int u = prereq[i][1];
            int v = prereq[i][0];
            adj[u].push_back(v);
        }

        color = string(n, 'w');
        for (int u = 0; u < n; ++u) {
            if (color[u] == 'w') {
                dfs(u);
                if (has_cycle)
                    return {};
            }
        }

        return vector<int>(begin(order), end(order));
    }

    void dfs(int u) {

        if (color[u] != 'w') {
            // color = black -> already visited -> no cycle
            // color = gray  -> back edge       -> cycle
            has_cycle |= (color[u] == 'g');
            return;
        }

        // color <- gray (begin explored)
        color[u] = 'g';

        for (int i = 0; i < adj[u].size(); ++i)
            dfs(adj[u][i]);

        // color <- black (done exploring)
        color[u] = 'b';

        // the ones who end first goes at the back
        // this has the effect of sorting by assending end time
        order.push_front(u);
    }
};