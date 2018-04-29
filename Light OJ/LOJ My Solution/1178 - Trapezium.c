#include <stdio.h>
#include <math.h>

double triangle_area(double a,double b,double c);

int main()
{
    int Case,caseno = 1;
    double a,b,c,d,AREA,tarea,temp1,temp2;

    scanf("%d", &Case);

    while( Case-- ){
        scanf("%lf%lf%lf%lf", &a,&b,&c,&d);

        temp1 = a - c;
        tarea = triangle_area(temp1,d,b);
        temp1 = 2*c/(a - c);
        temp2 = temp1 + 1;
        AREA = tarea*temp2;

        if(AREA < 0)
            printf("Case %d: %lf\n",caseno++,AREA*(-1));
        else
            printf("Case %d: %lf\n",caseno++,AREA);
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

