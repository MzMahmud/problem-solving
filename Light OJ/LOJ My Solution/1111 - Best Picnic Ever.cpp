#include<cstdio>
#include<cstring>
#include<vector>
#define SIZE 1002

using namespace std;

int cities[SIZE];
bool visited[SIZE];

void dfs(int n,vector<int> adj[]){
    if(visited[n]) return;
    visited[n] = true;
    cities[n]++;
    for(int i = 0;i < adj[n].size();i++)
        dfs(adj[n][i],adj);
}

int main(){
    freopen("in.txt","r",stdin);
    int T,cn = 1;

    scanf("%d",&T);
    while(T--){
        vector<int> persons;
        vector<int> adj[SIZE];
        int n,k,m,p,u,v;

        scanf("%d%d%d",&k,&n,&m);
        for(int i = 0;i < k;i++){scanf("%d",&p);persons.push_back(p-1);}
        for(int i = 0;i < m;i++){scanf("%d%d",&u,&v);adj[u-1].push_back(v-1);}

        memset(cities,0,sizeof(cities));
        for(int i = 0;i < k;i++){
            memset(visited,0,sizeof(visited));
            dfs(persons[i],adj);
        }

        int ans = 0;
        for(int i = 0;i < n;i++) if(cities[i] == k) ans++;

        printf("Case %d: %d\n",cn++,ans);
    }
    return 0;
}
