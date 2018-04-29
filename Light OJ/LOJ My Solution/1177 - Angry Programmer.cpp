/*
    LOJ 1177 - Angry Programmer
    Author: Moaz Mahmud
    Date  : 26 Oct,2017

    My Solution:
        int minCut = MaxFlow(2*n-2,1,n);
        this one line says it all :P
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
        int n,m;
        scanf("%d%d", &n,&m);
        for(int i = 1;i <= 3*n;i++)
            for(int j = 1;j <= 3*n;j++)
                adjMatrix[i][j] = 0;

        for(int i = 2;i <= n-1;i++){
            int c;
            scanf("%d", &c);
            adjMatrix[i][i+n-1] = c;
        }
        for(int i = 1;i <= m;i++){
            int a,b,c,u,v;
            scanf("%d%d%d", &a,&b,&c);
            u = (a==1||a==n)?a:(a+n-1);
            v = b;
            adjMatrix[u][v] = c;
            swap(a,b);
            u = (a==1||a==n)?a:(a+n-1);
            v = b;
            adjMatrix[u][v] = c;
        }
        int minCut = MaxFlow(2*n-2,1,n);
        printf("Case %d: %d\n",cn++,minCut);
    }
    return 0;
}

