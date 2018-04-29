/*
    LOJ 1155 - Power Transmission
    Author: Moaz Mahmud
    Date  : 25 Oct,2017

    My Solution:
        Flow network with Capacity at node.
        Turned it into normal by making
        node(i)--c-->node(n+i),c = node capacity.
        all incoming node in node(i) stays in i but
        out going goes from node(n+i).
    END :D :D
*/

#include <bits/stdc++.h>
#define MAXN 1000
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
        if(u == t) return true;
    }
    return false;
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

int main(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int n,m;
        vector<int> adj[MAXN];

        scanf("%d", &n);
        for(int i = 1;i <= 3*n;i++)
            for(int j = 1;j <= 3*n;j++)
                adjMatrix[i][j] = 0;

        for(int i = 1;i <= n;i++){
            int c;
            scanf("%d", &c);
            adj[i].push_back(n+i);
            adj[n+i].push_back(i);
            adjMatrix[i][n+i] = c;
            //an edge of capacity c from (i) to (i+1)
        }

        scanf("%d", &m);
        for(int i = 1;i <= m;i++){
            int u,v,c;
            scanf("%d%d%d", &u,&v,&c);

            adj[u+n].push_back(v);//outgoing edge from (u).So made (u+n) to v
            adj[v].push_back(u+n);
            adjMatrix[u+n][v] = c;
        }
        int B,D;
        scanf("%d%d", &B,&D);
        //Node BARISHAL 2n+1,DHAKA 2n+2
        for(int i = 1;i <= B;i++){
            int v;
            scanf("%d",&v);
            adj[2*n+1].push_back(v);//incoming,so from BARISHAL to (v)
            adj[v].push_back(2*n+1);
            adjMatrix[2*n+1][v] = INF;
        }
        for(int i = 1;i <= D;i++){
            int u;
            scanf("%d",&u);
            adj[u+n].push_back(2*n+2);//outgoing,so form (u+n) to DHAKA
            adj[2*n+2].push_back(u+n);
            adjMatrix[u+n][2*n+2] = INF;
        }
        int maxFlow = MaxFlow(adj,2*n+2,2*n+1,2*n+2);
        printf("Case %d: %d\n",cn++,maxFlow);
    }
    return 0;
}
