#include <stdio.h>

int main()
{

    int n,m,c[100][100],i,j,ans = 0,min;

    scanf("%d%d", &n,&m);

    for(i = 0;i < n;i++){
        for(j = 0;j < m;j++){
            scanf("%d", &c[i][j]);
        }
    }

    for(i = 0;i < n;i++){
        min = c[i][0];
        for(j = 1;j < m;j++){
            if(c[i][j] < min)
                min = c[i][j];
        }
        if(min > ans)
            ans = min;
    }
    printf("%d\n",ans);
    return 0;
}