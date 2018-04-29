#include <stdio.h>
#define min(x,y) (x < y? x:y)

double max_vol(double ,double );

int main()
{
     int tc,cn = 1;
     double l,w;

     scanf("%d",&tc);
     while( tc-- ){
          scanf("%lf%lf",&l,&w);
          printf("Case %d: %.10lf\n",cn++,max_vol(l,w));
     }
     return 0;
}

double max_vol(double l,double w)
{
     double hi,lo,x;
     int k = 300;
     lo = 0,hi = min(l,w)/2;
     x = (hi + lo)/2;
     while( k-- ){
          if( ( ( 4*(l+w)*x)-(12*x*x) - (l*w) ) > 0 )
                hi = x;
          else
                lo = x;
          x = (hi + lo)/2;
     }
     return ( (l - (2*x))*(w - (2*x))*x );
}

//this is done by Ternary Search
/*
#include <bits/stdc++.h>

using namespace std;

double L,W;

double f(double x){
    return ((L-2*x)*(W-2*x)*x);
}

double ternarySearch(double (*f)(double),double low,double high){
    int k = 200;
    double mid1,mid2;
    while(k--){
        mid1 = low  + (high-low)/3;
        mid2 = high - (high-low)/3;

        if( f(mid1) < f(mid2) )
            low = mid1;
        else if( f(mid1) == f(mid2) )
            low = mid1,high = mid2;
        else
            high = mid2;
    }
    return (mid1 + mid2)/2;
}

int main(){
    int T,cn = 1;
    scanf("%d", &T);
    while(T--){
        double x;
        scanf("%lf%lf",&L,&W);
        x = ternarySearch(f,0.0,min(L/2.0,W/2.0));
        printf("Case %d: %.10lf\n",cn++,f(x));
    }
    return 0;
}
*/