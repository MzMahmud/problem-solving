/*
ALGO:
    Trailing:
        (last 3 digits of n^k) = (n^k) mod 1000
        that is gained by BigMod in O(log n)
    Leadind:
        n^k = 10^(log(n^k)) = 10^(k*log(n))
        now,n^k can be written in scientific form a*10^b.
        log(a*10^b) = log(a)+ b
        example, 123456789 = 1.23456789*10^8
        log(123456789) = log(1.23456789) + 8
        forget that 8 :P
        10^log(1.23456789) = 1.23456789
        now any number of first digits can be found.
        so,the 10^{fractionalPart(k*log(n))} would give this king of form
        (first 3 digits) = floor( 100*10^{fractionalPart(k*log(n))} )
        By the this is O(1) :D
    Total Complexity O(log n)
*/

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;
typedef long double ld;

ll bigMod(ll a,ll b,ll m)
{
    if(b == 0) return (1 % m);

    ll x = bigMod(a,b/2,m);
    x = (x*x)%m;
    if( b % 2 == 1 ) x = (x*a) % m;
    return x;
}

int main()
{
    int T,cn = 1;
    ll n,k,lead,trail;
    ld a,b,c;

    scanf("%d", &T);
    while(T--){
        scanf("%lld%lld", &n,&k);
        trail = bigMod(n,k,1000);
        a = k*log10(n);
        c = (ll)a;
        b = a - c;
        a = pow(10,b+2);
        lead = (ll)a;
        printf("Case %d: %lld %03lld\n",cn++,lead,trail);
    }
    return 0;
}


