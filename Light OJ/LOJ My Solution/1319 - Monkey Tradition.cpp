/*
    LOJ 1319 - Monkey Tradition
    Author: Moaz Mahmud
    Date  : 01 Nov,2017

    My Solution:
        Given a system of modulo.Just use Chinese Remainder
        system of modular equations.

    END :D :D
*/
#include <cstdio>
#include <vector>
#include <cmath>
#define MAXN 20

using namespace std;

typedef long long i64;

i64 bigMod(i64 a,i64 b,i64 M){//used for modular inverse
    if (!b)  return (1%M);
    int x = bigMod(a,b/2,M);
    x = ((x%M)*(x%M))% M;
    if(b&1) x = (x*a)%M;
    return x;
}

i64 a[MAXN],p[MAXN];

i64 chineseRemainder(int n,i64 &mod){
    mod = 1;
    i64 x = 0;
    for(int i = 0;i < n;i++) mod *= p[i];
    for(int i = 0;i < n;i++){
        i64 y,z,k;
        y = mod/p[i];
        z = bigMod(y,p[i]-2,p[i]);
        //this is to find modular inverse.
        //by Fermat's Theorem.If p[i] is not prime wont work
        k = a[i]*z;if(k >= mod) k %= mod;
        k = k * y; if(k >= mod) k %= mod;
        x = x + k; if(x >= mod) x %= mod;
        //if checks,as remainder finding is costly operation.Done when needed.
    }
    return (x < mod) ? x : (x % mod);
}

int main(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int n;
        i64 x,mod,maxR = -1;
        scanf("%d",&n);

        for(int i = 0;i < n;i++){
            scanf("%lld%lld",&p[i],&a[i]);
            if(a[i] > maxR) maxR = a[i];
        }
        x = chineseRemainder(n,mod);
        i64 i = 0,l = -1;
        while(l < maxR){l = x + i*mod;i++;}
        //this is done because no remainder can be greater than length

        printf("Case %d: %lld\n",cn++,l);
    }
    return 0;
}
