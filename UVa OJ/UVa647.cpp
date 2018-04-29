/*#include <iostream>

#define size 100000

using namespace std;
 
long long int dp[size];

int main()
{
    int n,i,j;
    int cent[6]={1,5,10,25,50};

    for(i = 0;i < 5;i++){
        for(j = cent[i];j<= size;j++){
            dp[j] = dp[j] + dp[ j - cent[i] ];
        }
    }

    while( cin >> n ){
        cout << dp[m] << endl;
    }
    return 0;
}*/
#include <stdio.h>
int mod = 100000007;
int main()
{
    int coin[103];
    int T,cn = 1,i,j,n,k;

    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);

        for(i = 0;i<n;i++)
            scanf("%d",&coin[i]);

        int way[10005] = {0};
        way[0] = 1;
        for(i = 0;i<n;i++){
            for(j=1;j<=k;j++){
                if(coin[i]<= j)
                    way[j] = way[j] + way[j-coin[i]];
                if(way[j] > mod)
                    way[j] %= mod;
            }
        }
        printf("Case %d: %d\n",cn++,way[k]%mod);

    }
    return 0;
}
