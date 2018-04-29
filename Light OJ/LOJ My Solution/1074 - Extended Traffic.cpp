#include <bits/stdc++.h>

#define INF 1000000000

using namespace std;

struct Edge{
    int u,v;
    long long w;
    Edge(int _u,int _v,long long _w){
        u = _u,v = _v,w = _w;
    }
};

long long d[210];

void bellmanFord(int s,vector<Edge> edge,int n){
    for(int i = 0;i < n;i++) d[i] = INF;
    d[s] = 0;

    for(int i = 1;i < n;i++){
        for(int j = 0;j < edge.size();j++){
            Edge e = edge[j];
            int u,v,w;
            u = e.u;v = e.v;w = e.w;
            if(d[u]+w < d[v]) d[v] = d[u]+w;
        }
    }
    while(true){
        int i;
        for(i = 0;i < edge.size();i++){
            Edge e = edge[i];
            int u,v,w;
            u = e.u;v = e.v;w = e.w;

            if(d[v] == -INF) continue;

            if(d[u]+w < d[v]){d[v] = -INF;break;}
        }
        if(i == edge.size()) break;
    }
}

int main(){
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        vector<Edge> edge;
        vector<long long> w;
        int m,n;
        scanf("%d", &n);
        for(int i = 0;i < n;i++){
            long long wt;
            scanf("%lld", &wt);
            w.push_back(wt);
        }
        scanf("%d", &m);
        for(int i = 0;i < m;i++){
            int u,v;
            long long dif;
            scanf("%d%d", &u,&v);
            dif = w[v-1] - w[u-1];
            Edge e(u-1,v-1,dif*dif*dif);
            edge.push_back(e);
        }

        bellmanFord(0,edge,n);

        int q;
        scanf("%d", &q);
        printf("Case %d:\n",cn++);
        for(int i = 0;i < q;i++){
            int v;
            scanf("%d", &v);
            if(d[v-1] < 3 || d[v-1] > INF/10) printf("?\n");
            else                            printf("%lld\n",d[v-1]);
        }
    }

    return 0;
}
