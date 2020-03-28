#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef unsigned long long ull;

template <class T>

T bigMod(T a,T b,T M)

{

    if (!b) return (1 % M);

    int x = bigMod( a , b / 2 , M) ;

    x = ( (x%M) * (x%M) ) % M;

    if(b&1)//is same as b%2 == 1

        x = (x*a) % M;

    return x ;

}

//Returns a^b % M

int main(){

    ull x,k,ans = 0,a;
    
    cin>>x>>k;
    
    if(!x) {
    	cout << ans << endl;
    	return 0;
    }
    
    ans = bigMod((ull)2,k,(ull)MOD);
    a = (2*x - 1 + MOD) % MOD;
    ans = (a*ans + 1) % MOD;
    
    cout << ans << endl;

    return 0;

}