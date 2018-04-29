/*
    //LOJ 1169 - Monkeys on Twin Tower
    Author: Moaz Mahmud
    Date  : 14 May,2017

    My Solution:
        dp :V
    END
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#define SIZE 1002

using namespace std;

int twinTower[2][SIZE],path[2][SIZE],n;
int dp[2][SIZE];

int solve(int a,int lr){
    if(a == (n-1)) return (dp[lr][a] = twinTower[lr][a]);
    if(dp[lr][a] < 0){
        int same = twinTower[lr][a] + solve(a+1,lr);
        int other = twinTower[lr][a] + path[lr][a] + solve(a+1,!lr);
        dp[lr][a] = min(same,other);
    }
    return dp[lr][a];
}

int main() {
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdo);

    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int a;
        scanf("%d", &n);
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < n;j++){
                scanf("%d", &twinTower[i][j]);
                dp[i][j] = -1;
            }
        }
        for(int i = 0;i < 2;i++)
            for(int j = 0;j < (n-1);j++)
                scanf("%d", &path[i][j]);

        printf("Case %d: %d\n",cn++,min(solve(0,0),solve(0,1)));
    }
    return 0;
}

