#include <bits/stdc++.h>

using namespace std;
/*template <class T>
void egcd(T a,T b,T &x,T &y){
    if(!b){
        x = 1;
        y = 0;
        return;
    }
    egcd(b,a%b,x,y);

    T temp = x;
    x = y;
    y = temp - (a/b)*y;
}*/

int egcd (int a, int b, int &x, int &y){
    if(!a){
        x = 0;y = 1;
        return b;
    }
    int x1,y1;
    int d = egcd(b%a,a,x1,y1);

    x = y1 - (b/a)*x1;
    y = x1;
    return d;
}

int main(){
    //13x + 3y = 1gcd(a,b)
    int a = 13,b = 3,x,y;
    egcd(a,b,x,y);
    cout << x << " " << y;
}
