/*
    LOJ 1370 - Bi-shoe and Phi-shoe
    Author: Moaz Mahmud
    Date  : 16 Nov,2017

    My Solution:
        phi(p) = p-1,if p is a prime.And primes have more co-prime
        So,for k.For n,if phi(n) >= k,then minimum value of
        n is the nearest prime from k+1.
    END :D :D
*/
#include<cstdio>
#include<cmath>
#define MAXN 1000005

using namespace std;

bool isNotPrime[MAXN>>1];
void primeSieve(int n){
    int limit = sqrt(n+0.0) + 2;
    for(int i = 3;i <= n;i += 2)
        if(!isNotPrime[(i+1)>>1])
            if(i < limit)
                for(int j = i*i;j <= n;j += (i*2))
                    isNotPrime[(j+1)>>1] = 1;
}

int findPrime(int n){
    if(n == 2) return n;
    int i = (n&1)? n : (n+1);
    while(isNotPrime[(i+1)>>1]) i+= 2;
    return i;
}

int main(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    primeSieve(MAXN);//sets the isNotPrime array

    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        int n;
        long long ans = 0;
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            int x;
            scanf("%d",&x);
            ans += findPrime(x+1);
        }
        printf("Case %d: %lld Xukha\n",cn++,ans);
    }
    return 0;
}
