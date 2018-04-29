#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
    if(!b) return a;
    else   return gcd(b,a%b);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        ll g,l;
        cin >> g >> l;
        ll G,L;
        G = gcd(g,l);
        L = g*(l/G);
        if(G == g && L == l) cout << g << " " << l << endl;
        else                 cout << -1 << endl;
    }
    return 0;
}

