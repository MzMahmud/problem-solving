/*
    LOJ 1153 - Internet Bandwidth
    Author: Moaz Mahmud
    Date  : 25 Oct,2017

    My Solution:
        Straight Forward Max Flow.
        Just done adjMatrix[u][v] += c for multiple edge between
        Nodes.
    END :D :D
*/

#include <bits/stdc++.h>
#define MAXN 110
#define INF 1<<30
#define NILL 0

using namespace std;

bool visited[MAXN];
int dist[MAXN];
int parent[MAXN];
int adjMatrix[MAXN][MAXN];

bool bfs(int n,int s,int t){
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

        for(int v = 1;v <= n;v++){
            if(!visited[v] && adjMatrix[u][v] > 0){
                visited[v] = true;
                dist[v]    = dist[u] + 1;
                parent[v]  = u;
                Q.push(v);
            }
        }
        visited[u] = true;
        if(u == t) return true;
    }
    return false;
}

int MaxFlow(int n,int s,int t){
    int maxFlow = 0;
    while(bfs(n,s,t)){
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

int main(){
    freopen("in.txt","r",stdin);

    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int n,m,s,t;
        cin >> n >> s >> t >> m;

        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                adjMatrix[i][j] = 0;

        for(int i = 1;i <= m;i++){
            int u,v,c;
            cin >> u >> v >> c;
            adjMatrix[u][v] += c;
            adjMatrix[v][u] += c;
        }
        printf("Case %d: %d\n",cn++,MaxFlow(n,s,t));
    }
    return 0;
}
