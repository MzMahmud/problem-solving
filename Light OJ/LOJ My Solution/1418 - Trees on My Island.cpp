/*
    LOJ 1418 - Trees on My Island
    Author: Moaz Mahmud
    Date  : 09 Oct,2017

    My Solution:
        Pick's Theorem: A = i + b/2 - 1.
        A = Area of polygon,
        i = Lattice points inside polygon,
        b = Lattice points on boundary of polygon.

        Finding A:
            Area of polygon is found by Shoelace formula(cross matrix).
        Finding b:
            Lattice points on a line going through two points is, gcd(|Dell(x)|,|Dell(y)|) + 1.
        The Question asks for i.
        So, DONE :D
    END :D :D
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#define ABS(x) (x < 0?-x:x)

using namespace std;

int main(){
    int T,cn = 1,n;
    scanf("%d", &T);
    while(T--){
        long long sum = 0,dif = 0,A,b = 0,i;
        long long x1,y1,xp,yp,xc,yc;

        scanf("%d", &n);
        scanf("%lld%lld",&x1,&y1);
        xp = x1;yp = y1;
        for(int i = 1;i < n;i++){
            scanf("%lld%lld",&xc,&yc);
            b = b + __gcd( ABS( (xc-xp) ),ABS( (yc-yp) ) );
            //One is not added because AB line next BC line so B is over counted
            sum = sum + xp*yc;
            dif = dif + yp*xc;
            xp = xc,yp = yc;
        }
        b = b + __gcd( ABS( (x1-xp) ),ABS( (y1-yp) ) );
        sum = sum + xp*y1;
        dif = dif + yp*x1;
        A = ABS( (sum-dif) );//this is actually 2A
        i = (A + 2 - b)/2;
        printf("Case %d: %lld\n",cn++,i);

    }
    return 0;
}
