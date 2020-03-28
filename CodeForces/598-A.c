#include <stdio.h>

long long f2k(long long n)
{
    int k = 0,a = 2;

    while(a <= n){
        k++;
        a *= 2;
        //printf("k %d a %d\n",k,a);
    }
    return k;
}

int main()
{

    long long p2[30],a = 1,i,n,sum;

    p2[0] = 1;
    for(i = 1;i < 30;i++){
        a *= 2;
        p2[i] = p2[i-1] + a;
    }

    int T;
    scanf("%d", &T);

    while( T-- ){
        scanf("%lld", &n);

        sum = (n*(n+1))/2;
        sum = sum - 2*(p2[f2k(n)]);
        printf("%I64d\n",sum);
    }

    return 0;
}