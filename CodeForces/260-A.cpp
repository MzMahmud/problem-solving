#include <iostream>

using namespace std;

int main() {
    int a,b,n;
    cin >> a >> b >> n;
    
    for(int i = 0;i < 10;i++){
        if( (10*a + i) % b == 0 ){
            cout << a << i;
            while(--n) cout << 0;
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}