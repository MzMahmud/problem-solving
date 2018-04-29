/*
    //LOJ 1263 - Equalizing Money
    Author : Moaz Mahmud
    Date   : 04 May,2017

    My Solution:

        As only integer transaction is allowed so if total
        money is not divisible by n then its not possible.
        Now, my solution is a construction.
        If any person has a value less then the target(= total/n)
        then it collects the money from its relative. If that person
        can't collect enough money then the equalization
        is not possible. This is done by a bfs() run.

    DONE :D :D
*/
#include<cstdio>
#include<queue>
#define SIZE 1005

using namespace std;

int n,sum,target;

bool bfs(int s,vector<int> adj[],int money[]){
    bool visited[SIZE] = {0};

    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int i = 0;i < adj[u].size();i++){
            if(money[s] == target) return true;//it target is reached terminated
            int x = adj[u][i];
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
                if(money[x] > target){
                    int need = target - money[s];
                    int extra = money[x] - target;
                    int given = min(need,extra);
                    money[x] -= given;
                    money[s] += given;
                }
            }
        }
    }
    return (money[s] == target);
}

bool equalize(vector<int> adj[],int money[],int sum){
    if(sum%n) return false;
    target = sum/n;
    for(int i = 0;i < n;i++){
        if(money[i] < target){
            bool yes = bfs(i,adj,money);
            if(!yes) return false;//if any one is unreachable false is returned
        }
    }
    return true;//otherwise true
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int m;sum = 0;
        vector<int> adj[SIZE];
        int money[SIZE];

        scanf("%d%d", &n,&m);
        for(int i = 0;i < n;i++){
            scanf("%d", &money[i]);
            sum += money[i];
        }
        for(int i = 0;i < m;i++){
            int u,v;
            scanf("%d%d", &u,&v);
            adj[u-1].push_back(v-1),adj[v-1].push_back(u-1);//my indexing starts with 0 theirs 1.
        }

        printf("Case %d: %s\n", cn++,equalize(adj,money,sum) == true?"Yes":"No");
    }
    return 0;
}
