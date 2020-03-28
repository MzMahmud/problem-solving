#include <stdio.h>
#include <math.h>

int main()
{
    int n,ans = 1;

    scanf("%d", &n);

    if(n % 3 == 0)
        ans = 0;
    ans = 2*(n/3) + ans;

    printf("%d\n", ans);
    return 0;
}