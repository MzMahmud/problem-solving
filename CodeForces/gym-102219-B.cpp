#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        int w,h;
        cin >> w >> h;
        printf("%s\n",w == h?"YES":"NO");
    }
    return 0;
}