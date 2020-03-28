#include <stdio.h>

int zero(int n)
{
    int z = 0,k = 1;
    k = 5;
    while( k <= n){
        z += (n/k);
        k *= 5;
    }
    return z;
}

int main()
{
    int n,k,flag = 1;

    scanf("%d",&n);

    for(k = 4*n; ;k++){
        if( zero(k) == n ){
            flag = 0;
            printf("5\n");
            printf("%d %d %d %d %d\n",k,k+1,k+2,k+3,k+4);
            break;
        }
        if( zero(k) > n )
            break;
    }

    if( flag )
        printf("0\n");
    return 0;
}