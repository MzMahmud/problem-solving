#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

ll MOD = 1000000007;

ll bigMod(ll a,ll b,ll M)
{
    if (!b)  return (ll)(1 % M);
    ll x = bigMod( a , b / 2 , M) ;
    x = ( (x%M) * (x%M) ) % M;
    if(b&1)//is same as b%2 == 1
        x = (x*a) % M;
    return x ;
}

int main(){
    map<ll,ll> p;
    ll m,n = (ll)1,sqrtn = (ll)1,nod = (ll)1,sn = (ll)1;

    bool isSquare = true,done = false;

    cin >> m;

    for(int i = 0;i < m;i++){
        ll x;
        cin >> x;
        p[x]++;
        n *= x;
        if(n >= MOD) n %= MOD;
    }
    map<ll,ll>::iterator it;

    for(it = p.begin();it != p.end();it++){
        if(it->second % 2){
            isSquare = false;
            break;
        }
    }

    for(it = p.begin();it != p.end();it++){
        if(isSquare){
            nod *= (it->second + 1);
            if(nod >= (MOD-1)) nod %= (MOD-1);

            ll a = it->first;
            ll b = it->second;
            sn *= bigMod(a,b/2,MOD);
            if(sn >= MOD) sn %= MOD;
        }else{
            ll x = it->second + 1;
            if(x % 2 == 0 && !done){
                done = true;
                x /= 2;
            }
            nod *= x;
            if(nod >= (MOD-1)) nod %= (MOD-1);
        }
    }

    ll  ans;
    if(isSquare) n = sn;
    ans = bigMod(n,nod,MOD);

    if(ans >= MOD) ans %= MOD;
    printf("%I64d\n",ans);

    return 0;
}