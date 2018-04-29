/*
    LOJ 1341 - Aladdin and the Flying Carpet
    Author: Moaz Mahmud
    Date  : 17 Nov,2017

    My Solution:
        This looks like a straight forward one,but is not.
        The ans is #divisor pair (p,q) such that p >= b,q >= b and p != q.
        here a is the area,b is the minimum length.
        An idea man be,
        for i = b  to sqrt(a)
            if i divides n
                count++;
        for T test cases its O(T sqrt(n))
        which would give TLE ans T <= 4*10^4 and a <= 10^12.
        So better idea is to get tao(a) = #divisor of a and then
        just leave those divisor which is < b.
        tao(n)  is calculated by product of prime power.

    END :D :D
*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#define MAXN 1000005
#define getBit(n,pos)((bool)(n&(1<<pos)))
#define setBit(n,pos)(n = n|(1<<pos))

using namespace std;

typedef long long ll;

int state[(MAXN/64)+2];
vector <unsigned int> nPrime;
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

ll tao(ll n){
    ll t = 1;
    for(int i = 0;i < nPrime.size() && nPrime[i]*nPrime[i] <= n;i++){
        ll p = 0;
        while(!(n%nPrime[i])){n/=nPrime[i];p++;}
		//this reduces runtime.Every time n gets smaller
        t *= (p + 1);
    }
    if(n != 1) t *= 2;
    return t;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    bitSieve(MAXN);

    int T,cn = 1;
    scanf("%d",&T);
	while(T--){
        ll n,b,ans;
        scanf("%lld%lld",&n,&b);
        if(b*b >= n) ans = 0;
        else{
            ans = tao(n)/2;
			//the square part is taken care of automatically.As,for
            //square tao(n) is odd.So the odd one is reduced dividing by 2
            for(int i = 1;i < b;i++) if(!(n%i)) ans--;
        }
        printf("Case %d: %lld\n",cn++,ans);
    }

    return 0;
}
