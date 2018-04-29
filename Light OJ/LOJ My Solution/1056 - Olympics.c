#include <stdio.h>
#include <math.h>

int main()
{
    //freopen("Input.txt","rt",stdin);
    //freopen("Output.txt","wt",stdout);
    int Case,caseno = 1;
    double p,q,r,l,b,angle,t;

    scanf("%d", &Case);

    while( Case-- ){
        scanf("%lf : %lf", &p,&q);
        r = p/q;

        angle = acos(-1) - (2*atan(r));

        t = sqrt(r*r + 1);
        t = angle*t;
        t = t + (2*r);

        l = 400*r/t;
        b = l/r;

        printf("Case %d: %0.10lf %0.10lf\n",caseno++,l,b);
    }
    return 0;
}


