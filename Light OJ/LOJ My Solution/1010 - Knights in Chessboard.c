#include <stdio.h>

int Knight(int ,int );
int Max(int ,int );
int seeling(int );

int main()
{
    freopen("Input.txt", "rt", stdin);
    freopen("Output.txt", "wt", stdout);

    int Case,caseno = 1;
    int m,n,knight;

    scanf("%d", &Case);

    while( Case-- ){
        scanf("%d%d", &m,&n);

        knight = Knight(m,n);

        printf("Case %d: %d\n",caseno++,knight);
    }

    return 0;
}

int Knight(int m,int n)
{
    int d;

    if( m == 1 || n == 1)
        return Max(m,n);

    else if(m == 2 || n == 2){
        d = Max(m,n);

        if(d % 2 == 0){
            d = d / 2;
            return seeling(d)*4;
        }

        else
            return (d + 1);
    }

    else{
        d = m*n;
        return seeling(d);
    }

}

int Max(int a,int b)
{
    if(a >= b)
        return a;
    else
        return b;
}

int seeling(int a)
{
    if(a % 2 == 0)
        return (a/2);
    else
        return (a/2 + 1);
}
