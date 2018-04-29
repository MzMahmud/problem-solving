/*
    LOJ 1002 - Country Roads
    Author: Moaz Mahmud
    Date  : 19 Oct,2017

    My Solution:
        A slight modification in Dijkstra Algorithm.
        in Relax step
            if(max(d[u],w) < d[v]) then relaxed.
        because the question tells to minimize cost,
        which is defined by the maximum weight of an edge
        in a path.
    END :D :D
*/

#include <queue>
#include <stdio.h>
#define INF 1000000000
#define nVertices 503

using namespace std;

struct Node{
    int at,cost;
    Node(int _at,int _cost){at = _at;cost = _cost;}
};
bool operator<(Node A,Node B){return A.cost > B.cost;}

struct Edge{
    int v,w;
    Edge(int _v,int _w){v = _v;w = _w;}
};



int dist[nVertices];
int n,m;

void dijkstra(int s,vector<Edge> adj[]){
    for(int i = 0;i < n;i++) dist[i] = INF;
    dist[s] = 0;

    priority_queue<Node> PQ;
    PQ.push(Node(s,dist[s]));

    while(!PQ.empty()){
        Node u = PQ.top();PQ.pop();
        if(u.cost != dist[u.at]) continue;
        for(int i = 0;i < adj[u.at].size();i++){
            Edge e = adj[u.at][i];
            if( max(dist[u.at],e.w) < dist[e.v] ){
                dist[e.v] = max(dist[u.at],e.w);
                PQ.push(Node(e.v,dist[e.v]));
            }
        }
    }
    for(int i = 0;i < n;i++){
        if(dist[i] == INF) printf("Impossible\n");
        else               printf("%d\n",dist[i]);
    }
}

int main(){
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        vector<Edge> adj[nVertices];
        int t;
        scanf("%d%d",&n,&m);
        for(int i = 0;i < m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            adj[u].push_back(Edge(v,w));
            adj[v].push_back(Edge(u,w));
        }
        scanf("%d", &t);
        printf("Case %d:\n",cn++);
        dijkstra(t,adj);
    }
    return 0;
}