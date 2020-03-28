//TLE :( Optimization Needed

#include <stdio.h>

long long int MOD = 1000000007;

long long int BigMod(long long int a,long long int b,long long int m)
{
    if(b == 0)
        return 1;

    long long int x = BigMod(a,b/2,m);
    x = (x*x) % m;
    if(b % 2 == 1)
        return (x*(a)) % m;
    return x % m;
}

int main()
{

    long long int n,k,sum = 0,i;

    scanf("%I64d%I64d",&n,&k);

    for(i = 1;i <= n;i++){
        sum = ( sum + BigMod(i,k,MOD) ) % MOD;
    }
    printf("%I64d\n",sum % MOD);
    return 0;
}