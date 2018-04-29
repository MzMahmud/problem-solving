#include <bits/stdc++.h>

using namespace std;

int main(){
    int T,cn = 1;
    cin >> T;
    while(T--){
        int n,d,ans = 1;
        cin >> n >> d;
        int a = d;
        while(a%n){
            a = 10*a + d;
            if(a > n) a %= n;
            ans++;
        }
        printf("Case %d: %d\n",cn++,ans);
    }
    return 0;
}
