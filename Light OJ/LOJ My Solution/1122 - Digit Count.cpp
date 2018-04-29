/*
    //LOJ 1122 Digit Count
    Author: Moaz Mahmud
    Date  : 08 May,2017
*/
#include <cstdio>
#define ABS(x) (x < 0? -1*x : x)
#define SIZE 11

using namespace std;

int digits[SIZE];
int s[SIZE][SIZE];
int d;

int startsWith(int i,int n){
    if(n == 1) s[i][n] = 1;

    if(s[i][n] < 0){
        int res = 0;
        for(int j = 0;j < d;j++){
            if( ABS( (digits[i]-digits[j]) ) <= 2 ){
                res += startsWith(j,n-1);
            }
        }
        s[i][n] = res;
    }

    return s[i][n];
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdo);

    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d%d",&d,&n);
        for(int i = 0;i < d;i++)
            scanf("%d", &digits[i]);

        for(int i = 0;i < SIZE;i++)
            for(int j = 0;j < SIZE;j++)
                s[i][j] = -1;

        int ans = 0;
        for(int i = 0;i < d;i++){
            ans += startsWith(i,n);
        }
        printf("Case %d: %d\n",cn++,ans);
    }
    return 0;
}

