#include <stdio.h>

int main()
{
    //freopen("Input.txt", "rt", stdin);
    //freopen("Output.txt", "wt", stdout);

    int Case,counter = 1,k,p;
    long long int w,n,m,d;

    scanf("%d", &Case);
    while( Case-- ){
        scanf("%lld", &w);
        if( w % 2 == 1)
            printf("Case %d: Impossible\n",counter++);
        else{

            for(k = 1;;k++){
                p = pow(2,k);
                d = w/p;
                if(d % 2 == 1)
                    break;
            }
            m = p;
            n = w/m;
            printf("Case %d: %lld %lld\n",counter++,n,m);
        }
    }
    return 0;
}
