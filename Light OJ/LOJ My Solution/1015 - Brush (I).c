#include <stdio.h>
#include <math.h>


int main()
{
    int Case,counter = 1,num,total,temp;

    scanf("%d", &Case);

    while( Case-- ){
        scanf("%d", &num);
        total = 0;
        while( num -- ){
            scanf("%d", &temp);
            if( temp >= 0)
                total += temp;
        }
        printf("Case %d: %d\n", counter++,total);
    }
    return 0;
}


