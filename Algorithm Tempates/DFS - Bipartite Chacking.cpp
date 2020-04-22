#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Graph;

#define NO_COLOR 'n'

int n;
Graph adj;
string color;

bool dfs(int u, char node_color = 'w') {
    // if already colored:
    //      if conflicts with neighbour: not bipartite
    if (color[u] != NO_COLOR)
        return (color[u] == node_color);

    color[u] = node_color;

    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!dfs(v, (node_color == 'b') ? 'w' : 'b'))
            return false;
    }

    return true;
}

bool is_bipartite() {
    color = string(n, NO_COLOR);
    for (int u = 0; u < n; ++u) {
        if (color[u] == NO_COLOR)
            if (!dfs(u))
                return false;
    }
    return true;
}

void add_edge(Graph &g, int u, int v) { g[u].push_back(v); }

int main() {
    adj = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << boolalpha << is_bipartite() << endl;
    return 0;
}