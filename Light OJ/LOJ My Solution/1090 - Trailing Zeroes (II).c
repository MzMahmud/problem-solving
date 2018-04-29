#include <stdio.h>
#define min(x,y) (x < y? x:y)

int PrimePower(int ,int );
int PrimePower2(int ,int );

int main()
{
    int tc,cn = 1;
    int n,r,p,q;
    long long int count0,count2,count5;

    scanf("%d", &tc);
    while( tc-- ){
        scanf("%d%d%d%d", &n,&r,&p,&q);

        count2 = PrimePower(2,n) - (PrimePower(2,r)+PrimePower(2,(n-r)));
        count5 = PrimePower(5,n) - (PrimePower(5,r)+PrimePower(5,(n-r)));
        count2 += ((PrimePower2(2,p))*q);
        count5 += ((PrimePower2(5,p))*q);
        count0 = min(count2,count5);
        printf("Case %d: %lld\n",cn++,count0);
    }
    return 0;
}

int PrimePower(int a,int n)
{
    int zero = 0,k = a;
    while(k <= n){
        zero = zero + (n/k);
        k = k*a;
    }
    return zero;
}

int PrimePower2(int a,int n)
{
    int zero = 0,k = a;
    while(k <= n){
        if( n % k == 0 )
            zero++;
        k = k*a;
    }
    return zero;
}
