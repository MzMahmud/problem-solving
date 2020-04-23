// UVA - 10305 Ordering Tasks

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Graph;

// Topological Sort Order
list<int> order;
bool has_cycle;
string color;
Graph adj;
int n;

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

void add_edge(Graph &g, int u, int v) { g[u].push_back(v); }

void topological_sort() {
    // run dfs for each connected component
    order.clear();
    has_cycle = false;
    color = string(n, 'w');
    for (int u = 0; u < n; ++u) {
        if (color[u] == 'w') {
            dfs(u);
            // if cycle found no ordering
            if (has_cycle) {
                cout << "Not a DAG!" << endl;
                return;
            }
        }
    }
    // ordering stored in order
    int i = 0;
    for (const auto &node : order) {
        ++i;
        cout << (node + 1) << (i == n ? "\n" : " ");
    }
}

int main() {
    int m;
    while ((cin >> n >> m) and (n or m)) {
        adj = Graph(n);
        while (m--) {
            int u, v;
            cin >> u >> v;
            add_edge(adj, u - 1, v - 1);
        }
        topological_sort();
    }
    return 0;
}