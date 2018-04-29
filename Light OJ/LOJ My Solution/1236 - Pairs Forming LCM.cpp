/*
    LOJ 1236 - Pairs Forming LCM
    Author: Moaz Mahmud
    Date  : 25 Nov,2017

    My Solution:
        let n = prod p^a, be the prime factorize form of n.
        now for (i,j) <= n being lcm(i,j) = n the max power
        of p in (i,j) must be a.So,p^a must be in i or j or both.
        There can be two cases:
            1) i has p^a: so j has {0,1,2,...,a}
            2) j has p^a: so i has {0,1,2,...,a}
        So total way, way = prod (2a + 1).
        But here i <= j pair are wanted.
        Now there are one case only when i = j.Rest are (i,j) and (j,i).
        So pairs are = (way-1)/2 + 1.
    END :D :D
*/
#include <cstdio>
#include <cmath>
#include <vector>
#define MAXN 10000005
#define MAXP 664579
#define getBit(n,pos)((bool)(n&(1<<pos)))
#define setBit(n,pos)(n = n|(1<<pos))

using namespace std;

int state[(MAXN/64)+2];
int nPrime[MAXP];
int piN = 0;
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
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    bitSieve(MAXN);

    int T,cn = 1;
    scanf("%d",&T);
	while(T--){
        long long n,ans = 1;
        scanf("%lld",&n);
        for(int i = 0;i < piN && nPrime[i]*nPrime[i] <= n;i++){
            int pwr = 0;
            while(!(n%nPrime[i])){pwr++;n /= nPrime[i];}
            ans *= (2*pwr + 1);
        }
        if(n > 1) ans *= 3;//if n != 1 its a prime with power 1.Thats why ans *= (2*1 + 1)
        ans = (ans-1)/2 + 1;
        printf("Case %d: %lld\n",cn++,ans);
    }
    return 0;
}
