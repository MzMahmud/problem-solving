#include <stdio.h>

int main()
{
    int Case,caseno = 1;
    double a,b,c,d,p,q;

    scanf("%d" ,&Case);

    while( Case-- ){
        scanf("%lf%lf%lf", &a,&b,&c);

        p = a*c/b;

        if( (b - p) <= 0)
            printf("Case %d: -1\n",caseno++);

        else{
            q = (a + p);
            q = q*(c + p);
            q = q/(b - p);

            printf("Case %d: %0.10lf\n",caseno++,p + q);
        }
    }
    return 0;
}
