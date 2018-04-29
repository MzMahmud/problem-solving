#include <stdio.h>
#include <math.h>

double distence(double x1,double y1,double x2,double y2);
double angle(double d,double r1,double r2);
double area(double r,double angl);

double pi = 2*acos(0.0);

int main()
{
    int Case,caseno = 1;
    double x1,y1,r1,x2,y2,r2,temp1,temp2,Angle1,Angle2,d,AREA;

    scanf("%d", &Case);

    while( Case-- ){
        scanf("%lf%lf%lf%lf%lf%lf", &x1,&y1,&r1,&x2,&y2,&r2);

        d = distence(x1,y1,x2,y2);

        if(r1 >= (d + r2))
            AREA = pi*r2*r2;
        else if(r2 >= (d + r1))
            AREA = pi*r1*r1;
        else if(d >= (r1 + r2))
            AREA = 0;
        else{
                Angle1 = angle(d,r1,r2);
                Angle2 = angle(d,r2,r1);

                temp1 = area(r1,Angle1);
                temp2 = area(r2,Angle2);
                AREA  = temp1 + temp2;
        }

        printf("Case %d: %0.10lf\n",caseno++,AREA);
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

double angle(double d,double r1,double r2)
{
    double angl,a,b,c,t,e;

    a = r1*r1;
    b = r2*r2;
    c = d*d;
    t = a - b + c;
    e = (2*r1*d);
    t = t/e;

    angl = acos(t);
    angl = angl*2;

    return angl;
}

double area(double r,double angl)
{
    double ara,a,b;
    a = r*r;
    a = a/2;
    b = sin(angl);
    b = angl - b;
    ara = a*b;

    return ara;
}
