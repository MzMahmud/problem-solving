#include <bits/stdc++.h>

using namespace std;

int main(){
    string a;

    cin >> a;

    for(int i = 1;i < a.length();i++){
        if(a[i] >= 'a' && a[i] <= 'z'){
            cout << a << endl;
            return 0;
        }
    }

    if(a[0] >='a' && a[0] <= 'z'){
          a[0] = 'A' + a[0] - 'a';
    }else a[0] = 'a' + a[0] - 'A';
    for(int i = 1;i < a.length();i++){
        a[i] = 'a' + a[i] - 'A';
    }
    cout << a << endl;
    return 0;
}