/*
    1095 - Arrange the Numbers
    Author: Moaz Mahmud
    Date  : 11 Nov,2017

    My Solution:
        There can be C(m,k) number of ways to choose fixed
        position in first m positions.The rest m-k would have
        to be misplaced
        Arranging non fixed:
            if 1 of m-k is C(m-k,1)*(n-k-1)!;
            if 2 of m-k is C(m-k,2)*(n-k-2)!;
            and so on.
            By inclusion exclusion
            ways to arrange is
            C(m-k,1)*(n-k-1)! - C(m-k,2)*(n-k-2)! + C(m-k,1)*(n-k-3)! -...
            These are not accepting.So accepting are
            (n-k)! - (C(m-k,1)*(n-k-1)! - C(m-k,2)*(n-k-2)! + C(m-k,1)*(n-k-3)! -...)
            which can be written as
            (-1)^0*C(m-k,0)*(n-k)! +(-1)^1 C(m-k,1)*(n-k-1)! +(-1)^1*C(m-k,2)*(n-k-2)!...
            up to (-1)^(m-k)*C(m-k,m-k)*(n-k-(m-k))!
            = SUM{j = 0 to m-k} (-1)^j C(m-k,j) (n-k-j)!

        So final answer,
        C(m,k)*SUM{j = 0 to m-k} (-1)^j C(m-k,j) (n-k-j)!
    END :D :D
*/
#include <cstdio>
#define MAXN 1002
#define MOD 1000000007

using namespace std;

typedef long long lli;

lli C[MAXN][MAXN];
lli fact[MAXN];

int main(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    //finding C(n,r);
    C[0][0] = 1;
    for(int n = 1;n < MAXN;n++){
        for(int r = 0;r <= n;r++){
            if(!r) C[n][r] = 1;
            else   C[n][r] = C[n-1][r] + C[n-1][r-1];
            if(C[n][r] >= MOD) C[n][r] %= MOD;
        }
    }
    //calculating n!
    fact[0] = 1;
    for(int n = 1;n < MAXN;n++){
        fact[n] = n*fact[n-1];
        if(fact[n] >= MOD) fact[n] %= MOD;
    }

    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        lli n,m,k;
        scanf("%lld%lld%lld",&n,&m,&k);
        lli ans = 0;
        for(int j = 0;j <= m-k;j++){
            if(j&1) ans -= (C[m-k][j]*fact[n-k-j]);
            else    ans += (C[m-k][j]*fact[n-k-j]);
            ans = (ans + MOD) % MOD;
        }
        ans *= C[m][k];
        if(ans >= MOD) ans %= MOD;
        printf("Case %d: %lld\n",cn++,ans);
    }
    return 0;
}

