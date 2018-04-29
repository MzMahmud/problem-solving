/*
    LOJ 1149 - Factors and Multiples
    Author: Moaz Mahmud
    Date  : 01 Nov,2017

    My Solution:
        Notice,if an edge is given from any member of
        a to b if a(i)|b(i). Then the max max flow is the answer.
        So, used maximum Bipartite Matching.
    END :D :D
*/
#include <cstdio>
#include <cmath>
#include <queue>
#define MAXN 210
#define INF 1<<30
#define NILL 0

using namespace std;

bool visited[MAXN];
int parent[MAXN];
int adjMatrix[MAXN][MAXN];

bool bfs(int n,int s,int t){
    for(int i = 1;i <= n;i++){
        visited[i] = false;
        parent[i]  = NILL;
    }

    queue<int> Q;

    visited[s] = true;
    parent[s]  = NILL;
    Q.push(s);

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        for(int v = 1;v <= n;v++){
            if(!visited[v] && adjMatrix[u][v] > 0){
                visited[v] = true;
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
    //freopen("out.txt","w",stdout);

    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int n,m,a[MAXN],b[MAXN];
        for(int i = 0;i < MAXN;i++)
            for(int j = 0;j < MAXN;j++)
                adjMatrix[i][j] = 0;
        //super source m+n+1,super sink m+n+2
        //set a: 1 to n,set b: n+1 to n+m
        scanf("%d",&n);
        for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
        scanf("%d",&m);
        for(int i = 1;i <= m;i++) scanf("%d",&b[i]);

        for(int i = 1;i <= n;i++){
            adjMatrix[m+n+1][i] = 1;//super source to each a
            for(int j = 1;j <= m;j++){
                adjMatrix[n+j][m+n+2] = 1;//each b to super sink
                if(!a[i]) continue;//if a[i-1] == 0 no need to check
                if(!(b[j]%a[i]))
                    adjMatrix[i][n+j] = 1;//if divides give an edge
            }
        }
        //graph is constructed.Just run MaxFlow.
        int maxFlow = MaxFlow(m+n+2,m+n+1,m+n+2);
        printf("Case %d: %d\n",cn++,maxFlow);
    }
    return 0;
}
