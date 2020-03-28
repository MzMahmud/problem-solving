#include <stdio.h>
#include <math.h>
#include <string.h>

typedef long long int ll;

int main()
{
    int a,b,n,ans;

    scanf("%d%d%d",&n,&a,&b);

    ans = ( (a + b + n - 1)% n + n ) % n + 1;

    printf("%d\n",ans);

    return 0;
}