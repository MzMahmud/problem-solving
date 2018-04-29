#include <iostream>
#include <cstdio>

using namespace std;

int pow2(int  n)
{
    if(!n) return 1;
    return 2*pow2(n-1);
}

bool isPrime(int n)
{
    if(n < 2)     return 0;
    if(n == 2)    return 1;
    if( !(n & 1) )return 0;

    for(int i = 3;i*i <= n;i += 2)
        if( n % i == 0 ) return 0;

    return 1;
}

int main()
{
    int a[10]= {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int i,T,n;

    bool primes[32] = {};
    for(i = 0;i < 10;i++) primes[ a[i] ] = 1;

    bool prime2[32] = {};
    for(i = 0;i < 10;i++)
        if( isPrime( (pow2(a[i]) - 1) ) )
            prime2[a[i]] = 1;

    scanf("%d", &T);
    while( T-- ){
        scanf("%d,", &n);
        if( n > 30 ){
            printf("No\n");
            continue;
        }

        if( primes[n] && prime2[n] )
             printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
