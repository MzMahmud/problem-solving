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
    has_cycle = false;
    color = string(n, 'w');
    for (int u = 0; u < n; ++u) {
        if (color[u] == 'w') {
            dfs(u);
            // if cycle found no ordering
            if (has_cycle)
                cout << "Not a DAG!" << endl;
        }
    }
    // ordering stored in order
    for (const auto &node : order) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    // construct graph
    n = 6;
    adj = Graph(n);
    add_edge(adj, 5, 2);
    add_edge(adj, 5, 0);
    add_edge(adj, 4, 0);
    add_edge(adj, 4, 1);
    add_edge(adj, 2, 3);
    add_edge(adj, 3, 1);

    topological_sort();
    return 0;
}