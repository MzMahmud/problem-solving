#include <stdio.h>

int main()
{
    //freopen("Input.txt", "rt",stdin);
    //freopen("Output.txt", "wt",stdout);

    int Case,caseno = 1,a,b,x,A,B,count;

    scanf("%d", &Case);

    while( Case-- ){
        scanf("%d%d",&a,&b);

        x = a % 3;
        if( x == 0 )
            A = a + 1;
        else if( x == 1)
            A = a;
        else if( x == 2)
            A = a + 2;

        x = b % 3;
        if( x == 0 )
            B = b - 2;
        else if( x == 1)
            B = b;
        else if( x == 2)
            B = b - 1;

        count = (B - A)/3;
        count = (b - a) - count;

        printf("Case %d: %d\n",caseno++,count);
    }
    return 0;
}
