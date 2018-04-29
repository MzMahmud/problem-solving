#include <bits/stdc++.h>
#define SIZE 1000000

using namespace std;

template <class T>
T bigMod(T a,T b,T M)
{
    if (!b)  return (1 % M);
    int x = bigMod( a , b / 2 , M) ;
    x = ( (x%M) * (x%M) ) % M;
    if(b&1)//is same as b%2 == 1
        x = (x*a) % M;
    return x ;
}
//Returns a^b % M

template <class T>
T gcd(T a,T b){
    if(!b) return a;
    return gcd(b,a%b);
}
//Euclid's Algorithm to find GCD

int main(){
    /*long long m = 1006795,n = 10,p = 106;
    cout << bigMod(m,p,n)<<endl;
    cout << gcd(m,n)<<endl;*/
    for(int i = 1;i < 100;i++){
        if(bigMod(13,i,2013) == 1)
            cout << i << endl;
    }
    return 0;
}
