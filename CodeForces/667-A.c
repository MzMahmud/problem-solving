#include <stdio.h>
#include <math.h>

double pi = acos(-1.0);

double glass(double d,double h,double v,double e)
{
    double v_0,r,t;

    v_0 = pi*d*d*h/4.0;
    r   = pi*d*d*e/4.0;

    if( v <= r )
        return -1.0;

    t = v_0/(v-r);
    if(t > 10000.0)
        return -1.0;

    return t;
}

int main()
{
    double d,h,v,e,ans;

    scanf("%lf%lf%lf%lf",&d,&h,&v,&e);

    ans = glass(d,h,v,e);
    if( ans == -1 )
        printf("NO\n");
    else{
        printf("YES\n");
        printf("%.10lf\n",ans);
    }
    return 0;
}