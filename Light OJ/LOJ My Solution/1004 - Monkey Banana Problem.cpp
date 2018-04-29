/*
    //LOJ 1004 - Monkey Banana Problem
    Author: Moaz Mahmud
    Date  : 07 May,2017
*/

#include<cstdio>
#define SIZE 2*100+9
#define ABS(x) (x < 0? -1*x : x)
#define MAX(a,b) (a > b? a : b)

using namespace std;
int grid[SIZE][SIZE];
long long total[SIZE][SIZE];
int s,n;
long long solve(int x,int y){
    if(x < 0 || x >= s || y < 0 || y >= s)
        return 0;

    if(x == (s-1))
        total[x][y] = grid[x][n-1];

    if(total[x][y] < 0)
       total[x][y] = MAX( (grid[x][y] + solve(x+1,y-1)),(grid[x][y] + solve(x+1,y+1)));

    return total[x][y];
}

int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        s = 2*n - 1;
        for(int i = 0;i < s;i++){
            for(int j = 0;j < s;j++){
                total[i][j] = -1;
                grid[i][j]  = 0;
            }
        }
        for(int i = 0;i < s;i++){
            int start = ABS( (n-1-i) ),k = i+1;
            if(i >= n) k = n-(i-(n-1));
            for(int j = 0;j < k;j++){
                scanf("%d",&grid[i][start + (2*j)]);
            }
        }
        for(int i = 0;i < s;i++){
            for(int j = 0;j < s;j++){
                total[i][j] = -1;
            }
        }
        printf("Case %d: %lld\n",cn++,solve(0,n-1));
    }
    return 0;
}
