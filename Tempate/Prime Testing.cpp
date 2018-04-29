#include <bits/stdc++.h>
#define SIZE 1000000

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
    cout << isPrime(103);
    return 0;
}
