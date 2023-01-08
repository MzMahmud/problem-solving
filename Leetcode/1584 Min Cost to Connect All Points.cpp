#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
  private:
    vector<int> parents;
    vector<int> ranks;

  public:
    DisjointSet(int n) {
        ranks.assign(n, 0);
        parents.assign(n, 0);
        for (int i = 0; i < n; ++i)
            parents[i] = i;
    }

    int find_set(int a) {
        if (parents[a] == a)
            return a;
        return parents[a] = find_set(parents[a]);
    }

    bool union_set(int a, int b) {
        int set_a = find_set(a);
        int set_b = find_set(b);
        if (set_a == set_b)
            return false;
        if (ranks[set_a] < ranks[set_b]) {
            parents[set_a] = set_b;
        } else {
            parents[set_b] = set_a;
            if (ranks[set_a] == ranks[set_b])
                ++ranks[set_a];
        }
        return true;
    }
};

class Solution {

    struct Edge {
        int from, to, weight;
        Edge(int _from, int _to, int _weight = 1)
            : from(_from), to(_to), weight(_weight) {}
        bool operator<(const Edge &other) const { return weight < other.weight; }
    };

    int dist(const vector<int> &a, const vector<int> &b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int kruskal_mst_cost(vector<Edge> &edges, int n_vertices) {
        sort(begin(edges), end(edges));
        DisjointSet disjoint_set(n_vertices);
        int cost = 0;
        for (const auto &edge : edges) {
            if (disjoint_set.union_set(edge.from, edge.to)) {
                cost += edge.weight;
            }
        }
        return cost;
    }

  public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        vector<Edge> edges;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                edges.push_back(Edge(i, j, dist(points[i], points[j])));
            }
        }
        return kruskal_mst_cost(edges, points.size());
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> points = {{-14, -14}, {-18, 5}, {18, -10}, {18, 18}, {10, -2}};
    cout << Solution().minCostConnectPoints(points) << endl; // sould give 102
    return 0;
}
