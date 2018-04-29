#include <stdio.h>
#include <math.h>

int perfect_square(long long int );

int main()
{
    long long int number,d,e,root,n,x,y;
    int t,c = 0;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld", &number);
        root = sqrt(number);

        if(perfect_square(number) == 1){
            if(root % 2 == 0) x = root,y = 1;
            else              x = 1,y = root;
        }
        else {
            n = root + 1;
            d = number - ((n-1)*(n-1)), e = (n*n) + 1 - number;

            if(n % 2 == 0){
                if(d <= n)  x =  d,y = n;
                else        x =  n,y = e;
            }
            else {
                if(d <= n) x =  n,y = d;
                else       x =  e,y = n;
            }
        }

        printf("Case %d: %lld %lld\n",++c,x,y);
    }
    return 0;
}

int perfect_square(long long int a)
{
    long long int iroot = sqrt(a);
    long  double droot = sqrt(a);
    if(iroot == droot)
        return 1;
    else
        return 0;
}
