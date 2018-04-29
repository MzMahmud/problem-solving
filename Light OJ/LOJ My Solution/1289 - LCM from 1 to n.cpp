/*
    LOJ 1289 - LCM from 1 to n
    Author: Moaz Mahmud
    Date  : 17 Nov,2017

    My Solution:
        LCM(1,2,..,n) is the product of the maximum power of every
        prime <= n.But this implementation would give TLE.
        An observation,every prime > sqrt(n) has maximum power of 1.
        But they are needed to be multiplied.
        So primeProduct[i] is pre-calculated with product of every prime <= i.
        So the the LCM would be p^(max power - 1)*primeProduct[i],
        for all primes p <= sqrt(n) and i is the index of maximum prime <= n.
        p^(max power - 1), this -1 because primeProduct[i] already has a p.
        The problem said to give mod 2^32.
        Interestingly its enough to store the result in a 32 unsigned int
        and operate only +,-,*.
    END :D :D
*/
#include <cstdio>
#include <cmath>
#define MAXN 100000005
#define MAXP 5761460
#define decode(x) ((x >= 0)? x :(-1*(x+1)))
#define getBit(n,pos)((bool)(n&(1<<pos)))
#define setBit(n,pos)(n = n|(1<<pos))

using namespace std;

int binarySearch(unsigned x,unsigned a[],int size){
    int pos,low,up,mid;
    low = 0,up  = size - 1;
    while(low <= up){
        mid = (low+up)/2;
        if(a[mid] == x) return mid;//if found returns the found index
        else if(x > a[mid]) low = mid + 1;
        else if(x < a[mid]) up  = mid - 1;
    }
	if(x > a[mid]) mid++;
    return -1*(mid+1);
}

int state[(MAXN/64)+2];
unsigned nPrime[MAXP];
int primeCount = 0;
void bitSieve(int n){
    nPrime[primeCount++] = 2;//2 is the first prime
    int pos,limit = sqrt(n*1.0)+2;
    for(int i = 3;i <= n;i+=2){
        pos = (i+1)/2;
        if( !getBit(state[pos>>5],(pos&31)) ){
            nPrime[primeCount++] = i;
            if(i < limit){
                for(int j = i*i;j <= n;j+=(2*i)){
                    pos = (j+1)/2;
                    setBit(state[pos>>5],(pos&31));
                }
            }
        }
    }
}

unsigned primeProduct[MAXP];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    bitSieve(MAXN);
    primeProduct[0] = 2;//2 is the first prime
    for(int i = 1;i < MAXP;i++)
        primeProduct[i] = primeProduct[i-1]*nPrime[i];//stores product of primes

    int T,cn = 1;
    scanf("%d",&T);
	while(T--){
        unsigned n,ans = 1;

        scanf("%u",&n);

        for(int i = 0;nPrime[i]*nPrime[i] <= n;i++){
            unsigned temp = n/nPrime[i],p = nPrime[i];
            while(temp >= p){ans *= nPrime[i];p*=nPrime[i];}
        }

        int pos = binarySearch(n,nPrime,primeCount);
        if(pos >= 0) ans *= primeProduct[pos];
        else         ans *= primeProduct[decode(pos)-1];
        printf("Case %d: %u\n",cn++,ans);
    }
    return 0;
}
