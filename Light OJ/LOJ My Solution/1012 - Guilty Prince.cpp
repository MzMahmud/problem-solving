#include <bits/stdc++.h>
#define SIZE 23

using namespace std;

char mat[SIZE][SIZE];
int h,w,X,Y,ans,i;

void DFS(int x,int y){
    if(x < 0 || y < 0 || x >= w || y >= h || mat[y][x] == '#') return;
    mat[y][x] = '#';//this means this is either visited or not accessible
    ans++;
    DFS(x+1,y);
    DFS(x-1,y);
    DFS(x,y+1);
    DFS(x,y-1);
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d", &w,&h);
        for(int i = 0;i < h;i++) scanf("%s",mat[i]);

        for(int i = 0;i < h;i++)
            for(int j = 0;j < w;j++)
                if(mat[i][j] == '@'){
                    X = j;
                    Y = i;
                    break;
                }

        ans = 0;
        DFS(X,Y);
        printf("Case %d: %d\n",cn++,ans);
    }
    return 0;
}
