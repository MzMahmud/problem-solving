#include <stdio.h>
#include <math.h>

int main()
{
    int t,caseno=1;
    long long int sum,n,N;

    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        N = n;
        sum = sqrt(n);
        n=n/2;
        sum = sum + sqrt(n);
        /*
        We know from Number Theory,sigma(n) is odd when n is of the form N^2*2^k,k >=0,k belongs to Z.
        That means,sigma(n) is odd when n is perfect square or n/2 is perfect square.
        So for odd it's needed find perfect square upto n and n/2.
        so even sigma(n) = n - (int(sqrt(n)) + int(sqrt(n/2))).
        */
        printf("Case %d: %lld\n",caseno++,N-sum);
    }
    return 0;
}
