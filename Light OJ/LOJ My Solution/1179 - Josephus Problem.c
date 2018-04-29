#include <stdio.h>

int josephus(int n,int k)
{
    if(n == 1) return 0;
    return (josephus(n-1,k)+k)%n;
}

int main()
{
    int T,cn=1;
    int n,k;

    scanf("%d",&T);
    while(T--){
         scanf("%d%d",&n,&k);
         printf("Case %d: %d\n",cn++,josephus(n,k)+1);
    }
    return 0;
}
