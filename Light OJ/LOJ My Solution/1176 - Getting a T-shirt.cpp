/*
    LOJ 1176 - Getting a T-shirt
    Author: Moaz Mahmud
    Date  : 25 Oct,2017

    My Solution:
        Straight Forward Maximum Bipartite matching.
    END :D :D
*/

#include <bits/stdc++.h>
#define MAXN 100
#define INF 1<<30
#define NILL 0

using namespace std;

bool visited[MAXN];
int dist[MAXN];
int parent[MAXN];
int adjMatrix[MAXN][MAXN];

bool bfs(vector<int> adj[],int n,int s,int t){
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
            if(!visited[v] && adjMatrix[u][v] > 0){
                visited[v] = true;
                dist[v]    = dist[u] + 1;
                parent[v]  = u;
                Q.push(v);
            }
        }
        visited[u] = true;
    }
    return visited[t];
}

int MaxFlow(vector<int> adj[],int n,int s,int t){
    int maxFlow = 0;

    while(bfs(adj,n,s,t)){
        int minCapacity = INF;
        int v = t;
        while(v != s){
            int u = parent[v];
            minCapacity = min(minCapacity,adjMatrix[u][v]);
            v = u;
        }

        v = t;
        while(v != s){
            int u = parent[v];
            adjMatrix[u][v] -= minCapacity;
            adjMatrix[v][u] += minCapacity;
            v = u;
        }
        maxFlow += minCapacity;
    }
    return maxFlow;
}

int convert(string a){
    if(a == "XS")  return 2;
    if(a == "S" )  return 3;
    if(a == "M" )  return 4;
    if(a == "L" )  return 5;
    if(a == "XL")  return 6;
    if(a == "XXL") return 7;
}

int main(){
    freopen("in.txt","r",stdin);
    int T,cn = 1;
    scanf("%d", &T);

    while(T--){
        int n,m;
        vector<int> adj[MAXN];

        cin >> n >> m;
        for(int i = 0;i <= (m+10);i++)
            for(int j = 0;j <= (m+10);j++)
                adjMatrix[i][j] = 0;

        for(int i = 2;i <= 7;i++){
            adj[1].push_back(i);
            adj[i].push_back(1);
            adjMatrix[1][i] = n;
        }

        for(int i = 1;i <= m;i++){
            string a,b;
            cin >> a >> b;
            int u = convert(a),v = 7+i;
            adj[u].push_back(v);
            adj[v].push_back(u);
            adjMatrix[u][v] = 1;

            u = convert(b);
            adj[u].push_back(v);
            adj[v].push_back(u);
            adjMatrix[u][v] = 1;

            u = 7+i,v = 8+m;
            adj[u].push_back(v);
            adj[v].push_back(u);
            adjMatrix[u][v] = 1;
        }
        int flow = MaxFlow(adj,m+8,1,m+8);
        printf("Case %d: %s\n",cn++,flow == m?"YES":"NO");
    }
    return 0;
}
