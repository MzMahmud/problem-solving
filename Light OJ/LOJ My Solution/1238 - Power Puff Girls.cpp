#include<cstdio>
#include<queue>
#define SIZE 20
#define inRange(x,y) ( x > 0 && y > 0 && x < (m-1) && y < (n-1) )

using namespace std;

char MAT[SIZE][SIZE];
int dist[SIZE][SIZE];
int m,n;

int bfs(pair<int,int> s){
    for(int i = 0;i < m;i++)
        for(int j = 0;j < n;j++)
            dist[i][j] = -1;//works as visited array. its visited is dist[i][j] > 0

    dist[s.first][s.second] = 0;
    queue< pair<int,int> > q;
    q.push(s);

    while(!q.empty()){
        pair<int,int> u = q.front();q.pop();
        int x = u.first,y = u.second;

        if(inRange(x+1,y) && MAT[x+1][y] != '#' && MAT[x+1][y] != 'm' && dist[x+1][y] < 0/*this means if its not visited*/){
            q.push(make_pair(x+1,y));
            dist[x+1][y] = dist[x][y] + 1;
            if(MAT[x+1][y] == 'h') return dist[x+1][y];//the problem assured there will always be a path so immediately returned
        }
        if(inRange(x-1,y) && MAT[x-1][y] != '#' && MAT[x-1][y] != 'm' && dist[x-1][y] < 0){
            q.push(make_pair(x-1,y));
            dist[x-1][y] = dist[x][y] + 1;
            if(MAT[x-1][y] == 'h') return dist[x-1][y];
        }
        if(inRange(x,y+1) && MAT[x][y+1] != '#' && MAT[x][y+1] != 'm' && dist[x][y+1] < 0){
            q.push(make_pair(x,y+1));
            dist[x][y+1] = dist[x][y] + 1;
            if(MAT[x][y+1] == 'h') return dist[x][y+1];
        }
        if(inRange(x,y-1) && MAT[x][y-1] != '#' && MAT[x][y-1] != 'm' && dist[x][y-1] < 0){
            q.push(make_pair(x,y-1));
            dist[x][y-1] = dist[x][y] + 1;
            if(MAT[x][y-1] == 'h') return dist[x][y-1];
        }
    }
    //the problem assured there will always be a path so immediately returned. so no return here .
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,cn = 1;

    scanf("%d",&T);
    while(T--){
        int da,db,dc;

        scanf("%d%d", &m,&n);
        for(int i = 0;i < m;i++) scanf("%s",&MAT[i]);

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(MAT[i][j] == 'a')
                   da = bfs(make_pair(i,j));

                else if(MAT[i][j] == 'b')
                   db = bfs(make_pair(i,j));

                else if(MAT[i][j] == 'c')
                   dc = bfs(make_pair(i,j));
            }
        }
        printf("Case %d: %d\n",cn++,max(max(da,db),dc));
    }
    return 0;
}
