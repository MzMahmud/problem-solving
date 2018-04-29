/*
    LOJ 1117 - Helping Cicada
    Author: Moaz Mahmud
    Date  : 16 Nov,2017

    My Solution:
        The problems needed to find the number of days
        not divisible by any of the given numbers.
        By using Inclusion-Exclusion its solved.

    END :D :D
*/


#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 15

using namespace std;

typedef long long ll;

ll ans,n,a[MAXN];
int m;
struct LCM{
    ll lcm;int r;//lcm keeps lcm,r keeps the # integers in that lcm
    LCM(ll p,int _r){lcm = p;r = _r;}
    LCM operator*(ll a){return LCM(a*(lcm/__gcd(lcm,a)),r+1);}
};

void comb(int i,int r,LCM b){
    if(i == m || r == 0){
        if(b.r&1) ans -= (n/b.lcm);
        else      ans += (n/b.lcm);
        return;
    }
    comb(i+1,r,b);//not taking a[i]
    comb(i+1,r-1,b*a[i]);//by taking a[i]
    //the operator* is overloaded such that it takes lcm and makes r++
}

int main(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        ans = 0;
        scanf("%lld%d",&n,&m);
        for(int i = 0;i < m;i++) scanf("%lld",&a[i]);
        comb(0,m,LCM(1,0));
        printf("Case %d: %lld\n",cn++,ans);
    }
    return 0;
}
