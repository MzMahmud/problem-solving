#include <stdio.h>
#include <math.h>

int main()
{
    int Case,caseno = 1;
    double ab,ac,bc,ratio,ad,d,x;

    scanf("%d", &Case);

    while( Case-- ){
        scanf("%lf%lf%lf%lf", &ab,&ac,&bc,&ratio);

        x = ratio/(ratio + 1);
        d = sqrt(x);
        ad = ab*d;

        printf("Case %d: %0.10lf\n",caseno++,ad);
    }
    return 0;
}
