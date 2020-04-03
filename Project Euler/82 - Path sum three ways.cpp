#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

struct Node {
    int at, cost;
    Node(int _at, int _cost) {
        at   = _at;
        cost = _cost;
    }
};
bool operator<(Node A, Node B) { return A.cost > B.cost; }

struct Edge {
    int v, w;
    Edge(int _v, int _w) {
        v = _v;
        w = _w;
    }
};

int dijkstra(int s, int d, vector<vector<Edge>> adj) {
    int n = adj.size();

    vector<int> dist(n, INF);
    dist[s] = 0;

    priority_queue<Node> PQ;
    PQ.push(Node(s, dist[s]));

    while (!PQ.empty()) {
        Node u = PQ.top();
        PQ.pop();
        for (int i = 0; i < adj[u.at].size(); i++) {
            Edge e = adj[u.at][i];
            if (dist[e.v] > dist[u.at] + e.w) {
                dist[e.v] = dist[u.at] + e.w;
                PQ.push(Node(e.v, dist[e.v]));
            }
        }
    }
    return dist[d];
}

void print(vector<vector<Edge>> adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << "-> ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << "(" << adj[i][j].v << "," << adj[i][j].w << ") ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    // construct the Graph
    vector<vector<Edge>> adj(n * n + 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - 1); j++) {
            // j < n - 1 because right-most dont need up,left,right

            int m_index = i * n + j;
            // Up
            if ((i - 1) >= 0) {
                int index = (i - 1) * n + j;
                int w     = grid[i][j] + grid[i - 1][j];
                adj[m_index].emplace_back(index, w);
            }

            // Down
            if ((i + 1) < n) {
                int index = (i + 1) * n + j;
                int w     = grid[i][j] + grid[i + 1][j];
                adj[m_index].emplace_back(index, w);
            }

            // Right
            if ((j + 1) < n) {
                int index = i * n + j + 1;
                int w     = grid[i][j] + grid[i][j + 1];
                adj[m_index].emplace_back(index, w);
            }
        }
    }

    int s = n * n, d = n * n + 1;
    for (int i = 0; i < n; i++) {
        int index, w;

        // n[source] to (i,0) to left most
        index = i * n + 0;
        w     = grid[i][0];
        adj[s].emplace_back(index, w);

        // (n+1)[dest] to (i,n-1)
        index = i * n + n - 1;
        w     = grid[i][n - 1];
        adj[index].emplace_back(d, w);
    }

    cout << "min path cost " << dijkstra(s, d, adj) / 2 << endl;
    // divided by two because by version of the constructed graph
    // each grid position is taken twice
    // so the answer would be min cost/2

    return 0;
}