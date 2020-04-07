#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        long long n,k;
        cin >> n >> k;
        if((n + k) & 1){
            cout << "NO\n";
            continue;
        }
        n = (n + k) >> 1;
        k = k*(k + 1)/2;
        
        cout << (n >= k?"YES\n":"NO\n");
    }
    return 0;
}