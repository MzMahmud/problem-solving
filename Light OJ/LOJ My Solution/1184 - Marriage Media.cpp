/*
    LOJ 1184 - Marriage Media
    Author: Moaz Mahmud
    Date  : 01 Nov,2017

    My Solution:
        Simple Bipartite Matching.
    END :D :D
*/
//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#define MAXN 60
#define INF 1<<30
#define NILL 0
#define MAX(x,y) (x > y? x : y)
#define MIN(x,y) (x < y? x : y)

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

struct person{
    int height,age;
    bool divorced;
    person(int h = 0,int a = 0,bool d = 0){
        height = h;
        age = a;
        divorced = d;
    }
    bool operator==(person a){//this is done for matching
        return (abs(height - a.height) <=  12)//height gap is <= 12
            && (abs(age - a.age) <= 5)//age gap <=5
            && (divorced == a.divorced);//with same divorced status
    }
};

int main(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int m,n;
        scanf("%d%d",&m,&n);

        for(int i = 1;i <= (m+n+2);i++)
            for(int j = 1;j <= (m+n+2);j++)
                adjMatrix[i][j] = 0;

        vector<person> man;
        vector<person> woman;
        //super source m+n+1,super sink m+n+2
        //men 1 to m,women m+1 to m+n
        for(int i = 1;i <= m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            man.push_back(person(a,b,c));
            adjMatrix[m+n+1][i] = 1;//super source to each man
        }
        for(int i = 1;i <= n;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            woman.push_back(person(a,b,c));
            adjMatrix[m+i][m+n+2] = 1;//each woman to super sink
        }

        for(int i = 1;i <= m;i++)
            for(int j = 1;j <= n;j++)
                if(man[i-1] == woman[j-1])
                    adjMatrix[i][m+j] = 1;//if match found an edge

        //graph is constructed.Just run MaxFlow.
        int maxFlow = MaxFlow(m+n+2,m+n+1,m+n+2);
        printf("Case %d: %d\n",cn++,maxFlow);
    }
    return 0;
}
