#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k ;
    if(k >= 240){
        cout << 0 << endl;
        return 0;
    }
    for(int i = n;i >= 0;i--){
        int t = i*(i+1)*5;
        if(t <= 2*(240-k)){
            cout << i << endl;
            return 0;
        }
    }
    //return 0;
}