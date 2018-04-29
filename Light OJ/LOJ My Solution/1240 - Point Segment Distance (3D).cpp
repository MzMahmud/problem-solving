/*
Solution:
    Solution is similar to
    LOJ 1146 - Closest Distance.
    All those holds good in both
    2D and 3D because vector process
    is same in both :D
*/
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct Vector{
    double x,y,z;

    Vector(double _x,double _y,double _z){x = _x,y = _y,z = _z;}
    Vector(){}
    double length(){
        return sqrt(x*x+y*y+z*z);
    }
    Vector operator-(Vector a){
        Vector temp(x-a.x,y-a.y,z-a.z);
        return temp;
    }
    Vector operator+(Vector a){
        Vector temp(x+a.x,y+a.y,z+a.z);
        return temp;
    }
    Vector operator*(double a){
        Vector temp(x*a,y*a,z*a);
        return temp;
    }
};

Vector a,b,p;

double f(double t){
    Vector ak;
    ak = a + (b-a)*t;
    return (ak-p).length();
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
        scanf("%lf%lf%lf",&a.x,&a.y,&a.z);
        scanf("%lf%lf%lf",&b.x,&b.y,&b.z);
        scanf("%lf%lf%lf",&p.x,&p.y,&p.z);
        t = ternarySearch(f,0,1);
        printf("Case %d: %.10lf\n",cn++,f(t));
    }
    return 0;
}
