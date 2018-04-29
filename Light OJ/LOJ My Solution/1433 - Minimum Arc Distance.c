#include <stdio.h>
#include <math.h>

double distence(double x1,double y1,double x2,double y2);
double angle(double d,double r);

int main()
{
    int Case,caseno = 1;
    double x1,y1,x2,y2,x3,y3,m1,m2,r,temp,temp1,Angle,d,dist;

    scanf("%d", &Case);

    while( Case-- ){
        scanf("%lf%lf%lf%lf%lf%lf", &x1,&y1,&x2,&y2,&x3,&y3);

        d = distence(x2,y2,x3,y3);
        r = distence(x1,y1,x2,y2);
        Angle = angle(d,r);

        dist = Angle*r;

        printf("Case %d: %0.10lf\n",caseno++,dist);
    }
    return 0;
}

double distence(double x1,double y1,double x2,double y2)
{
    double d,a,b;

    a = (x1 - x2)*(x1 - x2);
    b = (y1 - y2)*(y1 - y2);

    d = a + b;
    d = sqrt(d);
    return d;
}

double angle(double d,double r)
{
    double angl,t;

    t = d/r;
    t = t*t;
    t = t/2;
    t = 1 - t;
    angl = acos(t);

    return angl;
}
