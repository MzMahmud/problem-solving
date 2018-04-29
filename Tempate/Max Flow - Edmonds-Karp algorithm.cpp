#include <bits/stdc++.h>
#define MAXN 100
#define INF 1<<30
#define NILL 0

using namespace std;

bool visited[MAXN];
int dist[MAXN];
int parent[MAXN];
int adjMatrix[MAXN][MAXN];
int capacity[MAXN][MAXN];

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

void printFlow(vector<int> adj[],int n){
    for(int u = 1;u <= n;u++){
        for(int i = 0;i < adj[u].size();i++){
            int v = adj[u][i];
            if(adjMatrix[v][u] > 0)
                  printf("(%d)----%d/%d---->(%d)\n",u,adjMatrix[v][u],capacity[u][v],v);
            else  printf("(%d)----%d---->(%d)\n",u,capacity[u][v],v);
        }
    }
}

void dfs(vector<int> adj[],int u){
    visited[u] = true;
    for(int i = 0;i < adj[u].size();i++){
        int v = adj[u][i];
        if(adjMatrix[u][v] > 0 && !visited[v])
            dfs(adj,v);
    }
}

void printMinCut(vector<int> adjNet[],vector<int> adj[],int s,int n){
    for(int i = 1;i <= n;i++) visited[i] = false;
    //runs DFS on residual network
    dfs(adj,s);

    int cap = 0;
    printf("\n\nA Min Cut\n");
    for(int u = 1;u <= n;u++){
        for(int i = 0;i < adjNet[u].size();i++){
            int v = adjNet[u][i];
            //the edges from VISITED to UNVISITED are in MIN CUT
            if(visited[u] && !visited[v]){
                cap += capacity[u][v];
                printf("(%d)--%d--(%d)\n",u,capacity[u][v],v);
            }
        }
    }
    printf("capacity of Min Cut = %d\n",cap);
}

int main(){
    freopen("in.txt","r",stdin);

    int n,m;
    vector<int> adj[MAXN];
    vector<int> adjNetwork[MAXN];

    cin >> n >> m;

    for(int i = 1;i < MAXN;i++)
        for(int j = 1;j < MAXN;j++)
            adjMatrix[i][j] = 0,capacity[i][j] = 0;

    for(int i = 1;i <= m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        //for original flow network
        adjNetwork[u].push_back(v);
        capacity[u][v] = c;

        //for residual network
        adj[u].push_back(v);
        adj[v].push_back(u);
        adjMatrix[u][v] = c;
    }
    int s,t;
    cin >> s >> t;

    printf("Max Flow = %d\n",MaxFlow(adj,n,s,t));
    printFlow(adjNetwork,n);
    printMinCut(adjNetwork,adj,s,n);

    return 0;
}
