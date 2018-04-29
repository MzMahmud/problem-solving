#include <stdio.h>

int t,c = 1,n;

int main()
{
    scanf("%d", &t);

    while(t--){
        scanf("%d",&n);
        if(n <= 10)
            printf("Case %d: 0 %d\n",c++,n);
        else
            printf("Case %d: 10 %d\n",c++,n - 10);
    }
    return 0;
}
