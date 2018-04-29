#include <stdio.h>

int main()
{
    int t,cn = 1,n,b,a,d,e,count = 0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        b = 2;
        while(n--){
            scanf("%d",&a);
            d = a - b;
            if(d != 0){
                e = ((d-1)/5) + 1;
                count += e;
            }
            b = a;
        }
        printf("Case %d: %d\n",cn++,count);
        count = 0;
    }
    return 0;
}
