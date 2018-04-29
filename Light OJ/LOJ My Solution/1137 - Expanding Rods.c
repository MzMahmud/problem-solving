#include <stdio.h>
#include <math.h>

double f(double );
int sign(double );

double pi = 2*acos(0.0),l,n,C,L;

int main()
{
    double up,low,mid;
    int t,cn = 1,j;

    scanf("%d",&t);
    while( t-- ){
        scanf("%lf%lf%lf",&l,&n,&C);
        if(n == 0)
            printf("Case %d: %lf\n",cn++,n);
        else{
            L = (1 + (n*C))*l;
            up = 360,low = 0;
            mid = (up + low)/2;
            j = 200;

            while(j--){
                if(sign(f(low)) == sign(f(mid)))
                    low = mid;
                else
                    up = mid;
                mid = (up + low)/2;
                j = abs(f(mid));
            }
            mid = (pi*mid/180);
            mid = (1 - cos(mid/2))*(L/mid);
            printf("Case %d: %0.10lf\n",cn++,mid);
        }
    }
    return 0;
}

double f(double a)
{
    a = (pi*a/180);
    return ((2*L*(sin(a/2))) - (l*a));
}

int sign(double a)
{
    if(a >= 0)
        return 1;
    else
        return -1;
}
