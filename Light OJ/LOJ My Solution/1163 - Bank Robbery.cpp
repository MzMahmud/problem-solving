/*
ALGO:
    cutting off the last digit of a means to find floor(a/10)
    so the given number is,a - floor(a/10) = k
    now,a - 10*floor(a/10) = {0,1,2,...,9}
    so,10k = 10a - 10*floor(a/10) = 9a + a - 10*floor(a/10)
       9a + {0,1,2,...,9} = 10k
       a = ( 10k - {0,1,2,...,9} )/9
    now a >= 10 and is integer
    called to print in ascending order so the loop is run from 9 to 0 */
#include <stdio.h>

int main()
{
    int T,cn = 1,i;
    unsigned long long k;

    scanf("%d", &T);
    while(T--){
        scanf("%llu", &k);
        printf("Case %d:",cn++);
        for(i = 9;i >= 0;i--){
            if( (10*k - i) % 9 == 0 ){
                if( (10*k - i)/9 > 9 )
                    printf(" %llu",(10*k - i)/9);
            }
        }
        printf("\n");
    }

    return 0;
}
