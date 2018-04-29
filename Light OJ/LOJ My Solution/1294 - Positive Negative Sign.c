#include <stdio.h>

int main()
{
    long long Case,caseno,n,m;
    caseno = 1;
    scanf("%lld", &Case);
    while( Case-- ){
        scanf("%lld%lld",&n,&m);
        printf("Case %lld: %lld\n",caseno++,(m*n)/2);
    }
    return 0;
}

