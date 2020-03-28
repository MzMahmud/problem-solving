#include <stdio.h>

int finite(void)
{
    int i,move[100001],k,n,count;
    char direction[100001];
    char c;

    scanf("%d", &n);

    scanf("%s", direction);

    for(i = 0;i < n;i++){
        scanf("%d", &move[i]);
        if(direction[i] == '<')
            move[i] *= -1;
    }

    if( move[0] < 0  )  return 1;

    k = 0;
    i = 1,count = 0;
    while( k >= 0 && k < n ){
        count++;
        k = k + move[k];
        if( count >  100001)
            return 0;
    }
    return 1;
}

int main()
{
    //freopen("Input.txt","r",stdin);
    if( finite() == 1 )
         printf("FINITE\n");
    else printf("INFINITE\n");
    return 0;
}