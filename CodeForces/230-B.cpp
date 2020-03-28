#include <bits/stdc++.h>

using namespace std;

template <class T>
bool isPrime(T n){
    if(n < 2)  return false;
    if(n == 2) return true;
    if(!(n&1)) return false;

    for(T i = 3;i*i <= n;i+=2)
        if(!(n%i)) return false;

    return true;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        long long k;
        cin >> k;
        if( (long long)sqrt(k*1.0) != (double)sqrt(k*1.0) ){
            cout << "NO" << endl;
        }else{
            if(isPrime((long long)sqrt(k)))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}