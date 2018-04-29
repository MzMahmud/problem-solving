#include <stdio.h>
#include <math.h>

double pi = 2*acos(0.0);

int main()
{
    int Case,counter = 1;
    double radius,area,temp;
    temp = (4 - pi);

    scanf("%d", &Case);

    while( Case-- ){
        scanf("%lf", &radius);

        area = temp*radius*radius;

        printf("Case %d: %0.2lf\n", counter++,area);
    }
    return 0;
}


