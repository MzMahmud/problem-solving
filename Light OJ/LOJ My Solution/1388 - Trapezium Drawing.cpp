/*
    LOJ 1388 - Trapezium Drawing
    Author: Moaz Mahmud
    Date  : 28 Oct,2017

    My Solution:
              D...........C
             .          . .
            .          .   .
           A...........E.....B
        A(x,y),B(x,y),BC = b,CD = c,DA = d given.AB = a is known.
        draw AD || CE. E divides AB in a ration c:(a-c),so use
        ratio co-ordinate to find E.
        AE = c,CE = d. So angle BEF = theta can be found by Cos Law.
        Now,OR = Rotate EB by theta.
        D = A + OR;
        C = E + OR;

    END :D :D
*/
#include <cmath>
#include <cstdio>
#define PI acos(-1.0)

using namespace std;

struct Vector{
    double x,y;
    Vector(double _x = 0,double _y = 0){x = _x;y = _y;}
    bool   operator==(Vector  a){ return (x == a.x) && (y == a.y); }
    Vector operator*(double a)  { return Vector(x*a,y*a); }
    Vector operator/(double a)  { return Vector(x/a,y/a); }
    Vector operator=(Vector a)  { x = a.x;y = a.y;return *this; }
    Vector operator+(Vector a)  { return Vector(x + a.x,y + a.y); }
    Vector operator-(Vector a)  { return Vector(x - a.x,y - a.y); }
    double length(){return sqrt(x*x + y*y);}
    double   dot(Vector a){ return x*a.x + y*a.y;}
    double cross(Vector a){ return x*a.y - y*a.x;}//return type,double in 2D its always a vector in z-axis
    Vector rotate(double radian){
        Vector a(cos(radian),sin(radian));
        return Vector(x*a.x - y*a.y,x*a.y + y*a.x);
    }
};

int main(){
    freopen("in.txt","r",stdin);
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        Vector A,B;
        double b,c,d,a;
        scanf("%lf%lf",&A.x,&A.y);
        scanf("%lf%lf",&B.x,&B.y);
        scanf("%lf%lf%lf",&b,&c,&d);

        a = (B-A).length();
        Vector E;
        E.x = (c*B.x + (a-c)*A.x)/a;
        E.y = (c*B.y + (a-c)*A.y)/a;

        double theta;
        theta = ((a-c)*(a-c) + d*d - b*b)/(2*(a-c)*d);
        theta = acos(theta);

        Vector OR = (B-E).rotate(theta);//rotate BE by theta
        OR = (OR/OR.length())*d;//make rotated unit and give it a length d
        Vector C = E + OR;
        Vector D = A + OR;

        printf("Case %d:\n",cn++);
        printf("%.10lf %.10lf ",C.x,C.y);
        printf("%.10lf %.10lf\n",D.x,D.y);
    }
    return 0;
}
