#include <stdio.h>

int main()
{
    long long int n,sum = 0,way,gen[11] = {0},m,i,j;

    scanf("%I64d%I64d", &n,&m);
    for(i = 1;i <= n;i++){
        scanf("%lld", &j);
        gen[j]++;
    }
    for(i = 1;i <= m;i++){
        sum +=  ( (gen[i])*(gen[i]-1) )/2;
    }
    way = ( n*(n-1) )/2 - sum;
    printf("%I64d\n",way);
    return 0;
}