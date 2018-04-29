/*
ALGO:
    Linear Diophantine Equation.
    ax + by = c
    d = gcd(a,b)
    if d|c then integer Solution exists.
    Then,
        if (x',y') is a solution then
            x = x' + k(b/d)
            y = y' - k(a/d)
    As 2 integer point is given so solution exists.
    (x1,y2),(x2,y2) is given.
    a = y1 - y2,b = x2 - x1,c = x1(y1-y2) - y1(x1-x2)
    to be in the segment:
        x1 <= x1 + k1(b/d) <= x2 && y1 <= y1 + k2(b/d) <= y2
        0 <= k1 <= (x2-x1)/(b/d) && 0 <= k2 <= (y2-y1)/(a/d)
        ans = min(k1,k2) + 1
    **Every value is absolute
    SPECIAL CASE:
        x1 == x2:
            ans = |y1-y2| + 1
        y1 == y2:
            ans = |x1-x2| + 1

*/

#include <stdio.h>
#define Abs(x)   ( x < 0 ? -x : x)
#define min(x,y) ( x < y ? x  : y)

typedef long long int ll;

ll gcd(ll a,ll b)
{
    a = Abs(a),b = Abs(b);
    ll r = 1;
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    while( r ){
        r = b % a;
        b = a;
        a = r;
    }
    return b;
}

int main()
{
    int T,cn = 1;
    ll ax,ay,bx,by,a,b,c,d,ans,kx,ky;

    scanf("%d", &T);
    while(T--){
        scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);

        if(ay == by)
            ans = Abs( (ax - bx) ) + 1;
        else if(ax == bx)
            ans = Abs( (ay - by) ) + 1;
        else{
            a = ay - by,b = bx - ax,c = ( ax*(ay - by) ) - ( ay*(ax - bx) );
            d = gcd(a,b);

            kx  = ( Abs((ax-bx)))/(Abs(b)/d);
            ky  = ( Abs((ay-by)))/(Abs(a)/d);

            ans = min(kx,ky) + 1;
        }
        printf("Case %d: %lld\n", cn++,ans);

    }
    return 0;
}
