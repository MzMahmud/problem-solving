/*
    1094 - Farthest Nodes in a Tree
    Author : Moaz Mahmud
    Date   : 13 Apr,2020

    Solution:
        Calculates the depth of a node.
        Any longets path goes through a root node
        between any two leafs.
        Fardest path that goes throug node root
        fardest_path(root) = depth(left) + depth(right)
        for binary tree. The process is similar for n-ary tree.
        just need to sonsider every pair of vertices
    END :D:D
*/

#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

struct Edge {
    int v;
    ll w;
    Edge(int _v, ll _w = 1) : v(_v), w(_w) {}
};

typedef vector<vector<Edge>> Graph;

ll depth(int u, ll &diam, const Graph &adj, vector<bool> &visited) {
    visited[u] = true;

    vector<ll> depths;
    ll max_depth = -1;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i].v;
        if (!visited[v]) {
            ll d = adj[u][i].w + depth(v, diam, adj, visited);
            depths.push_back(d);
            max_depth = max(max_depth, d);
        }
    }

    if (max_depth == -1)
        // means all its neighbours are visited.ie, its a leaf
        return 0;

    if (depths.size() == 1) {
        if (max_depth > diam)
            diam = max_depth;
    } else {
        // checks every pair of children for maximum diameter
        for (int i = 0; i < depths.size(); i++) {
            for (int j = i + 1; j < depths.size(); j++) {
                ll curr_diam = depths[i] + depths[j];
                if (curr_diam > diam)
                    diam = curr_diam;
            }
        }
    }
    return max_depth;
}

int main() {
    int T, cn = 1;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);

        Graph adj(n);
        vector<bool> visited(n, false);

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            ll w;
            scanf("%d%d%lld", &u, &v, &w);

            // undirected edge
            adj[u].emplace_back(v, w); //(u,v,w)
            adj[v].emplace_back(u, w); //(v,u,w)
        }

        ll diam = -1; // as no weight is < 0 min max dept is initilized with -1
        depth(0, diam, adj, visited);
        printf("Case %d: %lld\n", cn++, diam);
    }
    return 0;
}