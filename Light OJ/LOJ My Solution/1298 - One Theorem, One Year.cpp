/*
    LOJ 1298 - One Theorem, One Year
    Author: Moaz Mahmud
    Date  : 26 Nov,2017

    My Solution:
        I should write it in details later :P

    END :D :D
*/
#include <cstdio>
#include <cmath>
#include <iostream>
#define MAXK 560
#define MAXN 4000
#define MOD 1000000007
#define getBit(n,pos)((bool)(n&(1<<pos)))
#define setBit(n,pos)(n = n|(1<<pos))

using namespace std;

typedef long long lli;

int state[(MAXN/64)+2];
int nPrime[MAXK],piN = 1;
void bitSieve(int n){
    nPrime[piN++] = 2;
    int pos,limit = sqrt(n*1.0)+2;
    for(int i = 3;i <= n;i+=2){
        pos = (i+1)/2;
        if( !getBit(state[pos>>5],(pos&31)) ){
            nPrime[piN++] = i;
            if(i < limit){
                for(int j = i*i;j <= n;j+=(2*i)){
                    pos = (j+1)/2;
                    setBit(state[pos>>5],(pos&31));
                }
            }
        }
    }
}

lli bigMod(int a,int b,int M){
    if (!b)  return (1 % M);
    lli x = bigMod(a,b/2,M) ;
    x = ((x%M)*(x%M))%M;
    if(b&1) x = (x*a)%M;
    return x;
}

lli primeProd[MAXK],ans[MAXK][MAXK];
lli dp(int i,int k){
    if(!k)      ans[i][k] = 1;
    if(i == 1)  ans[i][k] = bigMod(nPrime[i],k,MOD);
    if(!ans[i][k])
        ans[i][k] = (nPrime[i]*dp(i,k-1) + dp(i-1,k))%MOD;

    return ans[i][k]%MOD;
}

int main(){
    bitSieve(MAXN);
    dp(500,500);

    primeProd[0] = 1;
    for(int i = 1;i < piN;i++)
        primeProd[i] = (primeProd[i-1]*(nPrime[i]-1))%MOD;

    int T,cn = 1;
    scanf("%d",&T);
	while(T--){
        int k,p;
        scanf("%d%d",&k,&p);
        printf("Case %d: %lld\n",cn++,(dp(p,k-p)*primeProd[p])%MOD);
    }
    return 0;
}
