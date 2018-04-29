#include <stdio.h>
#include <math.h>

int main()
{
    int Case,counter = 1,a,b,c,mx;

    scanf("%d", &Case);

    while( Case-- ){
            scanf("%d%d%d", &a,&b,&c);
            a = a*a,b = b*b,c = c*c;
            if( a == (b+c) ||b == (c+a) ||c == (a+b))
                printf("Case %d: yes\n",counter++);
            else
                printf("Case %d: no\n",counter++);
    }
    return 0;
}
