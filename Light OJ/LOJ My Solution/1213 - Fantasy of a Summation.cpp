/*
ALGO:
    all those bals ends in this
    ans = n^(k-1)*k*sum mod MOD :V
    you wonder how!!!
    n^k permutations of n digits k times total digit n^k*k
    where each appears the same number of times -_-
    so total run = n^k*k/n = n^(k-1)*k
    and every time it sums up all those integers
    so,ans = n^(k-1)*k*sum mod MOD -_-
*/

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll bigMod(ll a,ll b,ll M)
{
    if ( b == 0 )  return (1 % M);
    int x = bigMod( a , b / 2 , M) ;
    x = ( (x%M) * (x%M) ) % M;
    if ( b % 2 == 1 ) x = (x*a) % M;
    return x ;
}

int main()
{
    int T,cn = 1,i;
    ll n,k,MOD,a,sum,ans;

    scanf("%d", &T);
    while(T--){
        scanf("%lld%lld%lld", &n,&k,&MOD);

        for(i = 0,sum = 0;i < n;i++){
            scanf("%lld", &a);
            sum = ( sum + a%MOD ) % MOD;
        }
        ans = bigMod(n,k-1,MOD);
        k %= MOD;
        ans = (ans*k)%MOD;
        ans = (ans*sum)%MOD;
        printf("Case %d: %lld\n",cn++,ans);
    }
    return 0;
}
