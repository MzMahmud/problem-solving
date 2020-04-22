/*
    LOJ 1003 - Drunk
    Author: Moaz Mahmud
    Date  : 22 Apr,2020

    My Solution:
        if the dependency graph has cycle then not possible to drink.
        because of dependency cycle.
        used dfs to check existance of cycle
    END :D :D
*/

#include <bits/stdc++.h>

using namespace std;

typedef unordered_map<string, vector<string>> Graph;
typedef unordered_map<string, int> Color;

#define WHITE 0
#define GRAY 1
#define BLACK 2

// dfs returns if it found a cycle
bool dfs(string u, Color &color, Graph &g) {
    // gray node: u is reached by some path back to u
    // so cycle exists
    if (color[u] == GRAY)
        return true;

    // black node: no way to go from here. so can't have cycle
    if (color[u] == BLACK)
        return false;

    // mark the node gray(being explored)
    color[u] = GRAY;
    for (const auto &v : g[u])
        if (dfs(v, color, g))
            return true;

    // mark the node black(done exploring)
    color[u] = BLACK;
    return false;
}

bool has_cycle(Graph &g) {
    Color color;
    // initially all nodes are white(un-explored)
    for (const auto &u : g)
        color[u.first] = WHITE;

    bool found_cycle = false;
    for (const auto &u : g) {
        // for every un-explored node (ie: connected component)
        if (color[u.first] == WHITE)
            found_cycle |= dfs(u.first, color, g);

        if (found_cycle)
            return true;
    }
    return found_cycle;
}

int main() {
    int T, cn = 1;
    scanf("%d", &T);
    while (T--) {
        int n;
        cin >> n;
        Graph g;
        while (n--) {
            string u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        printf("Case %d: %s\n", cn++, has_cycle(g) ? "No" : "Yes");
    }
    return 0;
}