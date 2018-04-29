#include <stdio.h>
#include <math.h>

double triangle_area(double a,double b,double c);
double distence(double x1,double y1,double x2,double y2);

int main()
{
    //freopen("Input.txt","rt",stdin);
    //freopen("Output.txt","wt",stdout);

    int Case,caseno = 1;
    double x1,y1,x2,y2,x3,y3,x,y,m1,m2,c1,c2,AREA,l,b,d;

    scanf("%d", &Case);

    while( Case-- ){
        scanf("%lf%lf%lf%lf%lf%lf", &x1,&y1,&x2,&y2,&x3,&y3);

        l = distence(x1,y1,x2,y2);
        b = distence(x2,y2,x3,y3);
        d = distence(x1,y1,x3,y3);
        AREA = triangle_area(l,b,d);
        AREA = 2*AREA;

        m1 = (y3 - y2)/(x3 - x2);
        m2 = (y2 - y1)/(x2 - x1);

        c1 = y1 - (m1*x1);
        c2 = y3 - (m2*x3);

        if(AREA == 0){
            x = x2;
            y = y2;
        }

        else if( x1 == x2){
            x = x3;
            y = m1*x + c1;
        }

        else if( x2 == x3){
            x = x1;
            y = m2*x + c2;
        }

        else {
            x = (c2 - c1)/(m1 - m2);
            y = m1*x + c1;
        }

        printf("Case %d: %0.0lf %0.0lf %0.0lf\n",caseno++,x,y,AREA);
    }
    return 0;
}

double triangle_area(double a,double b,double c)
{
    double s,area,A,B,C;

    s = (a + b + c)/2;
    A = s - a;
    B = s - b;
    C = s - c;
    area = s*A*B*C;
    area = sqrt(area);

    return area;
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
