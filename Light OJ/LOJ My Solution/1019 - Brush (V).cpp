/*
    LOJ 1019 - Brush (V)
    Author: Moaz Mahmud
    Date  : 11 Oct,2017

    My Solution:
        Straight Forward Single Source Shortest Path
        Problem for weighted undirected graph.
        So implemented Dijkstra Algorithm.

    END :D :D
*/

#include <queue>
#include <stdio.h>
#define INF 1000000000

using namespace std;

int d[103];
struct Node{
    int at,cost;
    Node(int _at,int _cost){at = _at;cost = _cost;}
};
bool operator<(Node A,Node B){return A.cost > B.cost;}

struct Edge{
    int v,w;
    Edge(int _v,int _w){v = _v;w = _w;}
};



int dist[103];
int n,m;

void dijkstra(int s,vector<Edge> adj[]){
    for(int i = 1;i <= n;i++) dist[i] = INF;
    dist[s] = 0;

    priority_queue<Node> PQ;
    PQ.push(Node(s,dist[s]));

    while(!PQ.empty()){
        Node u = PQ.top();PQ.pop();
        if(u.cost != dist[u.at]) continue;
        for(int i = 0;i < adj[u.at].size();i++){
            Edge e = adj[u.at][i];
            if( (u.cost + e.w) < dist[e.v] ){
                dist[e.v] = u.cost + e.w;
                PQ.push(Node(e.v,dist[e.v]));
            }
        }
    }
}

int main(){
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        vector<Edge> adj[103];
        scanf("%d%d",&n,&m);
        for(int i = 0;i < m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            adj[u].push_back(Edge(v,w));
            adj[v].push_back(Edge(u,w));
        }
        dijkstra(1,adj);
        printf("Case %d: ",cn++);
        if(dist[n] == INF) printf("Impossible\n");
        else               printf("%d\n",dist[n]);
    }
    return 0;
}
