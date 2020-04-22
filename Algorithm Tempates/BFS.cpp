#include <bits/stdc++.h>
#define MAXN 10000
#define INF 1<<30
#define NILL 0

using namespace std;

bool visited[MAXN];
int dist[MAXN];
int parent[MAXN];
void bfs(vector<int> adj[],int n,int s){
    for(int i = 1;i <= n;i++){
        visited[i] = false;
        dist[i]    = INF;
        parent[i]  = NILL;
    }

    queue<int> Q;

    visited[s] = true;
    dist[s]    = 0;
    parent[s]  = NILL;
    Q.push(s);

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        for(int i = 0;i < adj[u].size();i++){
            int v = adj[u][i];
            if(!visited[v]){
                visited[v] = true;
                dist[v]    = dist[u] + 1;
                parent[v]  = u;
                Q.push(v);
            }
        }
        visited[u] = true;
    }
}

int main(){
    /*Undirected Graph
        5
        7
        1 3
        1 4
        2 4
        2 5
        3 4
        3 5
        4 5
     */
    int n,m;
    vector<int> adj[MAXN];

    n = 6,m = 7;
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[1].push_back(4);
    adj[4].push_back(1);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);
    adj[5].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[3].push_back(5);
    adj[5].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(4);

    bfs(adj,n,1);

    cout << "Dist from Source" << endl;
    cout << dist[1] << endl;
    cout << dist[2] << endl;
    cout << dist[3] << endl;
    cout << dist[4] << endl;
    cout << dist[5] << endl;
    cout << dist[6] << endl;

    cout << "Parent" << endl;
    cout << parent[1] << endl;
    cout << parent[2] << endl;
    cout << parent[3] << endl;
    cout << parent[4] << endl;
    cout << parent[5] << endl;
    cout << parent[6] << endl;

    return 0;
}
