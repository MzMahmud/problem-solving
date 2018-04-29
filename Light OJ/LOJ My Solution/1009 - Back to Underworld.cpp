/*
    //LOJ 1009 - Back to Underworld
    Author : Moaz Mahmud
    Date   : 04 May,2017
*/
#include<set>
#include<cstdio>
#include<queue>
#define SIZE 20005
#define RED 1
#define BLUE 0
#define NotColored -1

using namespace std;

int bfsVisit(int s,vector<int> adj[],short int color[]){
    int col[2] = {0};//stores RED(0) in index 0 and BLUE(1) in 1.
    color[s] = RED;
    col[RED]++;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front();q.pop();
        for(int i = 0;i < adj[u].size();i++){
            if(color[adj[u][i]] == NotColored){
                q.push(adj[u][i]);
                color[adj[u][i]] = !color[u];//gets the opposite color of u
                col[color[adj[u][i]]]++;
            }
        }
    }
    return max(col[RED],col[BLUE]);
}

int bfs(set<int> vert,vector<int> adj[],short int color[]){
    set<int>::iterator it = vert.begin();
    while(it != vert.end()){
        color[*it] = NotColored;
        it++;
    }

    it = vert.begin();
    int ans = 0;
    while(it != vert.end()){
        if(color[*it] == NotColored)
            ans += bfsVisit(*it,adj,color);

        it++;
    }
    return ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        set<int> vert;vector<int> adj[SIZE];short int color[SIZE];
        int n,u,v;

        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d%d", &u,&v);
            vert.insert(u);vert.insert(v);
            adj[u].push_back(v);adj[v].push_back(u);
        }
        printf("Case %d: %d\n", cn++,bfs(vert,adj,color));
    }
    return 0;
}
