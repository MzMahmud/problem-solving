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

/*
 * Dijkstra Algorithm
 * Input: source,destinstion,Graph in Adjancy List form
 * Out  : shortest path distance from source to destination
 * NOTE : Works ONLY for POSITIVE edge wighted graph
 * Complexity: O(|E| + |V| log |V|)
 */

int dijkstra(int s, int d, vector<vector<Edge>> adj) {
    int n = adj.size();

    vector<int> dist(n, INF);
    dist[s] = 0;

    priority_queue<Node> PQ;
    PQ.push(Node(s, dist[s]));

    while (!PQ.empty()) {
        Node u = PQ.top();
        PQ.pop();

        /* This conditionis very imoportant.
         * In original algo, decrease key functionality
         * is needed. But C++/Java library PriorityQue
         * odes not provide that. So one node can be inserted
         * multiple times. So, to avoid loop if the old bigger
         * cost version is get just skip the loop. This leads
         * to more memory usage. But what to do if own min heap is
         * not to be implemented!
         */
        if (u.cost > dist[u.at])
            continue;

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
    vector<vector<Edge>> adj(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

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

            // Left
            if ((j - 1) >= 0) {
                int index = i * n + j - 1;
                int w     = grid[i][j] + grid[i][j - 1];
                adj[m_index].emplace_back(index, w);
            }
        }
    }

    // Source index = 0,0      top left
    // index on graph -> 0*n + 0 = 0
    // dest index   = n-1,n-1  bottom right
    // index on graph -> (n-1)*n + n - 1 = n*n - 1

    int s = 0, d = n * n - 1;
    cout << "min path cost ";

    int min_path = dijkstra(s, d, adj);

    int ans = (min_path + grid[0][0] + grid[n - 1][n - 1]) / 2;
    cout << ans << endl;

    // the way the graph is constructed, all but the two end
    // position's value appear twice in min path cost
    // ans = (min_cost - start - end)/2 + start + end
    //     = (min_cost + start + end)/2

    return 0;
}