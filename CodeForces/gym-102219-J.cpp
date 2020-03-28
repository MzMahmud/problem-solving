#include <bits/stdc++.h>

#define N_PLATES 5

using namespace std;

enum Color { WHITE, GREY, BLACK };

struct Node {
    string name;
    Color color;
    int startTime, endTime;
    vector<Node *> adj;

    Node() : name(""), color(WHITE), startTime(0), endTime(0) {}
    Node(string n) : name(n), color(WHITE), startTime(0), endTime(0) {}
};

vector<Node *> nodes;
int dfs_time = 0;

// returns true is has Cycle
bool dfs(Node *start) {
    start->startTime = ++dfs_time;
    start->color     = GREY;

    bool hasCycle = false;
    for (int i = 0; i < start->adj.size(); i++) {
        Node *v = start->adj[i];
        if (v->color == GREY) {
            hasCycle = true;
            break;
        }
        if (v->color == WHITE)
            hasCycle |= dfs(v);
    }

    start->endTime = ++dfs_time;
    start->color   = BLACK;
    return hasCycle;
}

// sorts by decreasing order of end time
bool cmp(Node *a, Node *b) { return a->endTime > b->endTime; }

void printOrder() {
    bool hasCycle = false, allVisited;
    do {
        allVisited = true;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i]->color == WHITE) {
                allVisited = false;
                hasCycle |= dfs(nodes[i]);
            }
        }
    } while (!hasCycle && !allVisited);

    if (hasCycle) {
        cout << "impossible" << endl;
        return;
    }

    sort(nodes.begin(), nodes.end(), cmp);

    for (int i = 0; i < nodes.size(); i++) {
        cout << nodes[i]->name;
    }
    cout << endl;
}

int main() {
    // freopen("J.in", "r", stdin);

    for (int i = 0; i < N_PLATES; i++) {
        string name = "A";
        name[0]     = 'A' + i;
        nodes.push_back(new Node(name));
    }

    int n = N_PLATES;
    while (n--) {
        string s;
        cin >> s;
        if (s[1] == '>') {
            swap(s[0], s[2]);
            s[1] = '<';
        } // makes all rules in this form "A<B"

        int n1 = s[0] - 'A';
        int n2 = s[2] - 'A';
        nodes[n1]->adj.push_back(nodes[n2]);
    }

    printOrder();

    // free memory
    for (int i = 0; i < N_PLATES; i++) {
        delete nodes[i];
    }
    return 0;
}