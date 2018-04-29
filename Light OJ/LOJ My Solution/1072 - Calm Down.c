#include <stdio.h>
#include <math.h>

double pi = acos(-1.0);

int main()
{
    int t,c = 1,n;
    double R,r,A,sine;

    scanf("%d", &t);

    while(t--){
        scanf("%lf%d", &R,&n);

        A = pi/n;
        sine = sin(A);
        r = R*sine/(1 + sine);

        printf("Case %d: %0.10lf\n",c++,r);
    }

    return 0;
}
