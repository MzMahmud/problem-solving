#include <stdio.h>

int main()
{
    //freopen("Input.txt", "rt",stdin);
    //freopen("Output.txt", "wt",stdout);

    int tcase,caseno = 1;
    double v1,v2,v3,a1,a2,D,d,T1,T2,T;

    scanf("%d", &tcase);

    while( tcase-- ){
        scanf("%lf%lf%lf%lf%lf", &v1,&v2,&v3,&a1,&a2);

        T1 = v1/a1;
        T2 = v2/a2;
        if(T1 >= T2)
            T = T1;
        else
            T = T2;

        D = (v1*v1/(2*a1)) + (v2*v2/(2*a2));
        d = v3*T;

        printf("Case %d: %0.10lf %0.10lf\n",caseno++,D,d);
    }
    return 0;
}
