#include <bits/stdc++.h>

using namespace std;

double f(double x){
    //the function to be Maximized/Minimized
    return -3*x*x + 21.6*x + 5;
}

double ternarySearch(double (*f)(double),double low,double high){
    int k = 100;
    double mid1,mid2;
    while(k--){
        mid1 = low  + (high-low)/3;
        mid2 = high - (high-low)/3;

        if( f(mid1) < f(mid2) )
            //FOR MAXIMIZATION
            low = mid1;

            //FOR MINIMIZATION
            //high = mid2;
        else if( f(mid1) == f(mid2) )
            //FOR BOTH cases
            low = mid1,high = mid2;
        else//f(mid1) > f(mid2)
            //FOR MAXIMIZATION
            high = mid2;

            //FOR MINIMIZATION
            //low = mid1;
    }
    return (mid1 + mid2)/2;
}
int main(){
    int x = ternarySearch(f,0,10);
    cout << "Maxima in [0,10] is " << f(x) << " for x = " << x << endl;
    return 0;
}
