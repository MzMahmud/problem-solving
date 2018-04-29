/*
    //LOJ 1215 - Finding LCM
    Author: Moaz Mahmud
    Date  : 14 May,2017

    My Solution:
        Notation ::
            * [a,b] means LCM(a,b)
            * ~|    means does not divide

        [a,b,c] = [[a,b],c] = [l,c] = L.
        a,b,L is given so l,L known.
        Now if l ~| L there can be no c.
        an example,
            l = 5^7*3^7*2^7;L = 5^9*3^8*2^7*7
        clearly,c_min = 5^9*3^8*7
        now, d = L/l = 5^2*3*7
        now the answer is d*(l without primes that belongs in both d and l);
    END
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#define SIZE 1000005
#define LCM(a,b) (a/__gcd(a,b)*b)

typedef long long ll;

using namespace std;

bool isPrime[SIZE/2];
vector <int> nPrime;
void primeSieve(int n){
    nPrime.push_back(2);

    int limit = sqrt(n+0.0) + 2;
    for(int i = 3;i <= n;i += 2){
        if( !isPrime[(i+1)/2] ){
            nPrime.push_back(i);
            if(i < limit){
                for(int j = i*i;j <= n;j += (i*2) ){
                    isPrime[(j+1)/2] = 1;
                }
            }
        }
    }
}

ll solve(ll a,ll b,ll L){
    if((L%a)||(L%b)) return -1;//a ~| L or b ~| L impossible
    ll l = LCM(a,b);
    ll d = L/l;

    for(int i = 0;i < nPrime.size() && nPrime[i] <= l;i++){
        if(!(l%nPrime[i]) && (d%nPrime[i])){
            while(!(l%nPrime[i]))
                l /= nPrime[i];
        }
    }//removing common primes is in l and d

    return l*d;
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    primeSieve(SIZE);

    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        ll a,b,l,ans;
        scanf("%lld%lld%lld", &a,&b,&l);
        ans = solve(a,b,l);
        if(ans < 0) printf("Case %d: impossible\n",cn++);
        else        printf("Case %d: %lld\n",cn++,ans);
    }
    return 0;
}
