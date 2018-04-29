#include <stdio.h>
int main()
{
    long long a,b;
    while(scanf("%lld %lld",&a,&b)==2){
        long long sum=a-b;
        if(sum<0)sum=sum*-1;
        printf("%lld\n",sum);
    }
    return 0;
}
