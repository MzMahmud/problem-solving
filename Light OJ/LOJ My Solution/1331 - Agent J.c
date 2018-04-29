#include <stdio.h>
#include <math.h>

double tarea(double r1,double r2,double r3);
double angle(double a,double b,double c);
double carea(double r,double angl);

int main()
{
    int Case,caseno = 1;
    double r1,r2,r3,Angle1,Angle2,Angle3,a,b,c,AREA,t,T;

    scanf("%d", &Case);

    while( Case-- ){
        scanf("%lf%lf%lf", &r1,&r2,&r3);

        a = r1 + r2;
        b = r2 + r3;
        c = r1 + r3;

        Angle1 = angle(a,c,b);
        Angle2 = angle(a,b,c);
        Angle3 = angle(b,c,a);

        t = carea(r1,Angle1);
        t = t + carea(r2,Angle2);
        t = t + carea(r3,Angle3);

        T = tarea(r1,r2,r3);

        AREA = T - t;

        printf("Case %d: %0.10lf\n",caseno++,AREA);
    }
    return 0;
}

double tarea(double r1,double r2,double r3)
{
    double ar,x,y;

    x = r1 + r2 + r3;
    y = r1*r2*r3;
    ar = x*y;
    ar = sqrt(ar);

    return ar;
}

double angle(double a,double b,double c)
{
    double angl,t;

    t = 2*a*b;
    a = a*a;
    b = b*b;
    c = c*c;
    angl = a + b -c;
    angl = angl/t;
    angl = acos(angl);

    return angl;
}

double carea(double r,double angl)
{
    r = r*r;
    r = r/2;

    return (r*angl);
}
