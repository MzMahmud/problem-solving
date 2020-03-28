#include <iostream>

using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(!(n % 2)) return false;

    for(int i = 3;i*i <= n;i++)
        if( !(n % i) ) return false;

    return true;
}

int main(){
    int n;
    cin >> n;
    for(int i = 2;;i++)
        if(!(isPrime(i) || isPrime(n-i))){
            cout << i << " " << n-i << endl;
            return 0;
        }
    return 0;
}