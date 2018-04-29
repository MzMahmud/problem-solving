#include <stdio.h>
#include <math.h>

double volume(double x,double y,double z);

double pi = 2*acos(0.0);

int main()
{
    freopen("Input.txt", "rt",stdin);
    freopen("Output.txt", "wt",stdout);

    int Case,counter = 1;
    double r1,r2,h,p,r3,x,vol,temp;

    scanf("%d", &Case);

    while( Case-- ){

        scanf("%lf%lf%lf%lf", &r1,&r2,&h,&p);

        x = h*r2/(r1-r2);
        temp = (x+p)/(x+h);
        r3 = temp*r1;

        vol = volume(r3,r2,p);

        printf("Case %d: %0.9lf\n",counter++,vol);
    }
    return 0;
}

double volume(double r1,double r2,double h)
{
    double a,b,c,A,d,v;
    a = r1*r1;
    b = r1*r2;
    c = r2*r2;
    A = a + b + c;
    d = pi*h/3;
    v = d*A;
    return v;
}

