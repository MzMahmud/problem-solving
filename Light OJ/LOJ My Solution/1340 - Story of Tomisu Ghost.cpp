/*
    LOJ 1340 - Story of Tomisu Ghost
    Author: Moaz Mahmud
    Date  : 17 Nov,2017

    My Solution:
        I <3 this solution of mine :D
        So not written here. May be I'll write in in LaTeX.
    END :D :D
*/
#include <cstdio>
#include <cmath>
#include <vector>
#define MAXN 100005
#define MOD  10000019
#define getBit(n,pos)((bool)(n&(1<<pos)))
#define setBit(n,pos)(n = n|(1<<pos))

using namespace std;
typedef long long ll;

int state[(MAXN/64)+2];
vector <int> nPrime;
void bitSieve(int n){
    nPrime.push_back(2);
    int pos,limit = sqrt(n*1.0)+2;
    for(int i = 3;i <= n;i+=2){
        pos = (i+1)/2;
        if( !getBit(state[pos>>5],(pos&31)) ){
            nPrime.push_back(i);
            if(i < limit){
                for(int j = i*i;j <= n;j+=(2*i)){
                    pos = (j+1)/2;
                    setBit(state[pos>>5],(pos&31));
                }
            }
        }
    }
}

int maxPowerInFact(int p,int n){
    int pi = p;
    ll ans = 0;
    while(pi <= n){ans += (n/pi);pi *= p;}
    return ans;
}

ll bigMod(int a,int b,int M){
    if (!b)  return 1%M;
    ll x = bigMod(a,b/2,M) ;
    x = ((x%M)*(x%M))%M;
    if(b&1) x = (x*a)%M;
    return x;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    bitSieve(MAXN);

    int T,cn = 1;
    scanf("%d",&T);
	while(T--){
        int n,t;
        ll ans = 1;
        bool impossible = true;

        scanf("%d%d",&n,&t);
        for(int i = 0;i < nPrime.size() && nPrime[i] <= n;i++){
            int p = maxPowerInFact(nPrime[i],n);
            p /= t;
            if(p) impossible = false;
            ans = ((ans%MOD)*bigMod(nPrime[i],p,MOD))%MOD;
        }
        printf("Case %d: %lld\n",cn++,impossible?-1:(ans%MOD));
    }
    return 0;
}
