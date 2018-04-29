#include <stdio.h>

double L[1000006],r;

int main()
{
    int t,c = 1,i,ans,n,b;
    L[0] = 0;
    for(i = 1;i < 1000006;i++)
        L[i] = L[i-1] + log10(i*1.0);

    scanf("%d",&t);
    while(t--){
        scanf("%d%d", &n,&b);
        r = L[n]/log10(b*1.0);
        ans = r + 1;
        printf("Case %d: %d\n",c++,ans);
    }
    return 0;
}
