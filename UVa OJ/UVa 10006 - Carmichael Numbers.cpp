/*
ALGO:
    Korselt's criterion
    A positive composite integer n is a Carmichael number if and only if
    n is square-free and for all prime divisors p of n
    it is true that (p-1)|(n-1).
    It follows from this theorem that all Carmichael numbers are odd,
    since any even composite number that is square-free
    (and hence has only one prime factor of two) will have at least
    one odd prime factor, and thus
    (p - 1)|(n - 1) results in an even dividing an odd, a contradiction.
*/

#include <bits/stdc++.h>
#define SIZE 65002

using namespace std;

bool isPrime[SIZE/2];
vector <unsigned int> nPrime;
void primeSieve(int n)
{
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

bool isCarmichael(int n){
    if(!(n&1)) return false;//Even are not Carmichael
    //Primes are not Carmichael
    if(n == 2) return false;
    if(!isPrime[(n+1)/2]) return false;

    for(int i = 0;i < nPrime.size() && nPrime[i] <= n;i++){
        int power = 0;
        if(!(n%nPrime[i])){
            if(!((n/nPrime[i])%nPrime[i]))
                return false;
            if((n-1)%(nPrime[i]-1))
                return false;
        }
    }
    return true;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    primeSieve(SIZE);

    int n;

    cin >> n;
    while(n){
        if(isCarmichael(n))
            printf("The number %d is a Carmichael number.\n",n);
        else
            printf("%d is normal.\n",n);
        cin >> n;
    }
    return 0;
}
