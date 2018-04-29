/*
Solution:
    a 2D point can be thought as a vector.
    |
    |
    |                  .B(b1,b1)
    |
    |    .A(a1,a2)
    |
    |______________________________
    the line AB's vector form is
    AB = a + (b-a)t1,where t1 is any number
    for the line segment 0 <= t1 <= 1.
    Now for other segment CD,
    CD = c + (d-c)t2.

    Now at any time t the person on AB is at K(k1,k2)
    so, AK = a + (a-b)t and CK = c + (c-d)t
    these t are same as the two are going at
    constant velocity.to verify put t = 0 then
    both of them are at A and C.t = 1,both of them are at B
    and D.
    Their distance is |AK-CK|,that is the length.
    Now the function is first decreasing,reach to minimum
    and then increasing.
    |
    |.              .
    | .           .
    |  .        .
    |    .    .
    |      ..
    |____________________
    So ternary search condition would be.
    *if(f(mid1) < f(mid2)) high = mid2;
    *if(f(mid1) > f(mid2)) low  = mid1;
    *if(f(mid1)== f(mid2)) low  = mid1,high = mid2;
    f(t) denotes their distance.
    Now the solution is in the segment,so run
    ternary search on t in range [0,1];
    the answer is f(t) :D

SOLUTION and CODE by MoaZ.
*/

#include <bits/stdc++.h>

using namespace std;

struct Vector{
    double x,y;

    Vector(double _x,double _y){x = _x,y = _y;}
    Vector(){}
    double length(){
        return sqrt(x*x+y*y);
    }
    Vector operator-(Vector a){
        Vector temp(x-a.x,y-a.y);
        return temp;
    }
    Vector operator+(Vector a){
        Vector temp(x+a.x,y+a.y);
        return temp;
    }
    Vector operator*(double a){
        Vector temp(x*a,y*a);
        return temp;
    }
};

Vector a,b,c,d;

double f(double t){
    Vector ak,ck;
    ak = a + (b-a)*t;
    ck = c + (d-c)*t;
    return (ck-ak).length();
}

double ternarySearch(double (*f)(double),double low,double high){
    int k = 100;
    double mid1,mid2;
    while(k--){
        mid1 = low  + (high-low)/3;
        mid2 = high - (high-low)/3;

        if( f(mid1) < f(mid2) )
            high = mid2;
        else if( f(mid1) == f(mid2) )
            low = mid1,high = mid2;
        else
            low = mid1;
    }
    return (mid1 + mid2)/2;
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,cn = 1;
    scanf("%d",&T);
    while(T--){
        double t;
        scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
        scanf("%lf%lf%lf%lf",&c.x,&c.y,&d.x,&d.y);
        t = ternarySearch(f,0,1);
        printf("Case %d: %.10lf\n",cn++,f(t));
    }
    return 0;
}
